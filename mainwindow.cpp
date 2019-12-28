#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    this->count_source = ui->countSource->value();
    this->buffer_size = ui->countBuffer->value();
    this->count_device = ui->countDevice->value();
    this->count_request = ui->countRequest->value();
    this->alpha = ui->Alpha->value();
    this->beta = ui->Beta->value();
    this->lambda = ui->Lambda->value();
}

void MainWindow::on_pushButton_2_clicked()
{
    this->modeling = true;
    SourceControlleer sourceController(this->count_source, this->alpha, this->beta);
    BufferController bufferController(buffer_size, sourceController);
    DeviceController deviceController(count_device, this->lambda);
    BOOC booc(bufferController, deviceController, sourceController,this->alpha, this->beta, this->count_source, this->count_request);

    booc.START();

    vec_buffer_controller = booc.vec_buff;
    vec_device_controller = booc.vec_device;
    vec_source_controller = booc.vec_source;
    vec_request = booc.vec_req;
}

void MainWindow::on_StepModeButton_clicked()
{
    if(modeling){
        StepMode window;
        window.setBeta(this->beta);
        window.setAlpha(this->alpha);
        window.setLambda(this->lambda);
        window.setBufferSize(this->buffer_size);
        window.setCountDevice(this->count_device);
        window.setCountSource(this->count_source);
        window.setCountRequest(this->count_request);
        window.setModal(true);
        SourceControlleer sourceController(this->count_source, this->alpha, this->beta);
        BufferController bufferController(buffer_size, sourceController);
        DeviceController deviceController(count_device, this->lambda);
        window.initControllers(sourceController, bufferController, deviceController);

        window.vec_request = vec_request;
        window.vec_buffer_controller = vec_buffer_controller;
        window.vec_device_controller = vec_device_controller;
        window.vec_source_controller = vec_source_controller;

        window.exec();
    }
    else{
        QMessageBox::information(0, "Hey", "You most set config and press modeling!");
    }


}

void MainWindow::on_pushButton_3_clicked()
{
    if(modeling){

    }
    else{
        QMessageBox::information(0, "Hey", "You most set config and press modeling!");
    }
}
