#ifndef DEVICE_H
#define DEVICE_H
#include <vector>
#include "request.h"
class Device
{
public:
    Device(size_t number);
    size_t getNumber(){return number;}
    double getTime(){return time;}
    void insert(Request request);
private:
    size_t number;
    double time;
    double lam = 0.5;
};

#endif // DEVICE_H
