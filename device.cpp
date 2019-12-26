#include "device.h"
Device::Device(size_t number, double lambda)
{
    this->number = number;
    this->time = 0.0;
    this->lam = lambda;
}

void Device::insert(Request request){
    double delta_time = -1 / this->lam * log(rand0to1());
    this->time = request.getTimeGeneration() + delta_time;
    this->number_source = request.getNumberOfSource();
    this->counter++;
    T_SUMM += time;
    T_SERVICE += time - delta_time;
}

double Device::getT_SERVICE(){
    return T_SERVICE/counter;
}
