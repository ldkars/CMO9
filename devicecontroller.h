#ifndef DEVICECONTROLLER_H
#define DEVICECONTROLLER_H
#include <vector>
#include "device.h"
#include <QDebug>
#include "request.h"
#define GetIndex(_index,_size) ( ( (_index%_size) + _size )%_size )

class DeviceController
{
public:
    DeviceController(size_t count_device, double lambda);
    void TESTPRINTDEVICE();
    bool insert(Request request);
    bool getStatusInsert(Request request);
    size_t getCountDevice(){ return count_device;}
private:
    size_t count_device;
    std::vector<Device> vec_device;
    size_t pointer;
    int error;
    double lambda = 0;
};

#endif // DEVICECONTROLLER_H
