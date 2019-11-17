#include "buffer.h"

Buffer::Buffer(size_t size)
{
    this->size = size;
    this->pointer = 0;
    Request request(0, 0, 0);
    for(int i = 0; i < size; i++) vec.push_back(request);
}

void Buffer::insert(Request request)
{
    for(int pointer = this->pointer; pointer < size; pointer++){
        if(vec[pointer].getTimeGeneration() == 0.0){
            vec[pointer] = request;
            this->pointer = pointer;
            //return;
       }
    }
}

Request Buffer::getRequest()
{
    return vec[pointer];
}

bool Buffer::checkFree(Request request){
    return true; //!!
}
