#ifndef LOGEVENT_H
#define LOGEVENT_H
#include <string>
#include <QString>

class LogEvent
{
public:
    LogEvent();
    QString buffer_info;
    QString fail_info;
    QString device_info;
    QString new_req;

    void setbuffer_info(QString buffer_info){this->buffer_info = buffer_info;}
    void setfail_info(QString fail_info){this->fail_info = fail_info;}
    void setdevice_info(QString device_info){this->device_info = device_info;}
    void setnew_req(QString new_req){this->new_req = new_req;}
};

#endif // LOGEVENT_H
