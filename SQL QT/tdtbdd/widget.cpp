#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
}

Widget::~Widget()
{
    delete ui;
}


void Widget::on_pushButtonConnexion_clicked()
{
    bd=QSqlDatabase::addDatabase("QMYSQL");
    bd.setHostName("172.18.58.8");
    bd.setDatabaseName("france2018");
    bd.setUserName("snir");
    bd.setPassword("snir");
    if (!bd.open())
    {
    qDebug()<<bd.lastError().text();
    }
    else
    {
    qDebug()<<"acces bdd ok!";
    }
}


void Widget::on_pushListeDepartement_clicked()
{
    QSqlQuery requete("select name from departments;");
    if (!requete.exec())
    {
    qDebug()<<requete.lastError().text();
    }
    int nbLignes = requete.size();
    qDebug()<<"Nombre de départements : "<<nbLignes;
    QString nomDepartement;
    while(requete.next())
    {
    nomDepartement=requete.value("name").toString();
    qDebug()<<nomDepartement;
    }
}


void Widget::on_pushButtonLIste2_clicked()
{
    QSqlQuery requetePreparee;
    requetePreparee.prepare("select name from departments where region_code like :idRegion; ");
    QString codeRegion;
    codeRegion=ui->lineEditDepartement->text();
    requetePreparee.bindValue(":idRegion",codeRegion);
    if (!requetePreparee.exec())
    {
    qDebug()<<requetePreparee.lastError().text();
    }
    int nbDept = requetePreparee.size();
    qDebug()<<"Nombre de départements de la région 52 : "<<nbDept;
    QString nomDepartementRegion;
    while(requetePreparee.next())
    {
    nomDepartementRegion=requetePreparee.value("name").toString();
    qDebug()<<nomDepartementRegion;
    }
}


void Widget::on_pushButtonQuitter_clicked()
{
    close();

}

