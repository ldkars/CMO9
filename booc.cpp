#include "booc.h"
#define GetIndex(_index,_size) ( ( (_index%_size) + _size )%_size )

BOOC::BOOC(BufferController &bufferController, DeviceController &deviceController)
{
    this->linkBufferController = &bufferController;
    this->linkDeviceController = &deviceController;
}

void BOOC::START(){

    //ATTENCION! bufferController::getMinNumberOfSource всего 3 источник!

    Source source1(1);
    Source source2(2);
    Source source3(3);
    std::vector<Source> vector_source;
    vector_source.push_back(source1);
    vector_source.push_back(source2);
    vector_source.push_back(source3);

    int countGeneration = 100;
    for(int j = 0; j < countGeneration; j++){
        for(int i = 0; i < vector_source.size(); i++){
            linkBufferController->insert(vector_source[GetIndex(i, 3)].generationReqest());
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


}



