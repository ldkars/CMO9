#include "automode.h"
#include "ui_automode.h"

AutoMode::AutoMode(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AutoMode)
{
    ui->setupUi(this);
}

AutoMode::~AutoMode()
{
    delete ui;
}
