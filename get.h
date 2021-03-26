#ifndef GET_H
#define GET_H
#include <QString>


class GET
{
public:
    QString URL;

    GET(QString URL_user ){
        URL=URL_user;
    }


    QByteArray Get_Reply();
    QByteArray Get_Reply(QByteArray type ,QByteArray value);        //for rawHeader





};

#endif // GET_H
