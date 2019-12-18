#ifndef BOOC_H
#define BOOC_H
#include "buffercontroller.h"
#include "devicecontroller.h"
#include "sourcecontrolleer.h"
#include <vector>
#include <QDebug>
#include "source.h"
#include "logevent.h"

class BOOC
{
public:
    BOOC(BufferController &bufferController, DeviceController &deviceController,SourceControlleer &sourceController ,double alpha, double beta, int count_source, int count_generation);
    void START();
    double percent_failure = 0.0;
    std::vector<BufferController> vec_buff;
    std::vector<DeviceController> vec_device;
    std::vector<Request> vec_req;
    std::vector<LogEvent> vec_log_event;
private:
    BufferController *linkBufferController;
    DeviceController *linkDeviceController;
    SourceControlleer *linkSourceController;
    double alpha = 0.0;
    double beta = 0.0;
    int count_source = 0;
    int count_generation = 0;
    double count_req = 0;
};

#endif // BOOC_H
