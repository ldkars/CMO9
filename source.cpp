#include "source.h"

Source::Source(int numberOfSource)
{
    this->numberOfSource = numberOfSource;
}

Request Source::generationReqest(){
    this->time_generation = time_generation + 0.03;
    Request request(time_generation, counter, numberOfSource);
    counter++;// тут жопа
    return request;
}
