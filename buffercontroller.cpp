#include "buffercontroller.h"
#include <QDebug>
BufferController::BufferController(int count_buffer)
{
    this->count_buffer = count_buffer;
    for(int i = 0; i < count_buffer; i++){
        int size_buffer = 5;
        Buffer buffer(size_buffer);
        vector_buffer.push_back(buffer);
    }
}

void BufferController::insert(Request request){
    for(int i = 0; i < count_buffer; i++){
        if(vector_buffer[i].checkFree(request)){
            qDebug() << request.getTimeGeneration();
            return;
        }
    }
    qDebug() << "Не вставили";
}
