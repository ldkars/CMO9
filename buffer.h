#ifndef BUFFER_H
#define BUFFER_H

#include <request.h>
#include <vector>
class Buffer
{
public:
    Buffer(int size);
    std::vector<Request> vec;
    void insert(Request req);
    Request getreq();
    bool checkFree(Request request);
private:
    int size;
};

#endif // BUFFER_H
