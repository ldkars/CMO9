#include "mainwindow.h"
#include <QApplication>
#include "source.h"
#include "request.h"
#include "buffercontroller.h"
#include "booc.h"
#include "devicecontroller.h"
int main()
{
    size_t buffer_size = 9;
    size_t count_device = 2;

    BufferController bufferController(buffer_size);
    DeviceController deviceController(count_device);
    BOOC booc(bufferController, deviceController);

    booc.START();



    //QApplication a(argc, argv);
    //MainWindow w;
    //w.show();
    //return a.exec();
}
