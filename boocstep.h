#ifndef BOOCSTEP_H
#define BOOCSTEP_H

#include "buffercontroller.h"
#include "devicecontroller.h"
#include <vector>
#include <QDebug>
#include "source.h"

class BoocStep
{
public:
    BoocStep(BufferController &bufferController, DeviceController &deviceController, double alpha, double beta, int count_source, int count_generation);
    void STEP();
private:
    BufferController *linkBufferController;
    DeviceController *linkDeviceController;
    double alpha = 0.0;
    double beta = 0.0;
    int count_source = 0;
    int count_generation = 0;
};

#endif // BOOCSTEP_H
