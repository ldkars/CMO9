#include "booc.h"//
#define GetIndex(_index,_size) ( ( (_index%_size) + _size )%_size )

BOOC::BOOC(BufferController &bufferController, DeviceController &deviceController, SourceControlleer &sourceController, int count_generation)
{
    this->linkBufferController = &bufferController;
    this->linkDeviceController = &deviceController;
    this->linkSourceController = &sourceController;
    this->count_generation = count_generation;
}

void BOOC::modeling(){
    if(linkDeviceController->getStatusInsert(linkSourceController->getGhostRequest()))
    {
        if(linkDeviceController->getStatusInsert(linkBufferController->getCopyRequest()))
        {
            linkDeviceController->insert(linkBufferController->getRequest());
        }else
        {
            linkDeviceController->insert(linkSourceController->getRequest());
        }
    }
    else
    {
        Request request = linkSourceController->getRequest();
        request.insertBuffTime = request.getTimeGeneration();

        linkBufferController->insert(request);

        if(linkDeviceController->getStatusInsert(linkBufferController->getCopyRequest())){
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
    vec_source.push_back(*linkSourceController);
}

void BOOC::START(){

    for(int j = 0; j < this->count_generation; j++)
    {
        modeling();
    }

    vec_final_req_buff = linkBufferController->getBuffvec(); //окончание моделирования. Фиксируем последние заявки

    percent_failure = linkBufferController->error / count_req;
}



