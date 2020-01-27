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

    std::vector<Request> getReqInSystems(int number_size);
    std::vector<Request> getVecRequest(){return vector_request;}
    std::vector<Request> getReqInSystems(){return requestInSystems;}


    std::vector<Source> getVecSource(){return vector_source;}

    size_t getCountSource(){return vector_source.size();}

    //-------TEST_METHOD-------//
    void PRINT_VECTOR_REQ();

private:
    size_t count_source;

    double alpha;
    double beta;

    std::vector<Request> vector_request;
    std::vector<Request> requestInSystems;
    std::vector<Source> vector_source;

    void init_source();
};

#endif // SOURCECONTROLLEER_H
