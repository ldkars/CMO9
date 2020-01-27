#ifndef STEPMODE_H
#define STEPMODE_H

#include <QDialog>
#include "source.h"
#include "request.h"
#include "buffercontroller.h"
//#include "booc.h"
#include "devicecontroller.h"
#include <QString>
#include <QStandardItemModel>
#include <QDebug>
#include <string>
#include "sourcecontrolleer.h"
#include <vector>
#include "device.h"
#include "sizetoint.h"

namespace Ui {
class StepMode;
class SourceControlleer;
}

class StepMode : public QDialog
{
    Q_OBJECT

public:
    explicit StepMode(QWidget *parent = nullptr);
    ~StepMode();
    void setBufferSize(size_t buffer_size){this->buffer_size = buffer_size;}
    void setCountDevice(size_t count_device){this->count_device = count_device;}
    void setCountSource(size_t count_source){this->count_source = count_source;}
    void setCountRequest(int count_request){this->count_request = count_request;}
    void setAlpha(double alpha){this->alpha = alpha;}
    void setBeta(double beta){this->beta = beta;}
    void setLambda(double lambda){this->lambda = lambda;}
    void initControllers(SourceControlleer &sourceController, BufferController &bufferController, DeviceController deviceController);

    //--pub

    void TESTPRINTDEVICE();
    bool insert(Request request);
    bool getStatusInsert(Request request);
    size_t getCountDevice(){ return count_device;}

    //---new
    std::vector<Request> vec_request;
    std::vector<BufferController> vec_buffer_controller;
    std::vector<DeviceController> vec_device_controller;
    std::vector<SourceControlleer> vec_source_controller;

private slots:
    void on_pushButton_clicked();
    void initBuffGrid();
    void initSourceGrid();
    void initDeviceGrid();
    void on_pushButton_2_clicked();

private:
    Ui::StepMode *ui;
    size_t buffer_size = 0;
    size_t count_device = 0;
    size_t count_source = 0;
    int count_request = 0;
    double alpha = 0.0;
    double beta = 0.0;
    double lambda = 0.0;
    int buff_size = (int)(buffer_size);
    bool b = false;

    int INDEX = 0;

    SourceControlleer *linkSourceController;
    BufferController *linkBufferController;
    DeviceController *linkDeviceController;

    QStandardItemModel *model_buff;
    QStandardItemModel *model_source;
    QStandardItemModel *model_device;

    DeviceController getDeviceController();
    std::vector<DeviceController> vec_device_con;

    //--priv
    int sizetToInt(size_t sizet);
    std::vector<Device> vec_device;
    size_t pointer = 0;
    int error;

    void initDeviceController();

    std::vector<double> vec_time_device;

};

#endif // STEPMODE_H
