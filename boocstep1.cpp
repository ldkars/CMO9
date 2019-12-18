#include "boocstep1.h"

#define GetIndex(_index,_size) ( ( (_index%_size) + _size )%_size )

BoocStep::BoocStep(BufferController* &bufferController, DeviceController* &deviceController, SourceControlleer* &sourceController, double alpha, double beta, int count_source)
{
    this->linkBufferController = bufferController;
    this->linkDeviceController = deviceController;
    this->linkSourceController = sourceController;
    this->alpha = alpha;
    this->beta = beta;
    this->count_source = count_source;
    this->count_generation = 1;
}

void BoocStep::START(){
    test++;
    qDebug() << "awdawd " << test;
    /*for(int j = 0; j < this->count_generation; j++)
    {
        linkSourceController->PRINT_VECTOR_REQ();
        qDebug() << "---------";
        qDebug() << "Пришедшая заявка: " <<linkSourceController->getGhostRequest().getTimeGeneration();

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
    }
    percent_failure = linkBufferController->error / count_req;
    qDebug() << " Вероятность отказа заявки: "<< percent_failure;

    this->count_generation = ((1.643*1.643) * (1-percent_failure)) / (percent_failure*(0.1*0.1));
    qDebug() << " new count: "<< this->count_generation;*/
}



