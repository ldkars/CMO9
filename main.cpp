#include "mainwindow.h"

#include <QApplication>

#include <iostream>
#include "source.h"
#include "request.h"

int main(int argc, char *argv[])
{
    Source source;
    Request req = source.generationReqest();
    std::cout << req.getTimeGeneration() << std::endl;
    //QApplication a(argc, argv);
    //MainWindow w;
    //w.show();
    //return a.exec();
}
