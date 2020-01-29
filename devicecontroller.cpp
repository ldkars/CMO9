#include "devicecontroller.h"

DeviceController::DeviceController(size_t count_device, double lambda)
{
    this->count_device = count_device;
    this->pointer = 0;
    this->lambda = lambda;

    for(size_t i = 0; i < count_device; i++)
        vec_device.push_back(Device(i, this->lambda));
}

bool DeviceController::insert(Request request){
    for(size_t i = pointer; i < count_device * 2; i++)
    {
        if(request.getTimeGeneration() > vec_device[GetIndex(i, count_device)].getTime())
        {
            request.insertDeviceTime = request.getTimeGeneration();

            vec_device[GetIndex(i, count_device)].insert(request);
            pointer = GetIndex(i + 1, count_device);

            return true;
        }
    }
    return false;
}

bool DeviceController::getStatusInsert(Request request){
    size_t copy_pointer = pointer;
    std::vector<Device> copy_vec_device = vec_device;
    for(size_t i = copy_pointer; i < count_device * 2; i++)
    {
        if(request.getTimeGeneration() > copy_vec_device[GetIndex(i, count_device)].getTime())
        {
            copy_vec_device[GetIndex(i, count_device)].insert(request);
            copy_pointer = GetIndex(i + 1, count_device);
            return true;
        }
    }
    return false;
}


/*TESTING*/

void DeviceController::TESTPRINTDEVICE(){
    for(size_t i = 0; i < count_device; i++)
        qDebug() << "time: " <<vec_device[i].getTime();
}

void DeviceController::checkDevice(){

}
