#include "boocstep.h"
#define GetIndex(_index,_size) ( ( (_index%_size) + _size )%_size )

BoocStep::BoocStep(BufferController &bufferController, DeviceController &deviceController, double alpha, double beta, int count_source, int count_generation)
{
    this->linkBufferController = &bufferController;
    this->linkDeviceController = &deviceController;
    this->alpha = alpha;
    this->beta = beta;
    this->count_source = count_source;
    this->count_generation = count_generation;
}

void BoocStep::STEP(){
    std::vector<Source> vector_source;
    for(int i = 1; i <= count_source; i++){
        Source source(i, this->alpha, this->beta);
        vector_source.push_back(source);
    }

    for(int j = 0; j < this->count_generation; j++)
    {
        for(int i = 0; i < vector_source.size(); i++){
            linkBufferController->insert(vector_source[GetIndex(i, this->count_source)].generationReqest());
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



