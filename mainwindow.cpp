#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QNetworkRequest>
#include <QEventLoop>
#include <QJsonDocument>
#include <QJsonObject>
#include <QTimer>
#include <get.h>
#include <QJsonValue>
#include <QInputDialog>
#include <QFile>
#include <QDir>
#include <QTextStream>



const QString api_key=<place your token>;




QVariantList MainWindow::Crypto(){

    QVariantList list;
    QJsonDocument doc;
    QJsonObject obj;

    GET symbol1("https://api3.binance.com/api/v3/ticker/price?symbol=BTCUSDT");

    doc=QJsonDocument::fromJson(symbol1.Get_Reply());
    obj=doc.object();
    list.append(obj.value("price").toString().toDouble());



    GET symbol2("https://api3.binance.com/api/v3/ticker/price?symbol=ETHUSDT");

    doc=QJsonDocument::fromJson(symbol2.Get_Reply());
    obj=doc.object();
    list.append(obj.value("price").toString().toDouble());

    GET symbol3("https://api3.binance.com/api/v3/ticker/price?symbol=XRPUSDT");



    doc=QJsonDocument::fromJson(symbol3.Get_Reply());
    obj=doc.object();
    list.append(obj.value("price").toString().toDouble());


    GET symbol4("https://api3.binance.com/api/v3/ticker/price?symbol=BNBUSDT");

    doc=QJsonDocument::fromJson(symbol4.Get_Reply());
    obj=doc.object();
    list.append(obj.value("price").toString().toDouble());


    GET symbol5("https://api3.binance.com/api/v3/ticker/price?symbol=ADAUSDT");

    doc=QJsonDocument::fromJson(symbol5.Get_Reply());
    obj=doc.object();
    list.append(obj.value("price").toString().toDouble());


    GET symbol6("https://api3.binance.com/api/v3/ticker/price?symbol=LINKUSDT");

    doc=QJsonDocument::fromJson(symbol6.Get_Reply());
    obj=doc.object();
    list.append(obj.value("price").toString().toDouble());


    GET symbol7("https://api3.binance.com/api/v3/ticker/price?symbol=LTCUSDT");

    doc=QJsonDocument::fromJson(symbol7.Get_Reply());
    obj=doc.object();
    list.append(obj.value("price").toString().toDouble());

    GET symbol8("https://api3.binance.com/api/v3/ticker/price?symbol=TRXUSDT");

    doc=QJsonDocument::fromJson(symbol8.Get_Reply());
    obj=doc.object();
    list.append(obj.value("price").toString().toDouble());


    return list;
}

QVariantList MainWindow::forex(){

    QVariantList list;
    QJsonDocument doc;
    QJsonObject obj;


    GET symbol1("https://twelve-data1.p.rapidapi.com/price?symbol=WTI/USD");

    doc=QJsonDocument::fromJson(symbol1.Get_Reply( "x-rapidapi-key",api_key));
    obj=doc.object();
    list.append(obj.value("price"));



    GET symbol2("https://twelve-data1.p.rapidapi.com/price?symbol=XBR/USD");

    doc=QJsonDocument::fromJson(symbol2.Get_Reply("x-rapidapi-key",api_key));
    obj=doc.object();
    list.append(obj.value("price"));



    GET symbol3("https://twelve-data1.p.rapidapi.com/price?symbol=XAU/USD");

    doc=QJsonDocument::fromJson(symbol3.Get_Reply("x-rapidapi-key",api_key));
    obj=doc.object();
    list.append(obj.value("price"));


    GET symbol4("https://twelve-data1.p.rapidapi.com/price?symbol=XAG/USD");

    doc=QJsonDocument::fromJson(symbol4.Get_Reply("x-rapidapi-key","91c969a8e9msh8b47ffbad7457eep11a88ajsnc07f9fe9120e"));
    obj=doc.object();
    list.append(obj.value("price"));



    GET symbol5("https://twelve-data1.p.rapidapi.com/price?symbol=XPT/USD");

    doc=QJsonDocument::fromJson(symbol5.Get_Reply("x-rapidapi-key","91c969a8e9msh8b47ffbad7457eep11a88ajsnc07f9fe9120e"));
    obj=doc.object();
    list.append(obj.value("price"));



    GET symbol6("https://twelve-data1.p.rapidapi.com/price?symbol=EUR/USD");

    doc=QJsonDocument::fromJson(symbol6.Get_Reply("x-rapidapi-key","91c969a8e9msh8b47ffbad7457eep11a88ajsnc07f9fe9120e"));
    obj=doc.object();
    list.append(obj.value("price"));



    GET symbol7("https://twelve-data1.p.rapidapi.com/price?symbol=CAD/USD");

    doc=QJsonDocument::fromJson(symbol7.Get_Reply("x-rapidapi-key","91c969a8e9msh8b47ffbad7457eep11a88ajsnc07f9fe9120e"));
    obj=doc.object();
    list.append(obj.value("price"));



    GET symbol8("https://twelve-data1.p.rapidapi.com/price?symbol=NZD/USD");

    doc=QJsonDocument::fromJson(symbol8.Get_Reply("x-rapidapi-key","91c969a8e9msh8b47ffbad7457eep11a88ajsnc07f9fe9120e"));
    obj=doc.object();
    list.append(obj.value("price"));



    GET symbol9("https://twelve-data1.p.rapidapi.com/price?symbol=USD/TRY");

    doc=QJsonDocument::fromJson(symbol9.Get_Reply("x-rapidapi-key","91c969a8e9msh8b47ffbad7457eep11a88ajsnc07f9fe9120e"));
    obj=doc.object();
    list.append(obj.value("price"));



    return list;

}

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{

    QFile read_time("time.txt");
    read_time.open(QFile::ReadOnly);

    QString time=read_time.readLine();


    QTimer *timer=new QTimer;

    ui->text->append(QDateTime::currentDateTime().toString());
    ui->text->append("*");
    ui->text->append("*");
    ui->text->append("*");


    connect(timer,&QTimer::timeout,this,[=](){

        QVariantList crypto_list;
        QVariantList forex_list;

        crypto_list=MainWindow::Crypto();

        forex_list=MainWindow::forex();

        QString BTCUSDT="BTCUSDT :"+crypto_list[0].toString();
        QString ETHUSDT="ETHUSDT :"+crypto_list[1].toString();
        QString XRPUSDT= "XRPUSDT :"+crypto_list[2].toString();
        QString BNBUSDT="BNBUSDT :"+crypto_list[3].toString();
        QString ADAUSDT ="ADAUSDT :"+crypto_list[4].toString();
        QString LINKUSDT="LINKUSDT :"+crypto_list[5].toString();
        QString LTCUSDT="LTCUSDT :"+crypto_list[6].toString();
        QString TRXUSDT="TRXUSDT :"+crypto_list[7].toString();


        ui->text->append(BTCUSDT);
        ui->text->append(ETHUSDT);
        ui->text->append(XRPUSDT);
        ui->text->append(BNBUSDT);
        ui->text->append(ADAUSDT);
        ui->text->append(LINKUSDT);
        ui->text->append(LTCUSDT);
        ui->text->append(TRXUSDT);

        ui->text->append("");



        //FOREX


        QString crudeoil="Crude Oil :"+forex_list[0].toString();
        QString brentoil="Brent Oil :"+forex_list[1].toString();
        QString gold="Gold :"+forex_list[2].toString();
        QString silver="Silver :"+forex_list[3].toString();
        QString platinum= "Platinum :"+forex_list[4].toString();
        QString EURUSD="EURUSD :"+forex_list[5].toString();
        QString CADUSD="CADUSD :"+forex_list[6].toString();
        QString NZDUSD="NZDUSD :"+forex_list[7].toString();
       QString USDTRY="USDTRY :"+forex_list[8].toString();


        ui->text->append(crudeoil);
        ui->text->append(brentoil);
        ui->text->append(gold);
        ui->text->append(silver);
        ui->text->append(platinum);
        ui->text->append(EURUSD);
        ui->text->append(CADUSD);
        ui->text->append(NZDUSD);
        ui->text->append(USDTRY);
        ui->text->append(QDateTime::currentDateTime().toString());


         QEventLoop loop;
         QString crypto="Crypto :";

        QNetworkAccessManager acc;
        QNetworkRequest req;
        req.setUrl(QUrl("https://api.telegram.org/bot<yourbottoken>/sendMessage?chat_id=<yourtelegramchannel>username&text="+crypto+'\n'+"\x31\xE2\x83\xA3"+BTCUSDT+"\xF0\x9F\x92\xB2"+'\n'+"\x32\xE2\x83\xA3"+ETHUSDT+"\xF0\x9F\x92\xB2"+'\n'+"\x33\xE2\x83\xA3"+XRPUSDT+"\xF0\x9F\x92\xB2"+'\n'+"\x34\xE2\x83\xA3"+BNBUSDT+"\xF0\x9F\x92\xB2"+'\n'+"\x35\xE2\x83\xA3"+ADAUSDT+"\xF0\x9F\x92\xB2"+'\n'+"\x36\xE2\x83\xA3"+LINKUSDT+"\xF0\x9F\x92\xB2"+'\n'+"\x37\xE2\x83\xA3"+LTCUSDT+"\xF0\x9F\x92\xB2"+'\n'+"\x38\xE2\x83\xA3"+TRXUSDT+"\xF0\x9F\x92\xB2"+'\n'+'\n'+"Forex: "+'\n'+"\x31\xE2\x83\xA3"+crudeoil+"\U0001f6e2\uFE0F"+'\n'+"\x32\xE2\x83\xA3"+brentoil+"\U0001f6e2\uFE0F"+'\n'+"\x33\xE2\x83\xA3"+gold+"\U0001f3c6"+'\n'+"\x34\xE2\x83\xA3"+silver+"\U0001f948"+'\n'+"\x35\xE2\x83\xA3"+platinum+"\xF0\x9F\x85\xBF"+'\n'+"\x36\xE2\x83\xA3"+EURUSD+"\U0001f1ea\U0001f1fa"+'\n'+"\x37\xE2\x83\xA3"+CADUSD+"\U0001f1e8\U0001f1e6"+'\n'+"\x38\xE2\x83\xA3"+NZDUSD+"\U0001f1f3\U0001f1ff"+'\n'+"\x39\xE2\x83\xA3"+USDTRY+"\U0001f1f9\U0001f1f7"+'\n'+'\n'+'\n'+"------------------------------------------"+'\n'+"\xF0\x9F\x95\x91"+QDateTime::currentDateTime().toString()+'\n'+"\xF0\x9F\x93\x88"+"@Online_Price24"));
        QNetworkReply *rep=acc.get(req);


        connect(rep,SIGNAL(finished()),&loop,SLOT(quit()));
        loop.exec();

        ui->text->append(rep->readAll());

        ui->text->append("---------------------------------------------------------------------------------------------------------------------");

    });

    read_time.close();

    timer->start(time.toInt());


}

void MainWindow::on_pushButton_3_clicked()
{



        QFile write_time("time.txt");

        write_time.open(QFile::WriteOnly);

        QInputDialog *dialog=new QInputDialog;
       int time=dialog->getInt(this,tr("زمان"),tr(".لطفا زمان مورد نظر را وارد کنید"));


       QTextStream tetx(&write_time);
       tetx<<QString::number(time);


       write_time.close();

}
