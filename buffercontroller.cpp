#include "buffercontroller.h"
#include <QDebug>

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

    failureRequest.push_back(vec[pointer]);
    occupiedReq.push_back(request);

    vec[pointer] = request;
    pointer = GetIndex(pointer + 1, buffer_size);
    return false;
}

Request BufferController::getRequest(){
    std::vector<Request> vec_priority;
    vec_priority = getPreorityRequest(); //preority numberSource
    Request resault_request = findMinTimeReqest(vec_priority);

    deleteRequest(resault_request);

    linkSourceController->generationRequest(resault_request.getNumberOfSource());

    return resault_request;
}

Request BufferController::getCopyRequest(){
    std::vector<Request> vec_priority2;//это c++ детка, и тут это называется костыль
    vec_priority2 = getPreorityRequest(); //preority numberSource
    Request resault_request = findMinTimeReqest(vec_priority2);
    return resault_request;
}

int BufferController::getMinNumberSource(){
    size_t min_number_source = 10000;
    size_t tmp = 0;

    for(size_t i = 0; i < vec.size(); i++){
        if(vec[i].getNumberOfSource() > tmp){
            tmp = vec[i].getNumberOfSource();
        }
    }
    min_number_source = tmp;

    for(size_t i = 0; i < buffer_size; i++){
        if(vec[i].getNumberOfSource() < min_number_source){
            min_number_source = vec[i].getNumberOfSource();
        }
    }
    return min_number_source;
}

bool BufferController::requestEmpty(Request request){
    if(request.getTimeGeneration() == 0.0
                    && request.getCounter() == 0
                      && request.getNumberOfSource() == 200){
        return true;
    }
    else{
        return false;
    }
}

bool BufferController::requestEqualRequest(Request request1, Request request2){
    if(request1.getTimeGeneration() == request2.getTimeGeneration()
            && request1.getCounter() == request2.getCounter()
                && request1.getNumberOfSource() == request2.getNumberOfSource()){
        return true;
    }
    else{
        return false;
    }
}

Request BufferController::getEmptyRequest(){
    return Request(0,0,200);
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
    return vec_request[index];
}

void BufferController::deleteRequest(Request request){
    for(size_t i = 0; i < buffer_size; i++){
        if(requestEqualRequest(request, vec[i])){
            vec[i] = getEmptyRequest();
        }
    }
}

void BufferController::initVectorEmpty(){
    for(size_t i = 0; i < buffer_size; i++){
        vec.push_back(getEmptyRequest());
    }
}

std::vector<Request> BufferController::getFailureRequest(int number_source){
    std::vector<Request> failureRequestSource;
    for(size_t i = 0; i < failureRequest.size(); i++){
        if(failureRequest[i].getNumberOfSource() == number_source){
            failureRequestSource.push_back(failureRequest[i]);
        }
    }
    return failureRequestSource;
}

//TESTFUNC
void BufferController::buffPrint(){
    for(size_t i = 0; i < buffer_size; i++){
        qDebug() << "TimeGen: " << vec[i].getTimeGeneration() << " Source: " <<vec[i].getNumberOfSource();
    }
}


