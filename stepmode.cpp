#include "stepmode.h"
#include "ui_stepmode.h"


StepMode::StepMode(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::StepMode)
{
    ui->setupUi(this);
}


StepMode::~StepMode()
{
    delete ui;

}

void StepMode::on_pushButton_clicked()
{
    initBuffGrid();
    initSourceGrid();
    INDEX++;
    initDeviceGrid();
}

//---------PRIVATE METHOD-----------
void StepMode::initControllers(SourceControlleer &sourceController, BufferController &bufferController, DeviceController deviceController){

    linkSourceController = &sourceController;
    linkBufferController = &bufferController;
    linkDeviceController = &deviceController;
}


DeviceController StepMode::getDeviceController(){
    if(!b){
        vec_device_con.push_back(DeviceController(count_device, lambda));
        b = true;
    }
    return vec_device_con[0];
}

int StepMode::sizetToInt(size_t sizet){
    int tmp = 0;
    for(size_t i = 0; i < sizet; i++){tmp++;}
    return tmp;
}


void StepMode::initBuffGrid(){
    int buffer_size_tmp = sizetToInt(vec_buffer_controller[INDEX].getBufferSize());
    this->model_buff = new QStandardItemModel(buffer_size, 5 , this);
    ui->tableView->setModel(model_buff);

    QModelIndex index_buff;
    for(int i = 0; i < buffer_size_tmp; i++){
        index_buff = model_buff->index(i,0);
        model_buff->setData(index_buff, "Buffer " + QString::number(i) + ":");
    }

    for(int i = 0; i < sizetToInt(buffer_size); i++){
        model_buff->setData(model_buff->index(i,1), vec_buffer_controller[INDEX].vec[i].getTimeGeneration());
        model_buff->setData(model_buff->index(i,2), vec_buffer_controller[INDEX].vec[i].getNumberOfSource());
    }
}

void StepMode::initSourceGrid(){
    this->model_source = new QStandardItemModel(sizetToInt(this->count_source), 5 , this);
    ui->tableView_2->setModel(model_source);

    QModelIndex index_source;

    for(int i = 0; i < sizetToInt(count_source); i++){
        index_source = model_source->index(i,0);
        model_source->setData(index_source, "Source " + QString::number(i) + ":");
    }

    for(int i = 0; i < sizetToInt(count_source); i++){
        model_source->setData(model_source->index(i,1), vec_source_controller[INDEX].getVecRequest()[i].getTimeGeneration());
        model_source->setData(model_source->index(i,2), vec_source_controller[INDEX].getVecRequest()[i].getNumberOfSource());
    }
}

void StepMode::initDeviceGrid(){
    this->model_device = new QStandardItemModel(sizetToInt(vec_device_controller[INDEX].getCountDevice()), 5 , this);
    ui->tableView_3->setModel(model_device);

    QModelIndex index_device;

    for(int i = 0; i < sizetToInt(count_device); i++){
        index_device = model_device->index(i,0);
        model_device->setData(index_device, "Device " + QString::number(i) + ":");
    }

    for(int i = 0; i < sizetToInt(count_device); i++){
        model_device->setData(model_device->index(i,1), vec_device_controller[INDEX].vec_device[i].getTime());
        model_device->setData(model_device->index(i,2), vec_device_controller[INDEX].vec_device[i].getNumberOfSource());
    }

}

void StepMode::on_pushButton_2_clicked()
{
    if(0 < INDEX){
        INDEX--;
    }
    initBuffGrid();
    initSourceGrid();
    initDeviceGrid();
}

//--deviceCont
void StepMode::initDeviceController(){
    for(size_t i = 0; i < count_device; i++)
        vec_device.push_back(Device(i, this->lambda));
}

bool StepMode::insert(Request request){
    this->model_device = new QStandardItemModel(sizetToInt(this->count_device), 5 , this);
    ui->tableView_3->setModel(model_device);
    for(size_t i = pointer; i < count_device * 2; i++)
    {
        for(int i = 0; i < sizetToInt(count_device); i++){
            model_device->setData(model_device->index(i,1), vec_device[i].getTime() );
        }

        for(int i = 0; i < sizetToInt(count_device); i++){
            model_device->setData(model_device->index(i,2), vec_device[i].getNumberOfSource() );
        }

        for(int i = 0; i < sizetToInt(count_device); i++){
            model_device->setData(model_device->index(i,0), "Device " + QString::number(i) + ":");
        }


        if(request.getTimeGeneration() > vec_device[GetIndex(i, count_device)].getTime())
        {
            vec_device[GetIndex(i, count_device)].insert(request);
            pointer = GetIndex(i + 1, count_device);
            return true;
        }
    }
    return false;
}

bool StepMode::getStatusInsert(Request request){
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

void StepMode::TESTPRINTDEVICE(){
    for(size_t i = 0; i < count_device; i++)
        qDebug() << "time: " <<vec_device[i].getTime();
}
