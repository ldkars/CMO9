#include "request.h"

Request::Request(double TimeGeneration, int counter, int numberOfSource)
{
    this->TimeGeneration = TimeGeneration;
    this->numberOfSource = numberOfSource;
    this->counter = counter;
}

double Request::getTimeGeneration(){
    return TimeGeneration;
};
