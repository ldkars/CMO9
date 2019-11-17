#include "booc.h"
BOOC::BOOC(int count_source, int count_device)
{
    this->count_source = count_source;
    this->count_device = count_device;

    createSource(count_source);
    createDevice(count_device);
}

void BOOC::START(BufferController bufferController){
    //количество заявок N от каждого источника
   // for(int i = 0; i < 10; i++){
     //   for(int j = 0; i < vector_source.size(); i++){
       //     bufferController.insert(vector_source[j].generationReqest());
        //}
    //}
    bufferController.insert(vector_source[0].generationReqest());
    qDebug() << bufferController.getRequestOutBuffer().getTimeGeneration();
}

void BOOC::createSource(int count_source){
    for(int i = 0; i < count_source; i++){
        int numberOfSource = i;
        Source source(numberOfSource);
        vector_source.push_back(source);
    }
}

void BOOC::createDevice(int count_device){
    for(int i = 0; i < count_device; i++){
        Device device;
        vector_device.push_back(device);
    }
}



