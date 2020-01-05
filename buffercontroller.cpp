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
    vec_priority.clear();
    vec_priority = getPreorityRequest(); //preority numberSource
    Request resault_request = findMinTimeReqest(vec_priority);

    deleteRequest(resault_request);

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

std::vector<Request> BufferController::getPreorityRequest(){
    std::vector<Request> vec_priority;
    for(size_t i = 0; i < buffer_size; i++){
        if(vec[i].getNumberOfSource() == getMinNumberSource())
            vec_priority.push_back(vec[i]);
    }
    return vec_priority;
}

Request BufferController::findMinTimeReqest(std::vector<Request> &vec_request){
    double min_time = vec_request[0].getTimeGeneration();
    size_t index = 0;
    for(size_t i = 0; i < vec_request.size(); i++){
        if(vec_request[i].getTimeGeneration() < min_time){
            min_time = vec_request[i].getTimeGeneration();
            index = i;
        }
    }
}

void BufferController::deleteRequest(Request request){
    for(size_t i = 0; i < buffer_size; i++){
        if(requestEqualRequest(request, vec[i]))
        {
            vec[i] = getEmptyRequest();
        }
    }
}

void BufferController::initVectorEmpty(){
    for(size_t i = 0; i < buffer_size; i++){
        vec.push_back(generationEmptyRequest());
    }
}

//TESTFUNC
void BufferController::buffPrint(){
    for(size_t i = 0; i < buffer_size; i++)
        qDebug() << "TimeGen: " << vec[i].getTimeGeneration() << " Source: " <<vec[i].getNumberOfSource();
}


