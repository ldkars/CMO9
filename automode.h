#ifndef AUTOMODE_H
#define AUTOMODE_H
#define COUNT_PARAMETRS 9

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

namespace Ui {
class AutoMode;
}

class AutoMode : public QDialog
{
    Q_OBJECT

public:
    explicit AutoMode(QWidget *parent = nullptr);
    ~AutoMode();

    void setBufferSize(size_t buffer_size){this->buffer_size = buffer_size;}
    void setCountDevice(size_t count_device){this->count_device = count_device;}
    void setCountSource(size_t count_source){this->count_source = count_source;}
    void setCountRequest(int count_request){this->count_request = count_request;}

    std::vector<BufferController> vec_buffer_controller;
    std::vector<DeviceController> vec_device_controller;
    std::vector<SourceControlleer> vec_source_controller;
    std::vector<Request> vec_final_req_buff;

private slots:
    void on_modelingButton_clicked();

private:
    Ui::AutoMode *ui;

    size_t buffer_size = 0;
    size_t count_device = 0;
    size_t count_source = 0;

    int count_request = 0;
    int buff_size = (int)(buffer_size);
    int sizetToInt(size_t sizet);
    int getCountReqSource(int number_source);

    double alpha = 0.0;
    double beta = 0.0;
    double lambda = 0.0;

    QStandardItemModel *model_source;
    QStandardItemModel *model_device;

    QModelIndex index_source;
    QModelIndex index_device;

    void initSourceGrid();
    void initDeviceGrid();

    void reqproc();
    void reqfail();
    void timeSystem();
    void timeWait();
    void timeProc();
    void dispTOF();
    void dispTOP();
    void probfail();

};

#endif // AUTOMODE_H
