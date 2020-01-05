#ifndef BUFFERCONTROLLER_H
#define BUFFERCONTROLLER_H

#include "request.h"
#include "vector"
#include <QDebug>
#include "sourcecontrolleer.h"

#define GetIndex(_index,_size) ( ( (_index%_size) + _size )%_size )

class BufferController
{
public:
    BufferController(size_t buffer_size, SourceControlleer &sourceController);

    bool insert(Request request);

    Request getRequest();
    Request getCopyRequest();

    size_t getBufferSize(){ return buffer_size;}

    std::vector<Request> getBuffvec(){return vec;}
    std::vector<Request> getFailureRequest(int number_source);
    std::vector<Request> vec;
    std::vector<Request> occupiedReq; //Понадобится для определения времени пребывания заявок, которые были выбиты

    double error = 0.0;

    void buffPrint();



private:
    size_t buffer_size;
    size_t pointer = 0;

    int getMinNumberSource();

    bool checkFree(Request request);
    bool requestEqualRequest(Request request1, Request request2);
    bool requestEmpty(Request request);

    Request getEmptyRequest();
    Request findMinTimeReqest(std::vector<Request> &vec_request);

    SourceControlleer *linkSourceController;

    std::vector<Request> getPreorityRequest();
    std::vector<Request> failureRequest;

    void initVectorEmpty();
    void deleteRequest(Request request);
};

#endif // BUFFERCONTROLLER_H
