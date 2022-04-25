#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtNetwork>
#include <QNetworkAccessManager>
#include <QJsonDocument>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
private slots:

    void GetCarSlot(QNetworkReply *reply);

    void on_GetCars_clicked();
    void updateCarSlot (QNetworkReply *reply);
    void addCarSlot (QNetworkReply *reply);
    void on_btngetcar_clicked();

    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;
    QNetworkAccessManager *getManager;
    QNetworkReply *reply;
    QByteArray response_data;
    QNetworkAccessManager *postManager;
    QNetworkAccessManager *putManager;
};
#endif // MAINWINDOW_H
