#ifndef FENETRE_H
#define FENETRE_H

#include <QMainWindow>
#include <QTcpSocket>
#include <QDebug>

QT_BEGIN_NAMESPACE
namespace Ui { class Fenetre; }
QT_END_NAMESPACE

class Fenetre : public QMainWindow
{
    Q_OBJECT

public:
    Fenetre(QWidget *parent = nullptr);
    ~Fenetre();

private slots:
    void on_pushButtonConnexion_clicked();

    void on_pushButtonEnvoyer_clicked();

    void onQTcpSocketConnected();
    void onQTcpSocketDisconnected();
    void onQTcpSocketErrorOccurred(QAbstractSocket::SocketError socketError);
    void onQTcpSocketStateChanged(QAbstractSocket::SocketState socketState);
    void onQTcpSocketReadyRead();
    


private:
    Ui::Fenetre *ui;
    QTcpSocket sockVersServeur;
};
#endif // FENETRE_H
