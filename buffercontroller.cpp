#include "buffercontroller.h"
#include <QDebug>
#define GetIndex(_index,_size) ( ( (_index%_size) + _size )%_size )

BufferController::BufferController(size_t buffer_size)
{
    this->buffer_size = buffer_size;
    this->pointer = 0;
    for(size_t i = 0; i < buffer_size; i++)
        vec.push_back(Request(0, 0, 0));
    error = 0;
}

void BufferController::insert(Request request){
    for(size_t i = 0; i < buffer_size * 2; i++){
        if( vec[GetIndex(i, buffer_size)].getTimeGeneration() == 0.0 ){
            vec[GetIndex(i, buffer_size)] = request;
            pointer = i;
            return;
        }
    }
    error++;
}

Request BufferController::getRequestOutBuffer(){
   return vec[4];
}
