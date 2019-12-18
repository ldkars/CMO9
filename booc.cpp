#include "booc.h"
#define GetIndex(_index,_size) ( ( (_index%_size) + _size )%_size )

BOOC::BOOC(BufferController &bufferController, DeviceController &deviceController, SourceControlleer &sourceController, double alpha, double beta, int count_source, int count_generation)
{
    this->linkBufferController = &bufferController;
    this->linkDeviceController = &deviceController;
    this->linkSourceController = &sourceController;
    this->alpha = alpha;
    this->beta = beta;
    this->count_source = count_source;
    this->count_generation = count_generation;
}

void BOOC::START(){

    for(int j = 0; j < this->count_generation; j++)
    {
        linkSourceController->PRINT_VECTOR_REQ();
        qDebug() << "---------";
        qDebug() << "Пришедшая заявка: " <<linkSourceController->getGhostRequest().getTimeGeneration();
        vec_log_event.push_back(LogEvent().setnew_req("Пришла заявка от " + QString::number(12)));
        vec_req.push_back(linkSourceController->getGhostRequest());

        if (linkDeviceController->getStatusInsert(linkSourceController->getGhostRequest())){
            linkDeviceController->insert(linkSourceController->getRequest());
            count_req++;
        }else
        {
            if(!linkBufferController->insert(linkSourceController->getRequest())){
                linkSourceController->generationRequest(linkBufferController->tmp_count_source);
            }

            count_req++;
            if(linkDeviceController->getStatusInsert(linkBufferController->getCopyRequest())){
                linkDeviceController->insert(linkBufferController->getRequest());
            }
        }

        qDebug() << "------------------------";

        linkBufferController->buffPrint();
        for(int i = 0; i < linkBufferController->getBufferCountSize(); i++){
            Request copyRequest = linkBufferController->getCopyRequest();
            if(linkDeviceController->getStatusInsert(copyRequest)){
                linkDeviceController->insert(linkBufferController->getRequest());
            }
        }

        qDebug() << "----------------------------------------------";
        qDebug() << "         DEVICES";
        linkDeviceController->TESTPRINTDEVICE();
        qDebug() << "Количество отказов: " << linkBufferController->error;
        qDebug() <<"      STATUS BUFFER                 ";
        linkBufferController->buffPrint();
        vec_buff.push_back(*linkBufferController);
        vec_device.push_back(*linkDeviceController);
    }

    percent_failure = linkBufferController->error / count_req;
    qDebug() << " Вероятность отказа заявки: "<< percent_failure;

    this->count_generation = ((1.643*1.643) * (1-percent_failure)) / (percent_failure*(0.1*0.1));
    qDebug() << " new count: "<< this->count_generation;
}



