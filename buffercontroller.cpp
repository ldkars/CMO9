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
    for(size_t i = pointer; i < buffer_size * 2; i++){
        if( vec[GetIndex(i, buffer_size)].getTimeGeneration() == 0.0 )
        {
            vec[GetIndex(i, buffer_size)] = request;
            pointer = GetIndex(i, buffer_size);
            return;
        }
    }
    error++;
}

Request BufferController::getRequest(){
    std::vector<Request> vec_priority; //содержит самые "свежие" заявки
    int min_source = getMinNumberSource();

    for(size_t i = 0; i < buffer_size; i++){
        if(vec[i].getNumberOfSource() == min_source)
            vec_priority.push_back(vec[i]);
    }

    double min_time = vec_priority[0].getTimeGeneration();
    size_t index = 0;
    for(size_t i = 0; i < vec_priority.size(); i++){
        if(vec_priority[i].getTimeGeneration() < min_time){
            min_time = vec_priority[i].getTimeGeneration();
            index = i;
        }
    }
    return vec_priority[index];
}

int BufferController::getMinNumberSource(){ //
    size_t min_number_source = 3; //
    for(size_t i = 0; i < buffer_size; i++){
        if(vec[i].getNumberOfSource() < 3)
            min_number_source = vec[i].getNumberOfSource();
    }
    return min_number_source;
}












//TESTFUNC

void BufferController::BUFFTEST(){

    for(size_t i = 0; i < buffer_size; i++)
        insert(Request(228, i, 1));

    buffDelete(0);
    buffPrint();

    insert(Request(1, 1, 1)); // контрольный пакет, смотреть совпадения

    buffPrint();
    // надеюсь я найду время, чтобы написать хороший boost тест
    //PS. проверил вставка кореектна, на концах в том числею
}

void BufferController::buffDelete(size_t index){
    vec[index] = Request(0,0,0);
}

void BufferController::buffPrint(){
    for(size_t i = 0; i < buffer_size; i++)
        qDebug() << "buff print: " << vec[i].getTimeGeneration();
}
