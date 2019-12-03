#ifndef SOURCE_H
#define SOURCE_H

#include "request.h"
#include "random.h"
class Source
{
public:
    Source(int numberOfSource, double alpha, double beta);
    Request generationReqest();
private:
    int counter;
    int numberOfSource;
    double time_generation;
    double alpha = 0.0;
    double beta = 0.0;
};

#endif // SOURCE_H
