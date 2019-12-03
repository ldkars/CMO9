#ifndef BOOC_H
#define BOOC_H
#include "buffercontroller.h"
#include "devicecontroller.h"
#include <vector>
#include <QDebug>
#include "source.h"

class BOOC
{
public:
    BOOC(BufferController &bufferController, DeviceController &deviceController);
    void START();
private:
    BufferController *linkBufferController;
    DeviceController *linkDeviceController;
};

#endif // BOOC_H
