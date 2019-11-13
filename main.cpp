#include "mainwindow.h"

#include <QApplication>

#include <iostream>
#include "source.h"
#include "request.h"

int main()
{
    int count_source = 3; // входные параметры
    int count_device = 2;
    int count_buffer = 3;

    Source source;
    Request req = source.generationReqest(); // может не стоит возвращать заявку
    std::cout << req.getTimeGeneration() << std::endl;
    //QApplication a(argc, argv);
    //MainWindow w;
    //w.show();
    //return a.exec();
}
