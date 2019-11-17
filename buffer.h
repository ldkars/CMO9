#ifndef BUFFER_H
#define BUFFER_H

#include <request.h>
#include <vector>
#include <QDebug>
class Buffer
{
public:
    Buffer(size_t size);
    std::vector<Request> vec;
    void insert(Request request);
    Request getRequest();
    bool checkFree(Request request);
private:
    int size;
    size_t pointer;
};

#endif // BUFFER_H
