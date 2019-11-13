#include "mainwindow.h"
#include <QApplication>
#include "source.h"
#include "request.h"
#include "buffercontroller.h"
#include "booc.h"

int main()
{
    int count_source = 3; // входные параметры
    int count_device = 2;
    int count_buffer = 3;

    BOOC booc(count_source, count_device);
    BufferController bufferController(count_buffer);
    booc.START(bufferController);
    //QApplication a(argc, argv);
    //MainWindow w;
    //w.show();
    //return a.exec();
}
