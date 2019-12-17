#include "stepmode.h"
#include "ui_stepmode.h"
#include "boocstep.h"
#include "sourcecontrolleer.h"
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

    SourceControlleer sourceController(this->count_source, this->alpha, this->beta);
    BufferController bufferController(buffer_size, sourceController);
    DeviceController deviceController(count_device, this->lambda);
    BoocStep boocStep(bufferController, deviceController, this->alpha, this->beta, this->count_source, this->count_request);

    boocStep.STEP();

    std::vector<Request> vec = bufferController.getBuffvec();
    QString time_generation;
    QString source;
    QString tmp;

}

//---------PRIVATE METHOD-----------
int StepMode::sizetToInt(size_t sizet){
    int tmp = 0;
    for(size_t i = 0; i < sizet; i++){tmp++;}
    qDebug() << sizet;
    return tmp;
}

void StepMode::initBuffGrid(){
    this->model_buff = new QStandardItemModel(sizetToInt(this->buffer_size), 5 , this);
    ui->tableView->setModel(model_buff);

    QModelIndex index_buff;
    for(int i = 0; i < sizetToInt(buffer_size); i++){
        index_buff = model_buff->index(i,0);
        model_buff->setData(index_buff, "Buffer " + QString::number(i) + ":");
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
}
