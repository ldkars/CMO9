#ifndef BOOC_H
#define BOOC_H
#include "source.h"
#include "device.h"
#include "buffercontroller.h"
#include <vector>
#include <QDebug>

class BOOC
{
public:
    BOOC(int count_source, int count_device);
    void START(BufferController bufferController);
private:
    int count_source, count_device;

    std::vector<Source> vector_source;
    std::vector<Device> vector_device;

    void createSource(int count_source);
    void createDevice(int count_device);
};

#endif // BOOC_H
