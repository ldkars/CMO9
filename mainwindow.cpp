#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "source.h"
#include "request.h"
#include "buffercontroller.h"
#include "booc.h"
#include "devicecontroller.h"
#include <QDebug>

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
    BufferController bufferController(buffer_size);
    DeviceController deviceController(count_device, this->lambda);
    BOOC booc(bufferController, deviceController, this->alpha, this->beta, this->count_source, this->count_request);

    booc.START();
}
