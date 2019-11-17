#include "buffercontroller.h"
#include <QDebug>
BufferController::BufferController(size_t buffer_size)
{
    this->buffer_size = buffer_size;
}

void BufferController::insert(Request request){
}

Request BufferController::getRequestOutBuffer(){
   return Request(0,0,0);
}
