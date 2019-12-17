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
    SourceControlleer sourceController(this->count_source, this->alpha, this->beta);
    BufferController bufferController(buffer_size, sourceController);
    DeviceController deviceController(count_device, this->lambda);
    BOOC booc(bufferController, deviceController, sourceController,this->alpha, this->beta, this->count_source, this->count_request);

    booc.START();
}

void MainWindow::on_StepModeButton_clicked()
{
    StepMode window;
    window.setBeta(this->beta);
    window.setAlpha(this->alpha);
    window.setLambda(this->lambda);
    window.setBufferSize(this->buffer_size);
    window.setCountDevice(this->count_device);
    window.setCountSource(this->count_source);
    window.setCountRequest(this->count_request);
    window.setModal(true);
    window.exec();

}
