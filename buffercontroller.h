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
    int error;

    void BUFFTEST();

private:
    size_t buffer_size, pointer;
    bool checkFree(Request request);
    std::vector<Request> vec;
    int getMinNumberSource();

    //TESTING
    void buffDelete(size_t index);
    void buffPrint();
};

#endif // BUFFERCONTROLLER_H
