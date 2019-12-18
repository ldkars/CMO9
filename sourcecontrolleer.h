#ifndef SOURCECONTROLLEER_H
#define SOURCECONTROLLEER_H
#include <vector>
#include "request.h"
#include "source.h"
#include "QDebug"
class SourceControlleer
{
public:
    SourceControlleer(size_t count_source, double alpha, double beta);
    Request getRequest();
    Request getGhostRequest();
    void generationRequest(size_t number_source);
    //-------TEST_METHOD-------//
    void PRINT_VECTOR_REQ();
    std::vector<Request> getVecReq(){return vector_request;}
private:
    size_t count_source;
    std::vector<Request> vector_request;
    std::vector<Source> vector_source;
    double alpha;
    double beta;

    void init_source();
};

#endif // SOURCECONTROLLEER_H
