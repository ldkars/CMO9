#include "booc.h"
#define GetIndex(_index,_size) ( ( (_index%_size) + _size )%_size )

BOOC::BOOC(BufferController &bufferController, DeviceController &deviceController, SourceControlleer &sourceController, int count_request)
{
    this->linkBufferController = &bufferController;
    this->linkDeviceController = &deviceController;
    this->linkSourceController = &sourceController;
    this->count_request = count_request;
}

void BOOC::modeling(){
    if(linkDeviceController->getStatusInsert(linkSourceController->getGhostRequest())){
        if(linkDeviceController->getStatusInsert(linkBufferController->getCopyRequest())){
            linkDeviceController->insert(linkBufferController->getRequest());
        }else{
            linkDeviceController->insert(linkSourceController->getRequest());
        }
    }
    else{
        if(!linkBufferController->insert(linkSourceController->getRequest())){
            if(linkDeviceController->getStatusInsert(linkBufferController->getCopyRequest()))
            {
                linkDeviceController->insert(linkBufferController->getRequest());
            }

        }else{
            if(linkDeviceController->getStatusInsert(linkBufferController->getCopyRequest()))
            {
                linkDeviceController->insert(linkBufferController->getRequest());
            }
        }
    }


    qDebug() << "----------------------------------------------";
    qDebug() << "         DEVICES";
    linkDeviceController->TESTPRINTDEVICE();
    qDebug() << "Количество отказов: " << linkBufferController->error;
    qDebug() <<"      STATUS BUFFER                 ";
    linkBufferController->buffPrint();
}

void BOOC::saveState(){
    vec_buff.push_back(*linkBufferController);
    vec_device.push_back(*linkDeviceController);
    vec_source.push_back(*linkSourceController);
}

void BOOC::START(){
    for(int j = 0; j < this->count_request; j++)
    {
        modeling();
    }
}



