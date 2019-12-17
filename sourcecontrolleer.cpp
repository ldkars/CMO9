#include "sourcecontrolleer.h"

SourceControlleer::SourceControlleer(size_t count_source, double alpha, double beta)
{
    this->count_source = count_source;
    this->alpha = alpha;
    this->beta = beta;
    init_source();
}


//------PUBLIC METHOD---------

Request SourceControlleer::getRequest(){
    double index = 0;
    double min = vector_request[0].getTimeGeneration();

    for(size_t i = 0; i < vector_request.size(); i++){
        if(vector_request[i].getTimeGeneration() < min){
            min = vector_request[i].getTimeGeneration();
            index = i;
        }
    }

    Request tmp_request = vector_request[index];

    vector_request.erase(vector_request.begin() + index);
    generationRequest(tmp_request.getNumberOfSource());
    qDebug() << "сгенерировали от источника " << tmp_request.getNumberOfSource();
    return tmp_request;
}

Request SourceControlleer::getGhostRequest(){
    double index = 0;
    double min = vector_request[0].getTimeGeneration();

    for(size_t i = 0; i < vector_request.size(); i++){
        if(vector_request[i].getTimeGeneration() < min){
            min = vector_request[i].getTimeGeneration();
            index = i;
        }
    }

    return vector_request[index];
}

void SourceControlleer::generationRequest(size_t number_source){
    Request request = vector_source[number_source].generationReqest();
    qDebug() << "time: " << request.getTimeGeneration();
    vector_request.push_back(request);
}

//------TEST METHOD-----------

void SourceControlleer::PRINT_VECTOR_REQ(){
    for(size_t i = 0; i < vector_request.size(); i++){
        qDebug() << vector_request[i].getTimeGeneration() << vector_request[i].getNumberOfSource();
    }
}


//------PRIVATE METHOD--------
void SourceControlleer::init_source(){
    for(int i = 0; i < count_source; i++){
        Source source(i, alpha, beta);
        vector_source.push_back(source);
    }

    vector_request.clear();
    for(size_t i = 0; i < vector_source.size(); i++){
        vector_request.push_back(vector_source[i].generationReqest());
    }
}


