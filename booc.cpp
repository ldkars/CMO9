#include "booc.h"
BOOC::BOOC(BufferController &bufferController)
{
    this->linkBufferController = &bufferController;
}

void BOOC::START(){
    linkBufferController->insert(Request(228, 1, 1));
    linkBufferController->insert(Request(229, 2, 2));
    linkBufferController->insert(Request(230, 3, 2));
    linkBufferController->insert(Request(231, 4, 1));
    linkBufferController->insert(Request(232, 5, 3));

    qDebug() << linkBufferController->getRequestOutBuffer().getTimeGeneration();
}



