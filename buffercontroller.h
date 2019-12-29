#ifndef BUFFERCONTROLLER_H
#define BUFFERCONTROLLER_H

#include "request.h"
#include "vector"
#include <QDebug>
#include "sourcecontrolleer.h"
class BufferController
{
public:
    BufferController(size_t buffer_size, SourceControlleer &sourceController);

    bool insert(Request request);

    Request getRequest();
    Request getCopyRequest();
    size_t getBufferSize(){ return buffer_size;}
    int getBufferCountSize(); //количество заявкой
    std::vector<Request> getBuffvec(){return vec;}

    double error = 0.0;

    void BUFFTEST();
    void buffPrint();

    std::vector<Request> vec;

private:
    size_t buffer_size;
    size_t pointer = 0;
    bool checkFree(Request request);
    int getMinNumberSource();
    bool requestEqualRequest(Request request1, Request request2);
    bool requestEmpty(Request request);
    Request getEmptyRequest();
    void buffDelete(size_t index);
    Request generationEmptyRequest();
    void initVectorEmpty();

    SourceControlleer *linkSourceController;

    std::vector<Request> getPreorityRequest();
    Request findMinTimeReqest(std::vector<Request> &vec_request);
    void deleteRequest(Request request);
    std::vector<Request> vec_priority;
};

#endif // BUFFERCONTROLLER_H
