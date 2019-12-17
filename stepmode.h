#ifndef STEPMODE_H
#define STEPMODE_H

#include <QDialog>
#include "source.h"
#include "request.h"
#include "buffercontroller.h"
#include "booc.h"
#include "devicecontroller.h"
#include <QString>
#include <QStandardItemModel>
#include <QDebug>
#include <string>

namespace Ui {
class StepMode;
}

class StepMode : public QDialog
{
    Q_OBJECT

public:
    explicit StepMode(QWidget *parent = nullptr);
    ~StepMode();
    void setBufferSize(size_t buffer_size){this->buffer_size = buffer_size;}
    void setCountDevice(size_t count_device){this->count_device = count_device;}
    void setCountSource(size_t count_source){this->count_source = count_source;}
    void setCountRequest(int count_request){this->count_request = count_request;}
    void setAlpha(double alpha){this->alpha = alpha;}
    void setBeta(double beta){this->beta = beta;}
    void setLambda(double lambda){this->lambda = lambda;}
private slots:
    void on_pushButton_clicked();
    void initBuffGrid();
    void initSourceGrid();
private:
    Ui::StepMode *ui;
    size_t buffer_size = 0;
    size_t count_device = 0;
    size_t count_source = 0;
    int count_request = 0;
    double alpha = 0.0;
    double beta = 0.0;
    double lambda = 0.0;
    int buff_size = (int)(buffer_size);

    QStandardItemModel *model_buff;
    QStandardItemModel *model_source;

    int sizetToInt(size_t sizet);
};

#endif // STEPMODE_H
