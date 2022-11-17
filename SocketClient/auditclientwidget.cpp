#include "auditclientwidget.h"
#include "ui_auditclientwidget.h"

AuditClientWidget::AuditClientWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::AuditClientWidget)
{

    ui->setupUi(this);
        socketDeDialogueAvecServeur = new QTcpSocket(this);
        connect(socketDeDialogueAvecServeur,&QTcpSocket::connected,this,&AuditClientWidget::onQTcpSocketConnected);
        connect(socketDeDialogueAvecServeur,&QTcpSocket::disconnected,this,&AuditClientWidget::onQTcpSocketDisconnected);
        connect(socketDeDialogueAvecServeur,&QTcpSocket::hostFound,this,&AuditClientWidget::onQTcpSocketHostFound);
        connect(socketDeDialogueAvecServeur,&QTcpSocket::bytesWritten,this,&AuditClientWidget::onQTcpSocketBytesWritten);
        connect(socketDeDialogueAvecServeur,&QTcpSocket::readyRead,this,&AuditClientWidget::onQTcpSocketReadyRead);
        connect(socketDeDialogueAvecServeur,&QTcpSocket::aboutToClose,this,&AuditClientWidget::onQTcpSocketAboutToClose);
        connect(socketDeDialogueAvecServeur,&QTcpSocket::errorOccurred, this, &AuditClientWidget::onQTcpSocketErrorOccurred);
        connect(socketDeDialogueAvecServeur,&QTcpSocket::stateChanged,this,&AuditClientWidget::onQTcpSocketStateChanged);
        connect(socketDeDialogueAvecServeur,&QTcpSocket::readChannelFinished,this,&AuditClientWidget::onQTcpSocketReadChannelFinished);

}

AuditClientWidget::~AuditClientWidget()
{
    delete ui;
}


void AuditClientWidget::on_pushButtonConnexion_clicked()
{
     socketDeDialogueAvecServeur->connectToHost(ui->lineEditAdresseIP->text(),ui->spinBoxPort->value());
}


void AuditClientWidget::on_pushButtonQuitter_clicked()
{
    close();
}


void AuditClientWidget::on_pushButtonArchitecture_clicked()
{
    typeDeDemande="a";
        socketDeDialogueAvecServeur->write(typeDeDemande.toLatin1());
}


void AuditClientWidget::on_pushButtonUtilisateur_clicked()
{
    typeDeDemande="u";
       socketDeDialogueAvecServeur->write(typeDeDemande.toLatin1());
}


void AuditClientWidget::on_pushButtonOrdinateur_clicked()
{
    typeDeDemande="c";
       socketDeDialogueAvecServeur->write(typeDeDemande.toLatin1());
}


void AuditClientWidget::on_pushButtonOs_clicked()
{
    typeDeDemande="o";
    socketDeDialogueAvecServeur->write(typeDeDemande.toLatin1());

    }
void AuditClientWidget::onQTcpSocketConnected()
{
    qDebug()<<"connected";


      ui->pushButtonConnexion->setDisabled(true);  // désactiver le bouton envoyer
      ui->spinBoxPort->setDisabled(true);    // désactiver le bouton envoyer
      ui->lineEditAdresseIP->setDisabled(true);    // désactiver le bouton envoyer

}


void AuditClientWidget::onQTcpSocketDisconnected()
{
    qDebug()<<"disconnected";
       ui->pushButtonConnexion->setDisabled(false);  // activer le bouton envoyer
       ui->spinBoxPort->setDisabled(false);    // activer le bouton envoyer
       ui->lineEditAdresseIP->setDisabled(false);    // activer le bouton envoyer
       ui->lineEditNomUtilisateur->setDisabled(true);
       ui->lineEditNomUtilisateur->setDisabled(true);
       ui->lineEditArchitectureProcesseur->setDisabled(true);
       ui->lineEditOSOrdinateur->setDisabled(true);
}

void AuditClientWidget::onQTcpSocketErrorOccurred(QAbstractSocket::SocketError socketError)
{
    Q_UNUSED(socketError); // le paramètre n'est pas utilisé dans cette méthode
    ui->textEditEtat->append(socketDeDialogueAvecServeur->errorString());
    }

void AuditClientWidget::onQTcpSocketStateChanged(QAbstractSocket::SocketState socketState)
{
    switch (socketState) {
        case QAbstractSocket::UnconnectedState:
            ui->textEditEtat->append("The socket is not connected.");
            break;
        case QAbstractSocket::HostLookupState:
            ui->textEditEtat->append("The socket is performing a host name lookup.");
            break;
        case QAbstractSocket::ConnectingState:
            ui->textEditEtat->append("The socket has started establishing a connection.");
            break;
        case QAbstractSocket::ConnectedState:
            ui->textEditEtat->append("A connection is established.");
            break;
        case QAbstractSocket::BoundState:
            ui->textEditEtat->append("The socket is bound to an address and port.");
            break;
        case QAbstractSocket::ClosingState:
            ui->textEditEtat->append("The socket is about to close (data may still be waiting to be written).");
            break;
        case QAbstractSocket::ListeningState:
            ui->textEditEtat->append("For internal use only.");
            break;
        }
}

void AuditClientWidget::onQTcpSocketReadyRead()
{
    QByteArray reponse;
    reponse = socketDeDialogueAvecServeur->readAll();
       ui->textEditEtat->append(reponse);
       switch(typeDeDemande.at(0).toLatin1())
           {
           case 'c': ui ->lineEditNomOrdinateur->setText(reponse); break ;
           case 'u': ui ->lineEditNomUtilisateur->setText(reponse); break ;
           case 'a': ui ->lineEditArchitectureProcesseur->setText(reponse); break ;
           case 'o': ui ->lineEditOSOrdinateur->setText(reponse); break ;
           }
}

void AuditClientWidget::onQTcpSocketHostFound()
{
ui-> textEditEtat->append("Host Found");
}

void AuditClientWidget::onQTcpSocketAboutToClose()
{
ui-> textEditEtat->append("The socket is about to close");
}

void AuditClientWidget::onQTcpSocketBytesWritten(qint64 bytes)
{
ui->textEditEtat->append(QString::number(bytes) + "bytes written.");
}

void AuditClientWidget::onQTcpSocketChannelBytesWritten(int channel, qint64 bytes)
{
ui->textEditEtat->append(QString::number(bytes) + "bytes written on the channel" + QString::number(channel) + ".");
}

void AuditClientWidget::onQTcpSocketChannelReadyRead(int channel)
{
ui->textEditEtat->append("Read on the channel" + QString::number(channel) + ".");
}

void AuditClientWidget::onQTcpSocketReadChannelFinished()
{
  ui->textEditEtat->append("F3 - le serveur met fin au dialogue.");
}



