#include "buffer.h"

Buffer::Buffer(int size)
{
    this->size = size;
}

void Buffer::insert(Request req)
{
    vec.push_back(req); // вставка вектора вариант 18
}

Request Buffer::getreq()
{
    return vec[0]; //!!
}

bool Buffer::checkFree(Request request){
    return true; //!!
}
