#ifndef BOOC_H
#define BOOC_H
#include "source.h"
#include "device.h"
#include "buffer.h"
#include <vector>

class BOOC
{
public:
    BOOC(int count_source, int count_device, int count_buffer);
    void START();
private:
    int count_source, count_device, count_buffer;

    std::vector<Source> vector_source;
    std::vector<Device> vector_device;
    std::vector<Buffer> vector_buffer;

    void createSource(int count_source);
    void createDevice(int count_device);
    void createBuffer(int count_buffer);
};

#endif // BOOC_H
