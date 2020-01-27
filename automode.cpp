#include "automode.h"
#include "ui_automode.h"

AutoMode::AutoMode(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AutoMode)
{
    ui->setupUi(this);
}

AutoMode::~AutoMode()
{
    delete ui;
}

void AutoMode::on_modelingButton_clicked()
{
    initSourceGrid();
    initDeviceGrid();

    /*for(int i = 0; i < sizetToInt(count_source); i++){
        model_buff->setData(model_buff->index(i,1), vec_buffer_controller[INDEX].vec[i].getTimeGeneration());
        model_buff->setData(model_buff->index(i,2), vec_buffer_controller[INDEX].vec[i].getNumberOfSource());
    }*/
}

//PRIV
int AutoMode::sizetToInt(size_t sizet){
    int tmp = 0;
    for(size_t i = 0; i < sizet; i++){tmp++;}
    return tmp;
}

void AutoMode::initSourceGrid(){
    this->model_source = new QStandardItemModel(count_source, 8 , this);
    ui->sourceView->setModel(model_source);

    for(int i = 0; i < sizetToInt(count_source); i++){
        index_source = model_source->index(i,0);
        model_source->setData(index_source, "Source " + QString::number(i) + ":");
    }

    model_source->setHeaderData(0, Qt::Horizontal, tr("Req. proc."));
    model_source->setHeaderData(1, Qt::Horizontal, tr("Req. fail"));
    model_source->setHeaderData(2, Qt::Horizontal, tr("Time in system"));
    model_source->setHeaderData(3, Qt::Horizontal, tr("Time of wait"));
    model_source->setHeaderData(4, Qt::Horizontal, tr("Time of process."));
    model_source->setHeaderData(5, Qt::Horizontal, tr("Disp. TOF"));
    model_source->setHeaderData(6, Qt::Horizontal, tr("Disp. TOP"));
    model_source->setHeaderData(7, Qt::Horizontal, tr("Prob. of fail"));
}

void AutoMode::initDeviceGrid(){
    this->model_device = new QStandardItemModel(count_device, 2 , this);
    ui->deviceView->setModel(model_device);

    for(int i = 0; i < sizetToInt(count_device); i++){
        index_device = model_device->index(i,0);
        model_device->setData(index_device, "Device " + QString::number(i) + ":");
    }

    model_device->setHeaderData(0, Qt::Horizontal, tr("Device"));
    model_device->setHeaderData(1, Qt::Horizontal, tr("Coefficient"));
}
