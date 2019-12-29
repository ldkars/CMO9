#include "buffercontroller.h"
#include <QDebug>
#define GetIndex(_index,_size) ( ( (_index%_size) + _size )%_size )

BufferController::BufferController(size_t buffer_size, SourceControlleer &sourceController)
{
    this->buffer_size = buffer_size;
    this->linkSourceController = &sourceController;
    initVectorEmpty();
}

bool BufferController::insert(Request request){
    for(size_t i = pointer; i < buffer_size * 2; i++){
        if(requestEmpty(vec[GetIndex(i, buffer_size)]))
        {
            vec[GetIndex(i, buffer_size)] = request;
            pointer = GetIndex(i + 1, buffer_size);
            return true;
        }
    }
    error++;
    vec[pointer] = request;
    pointer = GetIndex(pointer + 1, buffer_size);
    return false;
}

Request BufferController::getRequest(){
    std::vector<Request> vec_priority; //содержит самые "свежие" заявки

    // поиск по приоритету источника
    for(size_t i = 0; i < buffer_size; i++){
        if(vec[i].getNumberOfSource() == getMinNumberSource())
            vec_priority.push_back(vec[i]);
    }

    double min_time = vec_priority[0].getTimeGeneration();
    size_t index = 0; // поиск индекса минимального по времени
    for(size_t i = 0; i < vec_priority.size(); i++){
        if(vec_priority[i].getTimeGeneration() < min_time){
            min_time = vec_priority[i].getTimeGeneration();
            index = i;
        }
    }

    for(size_t i = 0; i < buffer_size; i++)
        if(requestEqualRequest(vec_priority[index], vec[i]))
            vec[i] = getEmptyRequest();

    Request resault_request = vec_priority[index];
    vec_priority[index] = getEmptyRequest(); // bug //1decembber: what this bug?
    linkSourceController->generationRequest(resault_request.getNumberOfSource());
    return resault_request;
}

Request BufferController::getCopyRequest(){
    std::vector<Request> vec_priority; //содержит самые "свежие" заявки

    // поиск по приоритету источника
    for(size_t i = 0; i < buffer_size; i++){
        if(vec[i].getNumberOfSource() == getMinNumberSource())
            vec_priority.push_back(vec[i]);
    }

    double min_time = vec_priority[0].getTimeGeneration();
    size_t index = 0; // поиск индекса минимального по времени
    for(size_t i = 0; i < vec_priority.size(); i++){
        if(vec_priority[i].getTimeGeneration() < min_time){
            min_time = vec_priority[i].getTimeGeneration();
            index = i;
        }
    }

    Request resault_request = vec_priority[index];
    vec_priority[index] = getEmptyRequest(); // bug //1decembber: what this bug?
    return resault_request;
}

int BufferController::getMinNumberSource(){
    size_t min_number_source = 3; // to-do
    size_t tmp = 0; // ужас

    for(size_t i = 0; i < vec.size(); i++){
        if(vec[i].getNumberOfSource() > tmp){
            tmp = vec[i].getNumberOfSource();
        }
    }
    min_number_source = tmp;

    for(size_t i = 0; i < buffer_size; i++){
        if(vec[i].getNumberOfSource() < min_number_source)
            min_number_source = vec[i].getNumberOfSource();
    }
    return min_number_source;
}

bool BufferController::requestEmpty(Request request){
    if(request.getTimeGeneration() == 0.0
                    && request.getCounter() == 0
                      && request.getNumberOfSource() == 200)
        return true;
    else false;
}

bool BufferController::requestEqualRequest(Request request1, Request request2){
    if(request1.getTimeGeneration() == request2.getTimeGeneration()
            && request1.getCounter() == request2.getCounter()
                && request1.getNumberOfSource() == request2.getNumberOfSource())
    {
        return true;
    }
    else return false;
}


Request BufferController::generationEmptyRequest(){
    return Request(0,0,200);
}

Request BufferController::getEmptyRequest(){
    return Request(0,0,200);
}

int BufferController::getBufferCountSize(){
    int buffersize = 0;
    for(size_t i = 0; i < buffer_size; i++){
        if(vec[i].getCounter() == getEmptyRequest().getCounter()
                && vec[i].getNumberOfSource() == getEmptyRequest().getNumberOfSource()
                  && vec[i].getTimeGeneration() == getEmptyRequest().getTimeGeneration()){
        }else{
            buffersize++;
        }
    }
    return buffersize;
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
        qDebug() << "TimeGen: " << vec[i].getTimeGeneration() << " Source: " <<vec[i].getNumberOfSource();
}

void BufferController::initVectorEmpty(){
    for(size_t i = 0; i < buffer_size; i++){
        vec.push_back(generationEmptyRequest());
    }
}
