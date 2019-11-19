#include "booc.h"
#define GetIndex(_index,_size) ( ( (_index%_size) + _size )%_size)
BOOC::BOOC(BufferController &bufferController)
{
    this->linkBufferController = &bufferController;
}

void BOOC::START(){

    //ATTENCION! bufferController::getMinNumberOfSource всего 3 источник!
    linkBufferController->insert(Request(228, 1, 2));
    linkBufferController->insert(Request(229, 1, 1));
    linkBufferController->insert(Request(230, 1, 3));
    Request req(0,0,0);
    req = linkBufferController->getRequest();
    qDebug() << req.getTimeGeneration();

}



