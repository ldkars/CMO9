#include "mainwindow.h"
#include <QApplication>
#include "source.h"
#include "request.h"
#include "buffercontroller.h"
#include "booc.h"
#include "devicecontroller.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}
