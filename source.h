#ifndef SOURCE_H
#define SOURCE_H

#include "request.h"
#include "random.h"
class Source
{
public:
    Source(int numberOfSource);
    Request generationReqest();
private:
    int counter;
    int numberOfSource;
    double time_generation;
    double alpha = 0.5;
    double beta = 1.0;
};

#endif // SOURCE_H
