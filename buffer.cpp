#include "buffer.h"

Buffer::Buffer()
{

}

void Buffer::insert(Request req)
{
    vec.push_back(req); // вставка вектора вариант 18
}

Request Buffer::getreq()
{
    return vec[0]; //!!
}
