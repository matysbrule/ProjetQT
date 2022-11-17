#include "fenetre.h"
#include "ui_fenetre.h"

Fenetre::Fenetre(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Fenetre)
{
    ui->setupUi(this);
    ui->pushButtonEnvoyer->setDisabled(true); // desactiver le bouton envoyer
    ui->lineEditMessage->setDisabled(true); // desactiver le bouton envoyer
    //association signal/slot pour sockVersServeur
    connect(&sockVersServeur, &QTcpSocket::connected, this, &Fenetre::onQTcpSocketConnected);
    connect(&sockVersServeur, &QTcpSocket::disconnected, this, &Fenetre::onQTcpSocketDisconnected);
    connect(&sockVersServeur, &QTcpSocket::readyRead, this, &Fenetre::onQTcpSocketReadyRead);
    connect(&sockVersServeur, &QTcpSocket::stateChanged, this, &Fenetre::onQTcpSocketStateChanged);
    connect(&sockVersServeur, &QTcpSocket::errorOccurred, this, &Fenetre::onQTcpSocketErrorOccurred);
}

Fenetre::~Fenetre()
{
    delete ui;
}


void Fenetre::on_pushButtonConnexion_clicked()
{
    sockVersServeur.connectToHost(ui->lineEditServer->text(),ui->spinBoxPortServer->value());

}


void Fenetre::on_pushButtonEnvoyer_clicked()
{
    sockVersServeur.write(ui->lineEditMessage->text().toUtf8());
}

void Fenetre::onQTcpSocketConnected()
{
    qDebug()<<"connected";
    ui->pushButtonEnvoyer->setDisabled(false);  // activer le bouton envoyer
    ui->lineEditMessage->setDisabled(false);    // activer le bouton envoyer
    ui->pushButtonConnexion->setDisabled(true);  // désactiver le bouton envoyer
    ui->spinBoxPortServer->setDisabled(true);    // désactiver le bouton envoyer
    ui->lineEditServer->setDisabled(true);    // désactiver le bouton envoyer
}

void Fenetre::onQTcpSocketDisconnected()
{
    qDebug()<<"disconnected";
    ui->pushButtonEnvoyer->setDisabled(true);  // désactiver le bouton envoyer
    ui->lineEditMessage->setDisabled(true);    // désactiver le bouton envoyer
    ui->pushButtonConnexion->setDisabled(false);  // activer le bouton envoyer
    ui->spinBoxPortServer->setDisabled(false);    // activer le bouton envoyer
    ui->lineEditServer->setDisabled(false);    // activer le bouton envoyer
}

void Fenetre::onQTcpSocketReadyRead()
{
    QByteArray reponse;
    reponse = sockVersServeur.readAll();
    ui->textEditStatus->append(reponse);
}

void Fenetre::onQTcpSocketStateChanged(QAbstractSocket::SocketState socketState)
{
    switch (socketState) {
    case QAbstractSocket::UnconnectedState:
        ui->textEditStatus->append("The socket is not connected.");
        break;
    case QAbstractSocket::HostLookupState:
        ui->textEditStatus->append("The socket is performing a host name lookup.");
        break;
    case QAbstractSocket::ConnectingState:
        ui->textEditStatus->append("The socket has started establishing a connection.");
        break;
    case QAbstractSocket::ConnectedState:
        ui->textEditStatus->append("A connection is established.");
        break;
    case QAbstractSocket::BoundState:
        ui->textEditStatus->append("The socket is bound to an address and port.");
        break;
    case QAbstractSocket::ClosingState:
        ui->textEditStatus->append("The socket is about to close (data may still be waiting to be written).");
        break;
    case QAbstractSocket::ListeningState:
        ui->textEditStatus->append("For internal use only.");
        break;
    }
}

void Fenetre::onQTcpSocketErrorOccurred(QAbstractSocket::SocketError socketError)
{
    ui->textEditStatus->append(sockVersServeur.errorString());
}
