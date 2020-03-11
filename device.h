#ifndef DEVICE_H
#define DEVICE_H
#include <vector>
#include "request.h"
#include "random.h"
//#include "logevent.h"
class Device
{
public:
    Device(size_t number, double lambda);

    int getNumberOfSource(){return number_source;}

    double getTime(){return time;}
    double getT_SERVICE();

    void insert(Request request);
    void setNumber(size_t num){number = num;}
    void setTime(double tim){time = tim;}
    void setLam(double lamda){lam = lamda;}

    std::vector<Request> completedReq;


private:
    size_t number = 0;

    double time = 0.0;
    double lam = 0.0;
    double T_SUMM, T_SERVICE = 0;

    int number_source = 0;
    int counter = 0;
};

#endif // DEVICE_H
