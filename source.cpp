#include "source.h"

Source::Source()
{

}

Request Source::generationReqest(){
    double time_generation = 0.00003;
    Request request(time_generation);
    return request;
}
