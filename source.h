#ifndef SOURCE_H
#define SOURCE_H

#include "request.h"
class Source
{
public:
    Source(int numberOfSource);
    Request generationReqest();
private:
    int counter;
    int numberOfSource;
    double time_generation;
};

#endif // SOURCE_H
