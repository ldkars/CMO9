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

    reqproc();
    reqfail();
    timeSystem();
    timeProc();
    probfail();
}

//PRIV
int AutoMode::sizetToInt(size_t sizet){
    int tmp = 0;
    for(size_t i = 0; i < sizet; i++){tmp++;}
    return tmp;
}

void AutoMode::initSourceGrid(){
    this->model_source = new QStandardItemModel(count_source, COUNT_PARAMETRS , this);
    ui->sourceView->setModel(model_source);

    for(int i = 0; i < sizetToInt(count_source); i++){
        index_source = model_source->index(i,0);
        model_source->setData(index_source, "Source " + QString::number(i) + ":");
    }

    std::vector<QString> vec_param_name = {"Source", "Req. proc.", "Req. fail", "Time in system",
                                           "Time of wait", "Time of process.","Disp. TOF", "Disp. TOP", "Prob. of fail"};
    for(int i = 0; i < COUNT_PARAMETRS; i++){
        model_source->setHeaderData(i, Qt::Horizontal, vec_param_name[i]);
    }
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

int AutoMode::getCountReqSource(int number_source){
    int tmp_final_req = 0;
    for(int j = 0; j < sizetToInt(vec_final_req_buff.size() - 1); j++){
        if(vec_final_req_buff[j].getNumberOfSource() == number_source){
            tmp_final_req++;
        }
    }
    return tmp_final_req;
}

void AutoMode::reqproc(){
    int tmp_count_req = 0;

    for(int i = 0; i < sizetToInt(count_source); i++){ //find final req on source
        tmp_count_req = vec_source_controller[vec_source_controller.size() - 1].getReqInSystems(i).size();
        model_source->setData(model_source->index(i, 1),
                              tmp_count_req + getCountReqSource(i));
    }
}

void AutoMode::reqfail(){
    for(int i = 0; i < sizetToInt(count_source); i++){
        model_source->setData(model_source->index(i, 2),
                              sizetToInt(vec_buffer_controller[vec_buffer_controller.size() - 1].getFailureRequest(i).size()));
    }
    //vec_buffer_controller[vec_buffer_controller.size() - 1].getFailureRequest(i).size()
}

void AutoMode::timeSystem(){
    std::vector<Request> merge_req = vec_device_controller[vec_device_controller.size() - 1].vec_device[0].completedReq;

    if(count_device > 0){
        for(int i = 1; i < sizetToInt(count_device); i++){
             merge_req.insert(merge_req.end(), vec_device_controller[vec_device_controller.size() - 1].vec_device[i].completedReq.begin(),
                     vec_device_controller[vec_device_controller.size() - 1].vec_device[i].completedReq.end());
        }
    }

    for(int i = 0; i < sizetToInt(count_source); i++)
    {
        std::vector<Request> tmp_req;

        for(int j = 0; j < sizetToInt(merge_req.size()); j++){
            if(merge_req[j].getNumberOfSource() == i){
                tmp_req.push_back(merge_req[j]);
            }
        }

        double time_in_system = 0.0;
        //P.S Не учитываю время тех заявок, что получили отказ, но тоже по факту находились в системе
        for(int j = 0; j < sizetToInt(tmp_req.size()); j++){
            time_in_system += tmp_req[j].releaseTime - tmp_req[j].getTimeGeneration();
        }

        int tmp_count_req = vec_source_controller[vec_source_controller.size() - 1].getReqInSystems(i).size();
        model_source->setData(model_source->index(i, 3), time_in_system / tmp_count_req);

    }
}

void AutoMode::timeWait(){

}

void AutoMode::timeProc(){
    /*std::vector<Request> merge_req = vec_device_controller[vec_device_controller.size() - 1].vec_device[0].completedReq;

    if(count_device > 0){
        for(int i = 1; i < sizetToInt(count_device); i++){
             merge_req.insert(merge_req.end(), vec_device_controller[vec_device_controller.size() - 1].vec_device[i].completedReq.begin(),
                     vec_device_controller[vec_device_controller.size() - 1].vec_device[i].completedReq.end());
        }
    }

    for(int i = 0; i < sizetToInt(count_source); i++)
    {
        std::vector<Request> tmp_req;

        for(int j = 0; j < sizetToInt(merge_req.size()); j++){
            if(merge_req[j].getNumberOfSource() == i){
                tmp_req.push_back(merge_req[j]);
            }
        }

        double release_time = 0.0;

        for(int j = 0; j < sizetToInt(tmp_req.size()); j++){
            release_time += tmp_req[j].releaseTime - tmp_req[j].insertDeviceTime;
        }

        int tmp_count_req = vec_source_controller[vec_source_controller.size() - 1].getReqInSystems(i).size();
        model_source->setData(model_source->index(i, 5), release_time / tmp_count_req);*/

   // }
}

void AutoMode::dispTOF(){

}

void AutoMode::dispTOP(){

}

void AutoMode::probfail(){
    double tmp_count_req = 0.0;

    for(int i = 0; i < sizetToInt(count_source); i++){ //find final req on source
        tmp_count_req = vec_source_controller[vec_source_controller.size() - 1].getReqInSystems(i).size() + getCountReqSource(i);
        model_source->setData(model_source->index(i, 8),
                              vec_buffer_controller[vec_buffer_controller.size() - 1].getFailureRequest(i).size() / tmp_count_req);
    }
}
