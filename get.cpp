#include "get.h"
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QNetworkRequest>
#include <QEventLoop>
#include <QObject>

QByteArray GET::Get_Reply(){

    QEventLoop loop;

    QNetworkAccessManager acc;
    QNetworkRequest req((QUrl(URL)));

    QNetworkReply *rep=acc.get(req);
    QObject::connect(rep,SIGNAL(finished()),&loop,SLOT(quit()));
    loop.exec();


    return rep->readAll();
}

QByteArray GET::Get_Reply(QByteArray type,QByteArray value){

    QEventLoop loop;
    QNetworkAccessManager acc;

    QNetworkRequest req((QUrl(URL)));

    req.setRawHeader(type,value);

    QNetworkReply *rep=acc.get(req);

    QObject::connect(rep,SIGNAL(finished()),&loop,SLOT(quit()));
    loop.exec();

    return rep->readAll();
}

