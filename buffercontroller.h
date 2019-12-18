#ifndef BUFFERCONTROLLER_H
#define BUFFERCONTROLLER_H

#include "request.h"
#include "vector"
#include <QDebug>
#include "sourcecontrolleer.h"
class BufferController
{
public:
    BufferController(size_t buffer_size, SourceControlleer &sourceController);
    bool insert(Request request);
    Request getRequest();
    Request getCopyRequest();
    double error;
    size_t getBufferSize(){ return buffer_size;}
    int getBufferCountSize();
    size_t tmp_count_source; // выколите мои глаза! to-do

    void BUFFTEST();
    void buffPrint();
    std::vector<Request> vec;
    std::vector<Request> getBuffvec(){return vec;}
private:
    size_t buffer_size, pointer;
    bool checkFree(Request request);
    int getMinNumberSource();
    bool requestEqualRequest(Request request1, Request request2);
    bool requestEmpty(Request request);
    Request getEmptyRequest();
    //TESTING
    void buffDelete(size_t index);

    Request generationEmptyRequest();

    SourceControlleer *linkSourceController;
};

#endif // BUFFERCONTROLLER_H
