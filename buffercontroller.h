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
    void buffPrint();
private:
    size_t buffer_size, pointer;
    bool checkFree(Request request);
    std::vector<Request> vec;
    int getMinNumberSource();
    bool requestEmpty(Request request);
    //TESTING
    void buffDelete(size_t index);

    Request generationEmptyRequest();
};

#endif // BUFFERCONTROLLER_H
