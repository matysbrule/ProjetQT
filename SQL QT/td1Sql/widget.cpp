#include "widget.h"
#include "ui_widget.h"


Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    bd=QSqlDatabase::addDatabase("QMYSQL");
    QFileInfo conf("BaseDeDonnes.ini");
    if (conf.exists() && conf.isFile())
    {
        QSettings param("BaseDeDonnes.ini",QSettings::IniFormat);
        bd.setHostName(param.value("BDD/addDatabase").toString());
        bd.setHostName(param.value("BDD/setDatabaseName").toString());
        bd.setHostName(param.value("BDD/setUserName").toString());
        bd.setHostName(param.value("BDD/setPassword").toString());
    }
    if(!bd.open()){
        qDebug() <<"bdd ouverte";
    }
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_pushButton_ObtenirNumero_clicked()
{
    QSqlQuery requetePreparee;
    requetePreparee.prepare("select name from departments where code like :codeDept; ");
    QString numeroDepartement;
    numeroDepartement = ui->lineEditDepartement->text();
    requetePreparee.bindValue(":codeDept",numeroDepartement);
    if (!requetePreparee.exec())
    {
        qDebug()<<requetePreparee.lastError().text();
    }
    QString nomDepartement;
    while(requetePreparee.next())
    {
        nomDepartement=requetePreparee.value("name").toString();
        ui->labelDepartement->setText(nomDepartement);
        qDebug()<<nomDepartement;
    }
}
