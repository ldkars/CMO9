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

void BOOC::modeling(){
    if(linkDeviceController->getStatusInsert(linkSourceController->getGhostRequest()))

    {
        if(linkDeviceController->getStatusInsert(linkBufferController->getCopyRequest())){
            linkDeviceController->insert(linkBufferController->getRequest());
            qDebug() << "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!";
        }else{
            linkDeviceController->insert(linkSourceController->getRequest());
        }

    }
    else
    {
        if(!linkBufferController->insert(linkSourceController->getRequest())){
            qDebug() << "кому то отказали";
            if(linkDeviceController->getStatusInsert(linkBufferController->getCopyRequest())){
                linkDeviceController->insert(linkBufferController->getRequest());
                qDebug() << "ЗАБРАЛИ ИЗ БУФЕРА 1 ИФ!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!";
            }

        }else
        {
            if(linkDeviceController->getStatusInsert(linkBufferController->getCopyRequest())){
                linkDeviceController->insert(linkBufferController->getRequest());
                qDebug() << "ЗАБРАЛИ ИЗ БУФЕРА 2 ИФ ЗАБРАЛИ ИЗ БУФЕРА 1 ИФ!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!";
            }
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
    vec_source.push_back(*linkSourceController);
}

void BOOC::START(){

    for(int j = 0; j < this->count_generation; j++)
    {
        modeling();
    }

    vec_final_req_buff = linkBufferController->getBuffvec(); //окончание моделирования. Фиксируем последние заявки

    percent_failure = linkBufferController->error / count_req;
    qDebug() << " Вероятность отказа заявки: "<< percent_failure;

    this->count_generation = ((1.643*1.643) * (1-percent_failure)) / (percent_failure*(0.1*0.1));
    qDebug() << " new count: "<< this->count_generation;
}



