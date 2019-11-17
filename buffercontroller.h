#ifndef BUFFERCONTROLLER_H
#define BUFFERCONTROLLER_H
// сюда приходит заявка и он уже сам думает как ему танцевать;
#include "request.h"
#include "buffer.h"
#include "vector"
class BufferController
{
public:
    BufferController(int count_buffer);
    void insert(Request request);
    Request getRequestOutBuffer();
private:
    int count_buffer;
    std::vector<Buffer> vector_buffer;
    bool checkFree(Request request);
};

#endif // BUFFERCONTROLLER_H
