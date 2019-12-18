#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "source.h"
#include "request.h"
#include "buffercontroller.h"
#include "booc.h"
#include "devicecontroller.h"
#include <QDebug>
#include "stepmode.h"
#include "sourcecontrolleer.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_StepModeButton_clicked();

private:
    Ui::MainWindow *ui;
    size_t buffer_size = 0;
    size_t count_device = 0;
    size_t count_source = 0;
    int count_request = 0;
    double alpha = 0.0;
    double beta = 0.0;
    double lambda = 0.0;
    std::vector<Request> vec_request;
    std::vector<BufferController> vec_buffer_controller;
    std::vector<DeviceController> vec_device_controller;
};
#endif // MAINWINDOW_H
