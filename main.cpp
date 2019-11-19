#include "mainwindow.h"
#include <QApplication>
#include "source.h"
#include "request.h"
#include "buffercontroller.h"
#include "booc.h"
int main()
{
    size_t buffer_size = 9;

    BufferController bufferController(buffer_size);
    BOOC booc(bufferController);

    booc.START();



    //QApplication a(argc, argv);
    //MainWindow w;
    //w.show();
    //return a.exec();
}
