#ifndef REQUEST_H
#define REQUEST_H


class Request
{
public:
    Request(double TimeGeneration, int counter, int numberOfSource);
    double getTimeGeneration();
private:
    double TimeGeneration;
    int counter;
    int numberOfSource;
};

#endif // REQUEST_H
