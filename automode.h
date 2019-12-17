#ifndef AUTOMODE_H
#define AUTOMODE_H

#include <QDialog>

namespace Ui {
class AutoMode;
}

class AutoMode : public QDialog
{
    Q_OBJECT

public:
    explicit AutoMode(QWidget *parent = nullptr);
    ~AutoMode();

private:
    Ui::AutoMode *ui;
};

#endif // AUTOMODE_H
