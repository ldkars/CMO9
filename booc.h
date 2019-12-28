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
    BOOC(BufferController &bufferController, DeviceController &deviceController,SourceControlleer &sourceController, int count_request);
    void START();
    std::vector<BufferController> vec_buff;
    std::vector<DeviceController> vec_device;
    std::vector<SourceControlleer> vec_source;
    std::vector<Request> vec_req;
    std::vector<Request> vec_final_req_buff;
private:
    BufferController *linkBufferController;
    DeviceController *linkDeviceController;
    SourceControlleer *linkSourceController;
    double count_req = 0;
    int count_request = 0;
    void modeling();
    void saveState();
};

#endif // BOOC_H
