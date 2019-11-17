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
private:
    size_t buffer_size;
    bool checkFree(Request request);
};

#endif // BUFFERCONTROLLER_H
