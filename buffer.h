#ifndef BUFFER_H
#define BUFFER_H

#include <request.h>
#include <vector>
class Buffer
{
public:
    Buffer();
    std::vector<Request> vec;
    void insert(Request req);
    Request getreq();
};

#endif // BUFFER_H
