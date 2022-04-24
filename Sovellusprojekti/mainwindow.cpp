#include "mainwindow.h"
#include "ui_mainwindow.h"

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

void MainWindow::GetCarSlot(QNetworkReply *reply)
{
    {
     response_data=reply->readAll();
     qDebug()<<"DATA : "+response_data;
     QJsonDocument json_doc = QJsonDocument::fromJson(response_data);
     QJsonArray json_array = json_doc.array();
     QString car;
     foreach (const QJsonValue &value, json_array) {
        QJsonObject json_obj = value.toObject();
        car+=QString::number(json_obj["id_car"].toInt())+", "+json_obj["brand"].toString()+", "+json_obj["model"].toString()+"\r";
     }

     ui->CarTable->setText(car);

     reply->deleteLater();
     getManager->deleteLater();
    }
}






void MainWindow::on_GetCars_clicked()
{


QString site_url="http://localhost:3000/car";
QNetworkRequest request((site_url));
//BASIC AUTENTIKOINTI ALKU
QString credentials="root:root";
QByteArray data = credentials.toLocal8Bit().toBase64();
QString headerData = "Basic " + data;
request.setRawHeader( "Authorization", headerData.toLocal8Bit() );
//BASIC AUTENTIKOINTI LOPPU
getManager = new QNetworkAccessManager(this);

connect(getManager, SIGNAL(finished(QNetworkReply*)), this, SLOT(GetCarSlot(QNetworkReply*)));

reply = getManager->get(request);
}

