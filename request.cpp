#include "request.h"

Request::Request(double TimeOfGeneration)
{
    TimeGeneration = TimeOfGeneration;
}

double Request::getTimeGeneration(){
    return TimeGeneration;
};
