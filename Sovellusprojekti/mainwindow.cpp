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

void MainWindow::updateCarSlot(QNetworkReply *reply)
{

        response_data=reply->readAll();
        qDebug()<<response_data;
        reply->deleteLater();
        putManager->deleteLater();

}

void MainWindow::addCarSlot(QNetworkReply *reply)
{
    response_data=reply->readAll();
    qDebug()<<response_data;
    reply->deleteLater();
    postManager->deleteLater();
}

void MainWindow::DeleteCarSlot(QNetworkReply *reply)
{
    response_data=reply->readAll();
    qDebug()<<response_data;
    reply->deleteLater();
    putManager->deleteLater();
}




void MainWindow::on_btngetcar_clicked()
{
   // QString Brand = ui->textEdit->toPlainText();
   // ui->CarBrand->setText("brand" +Brand);            //Ei toimi vielä
    //QString Model = ui->textEdit->toPlainText();
      //  ui->CarModel->setText("model" +Model);
    QJsonObject jsonObj;
    jsonObj.insert("brand","Post");
    jsonObj.insert("model","Test");


    QString site_url="http://localhost:3000/car";
    QNetworkRequest request((site_url));
    request.setHeader(QNetworkRequest::ContentTypeHeader, QString("application/json"));
    //BASIC AUTENTIKOINTI ALKU
    QString credentials="root:root";
    QByteArray data = credentials.toLocal8Bit().toBase64();
    QString headerData = "Basic " + data;
    request.setRawHeader( "Authorization", headerData.toLocal8Bit() );
    //BASIC AUTENTIKOINTI LOPPU

    postManager = new QNetworkAccessManager(this);
    connect(postManager, SIGNAL(finished (QNetworkReply*)), this, SLOT(addCarSlot(QNetworkReply*)));

    reply = postManager->post(request, QJsonDocument(jsonObj).toJson());
}


void MainWindow::on_pushButton_clicked()
{
    QJsonObject jsonObj;
    jsonObj.insert("brand","Muokattu auto");
    jsonObj.insert("model","Testi");


    QString site_url="http://localhost:3000/car/8";
    QNetworkRequest request((site_url));
    request.setHeader(QNetworkRequest::ContentTypeHeader, QString("application/json"));
    //BASIC AUTENTIKOINTI ALKU
    QString credentials="root:root";
    QByteArray data = credentials.toLocal8Bit().toBase64();
    QString headerData = "Basic " + data;
    request.setRawHeader( "Authorization", headerData.toLocal8Bit() );
    //BASIC AUTENTIKOINTI LOPPU

    putManager = new QNetworkAccessManager(this);
    connect(putManager, SIGNAL(finished (QNetworkReply*)), this, SLOT(updateCarSlot(QNetworkReply*)));

    reply = putManager->put(request, QJsonDocument(jsonObj).toJson());
}


void MainWindow::on_DeleteCar_clicked()
{

    QString site_url="http://localhost:3000/car/8";
    QNetworkRequest request((site_url));
    //BASIC AUTENTIKOINTI ALKU
    QString credentials="root:root";
    QByteArray data = credentials.toLocal8Bit().toBase64();
    QString headerData = "Basic " + data;
    request.setRawHeader( "Authorization", headerData.toLocal8Bit() );
    //BASIC AUTENTIKOINTI LOPPU
    deleteResource = new QNetworkAccessManager(this);

    connect(deleteResource, SIGNAL(finished(QNetworkReply*)), this, SLOT(DeleteCarSlot(QNetworkReply*)));

    reply = deleteResource->deleteResource(request);
}

