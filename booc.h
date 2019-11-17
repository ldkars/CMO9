#ifndef BOOC_H
#define BOOC_H
#include "buffercontroller.h"
#include <vector>
#include <QDebug>

class BOOC
{
public:
    BOOC(BufferController &bufferController);
    void START();
private:
    BufferController *linkBufferController;
};

#endif // BOOC_H
