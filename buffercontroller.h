#ifndef BUFFERCONTROLLER_H
#define BUFFERCONTROLLER_H

#include "request.h"
#include "vector"

class BufferController
{
public:
    BufferController(size_t buffer_size);
    void insert(Request request);
    Request getRequestOutBuffer();
    int error;
private:
    size_t buffer_size, pointer;
    bool checkFree(Request request);
    std::vector<Request> vec;
};

#endif // BUFFERCONTROLLER_H
