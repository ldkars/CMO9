#include "booc.h"

BOOC::BOOC(int count_source, int count_device, int count_buffer)
{
    this->count_source = count_source;
    this->count_device = count_device;
    this->count_buffer = count_buffer;

    createSource(count_source);
    createDevice(count_device);
    createBuffer(count_buffer);
}

void BOOC::START(){

}

void BOOC::createSource(int count_source){
    for(int i = 0; i < count_source; i++){
        Source source;
        vector_source.push_back(source);
    }
}
void BOOC::createDevice(int count_device){
    for(int i = 0; i < count_device; i++){
        Device device;
        vector_device.push_back(device);
    }
}
void BOOC::createBuffer(int count_buffer){
    for(int i = 0; i < count_buffer; i ++){
        Buffer buffer;
        vector_buffer.push_back(buffer);
    }
}



