#ifndef REQUEST_H
#define REQUEST_H


class Request
{
public:
    Request(double TimeGeneration, int counter, int numberOfSource);

    double getTimeGeneration();
    double releaseTime = 0;

    int getNumberOfSource(){ return numberOfSource; }
    int getCounter(){return counter;}
private:
    double TimeGeneration;
    int counter;
    int numberOfSource;
};

#endif // REQUEST_H
