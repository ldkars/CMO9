#include "device.h"
#include "random.h"
Device::Device(size_t number)
{
    this->number = number;
    this->time = 0.0;
}

void Device::insert(Request request){
    double delta_time = -1 / this->lam * log(rand0to1());
    this->time = request.getTimeGeneration() + delta_time;
}
