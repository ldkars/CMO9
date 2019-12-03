#include "source.h"
#include <QDebug>

Source::Source(int numberOfSource, double alpha, double beta)
{
    this->numberOfSource = numberOfSource;
    this->alpha = alpha;
    this->beta = beta;
}

Request Source::generationReqest(){
    this->time_generation += + this->alpha + rand0to1()*(this->beta - this->alpha);
    counter++;
    Request request(this->time_generation, this->counter, this->numberOfSource);
    return request;
}
