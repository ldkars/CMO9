#ifndef BUFFERCONTROLLER_H
#define BUFFERCONTROLLER_H

#include "request.h"
#include "vector"
#include <QDebug>

class BufferController
{
public:
    BufferController(size_t buffer_size);
    void insert(Request request);
    Request getRequest();
    Request getCopyRequest();
    int error;
    size_t getBufferSize(){ return buffer_size;}
    int getBufferCountSize();

    void BUFFTEST();
    void buffPrint();
private:
    size_t buffer_size, pointer;
    bool checkFree(Request request);
    std::vector<Request> vec;
    int getMinNumberSource();
    bool requestEqualRequest(Request request1, Request request2);
    bool requestEmpty(Request request);
    Request getEmptyRequest();
    //TESTING
    void buffDelete(size_t index);

    Request generationEmptyRequest();
};

#endif // BUFFERCONTROLLER_H
