#include "porte.h"
#include "ui_porte.h"

porte::porte(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::porte)
{
    ui->setupUi(this);

    imagePorte[0] = new QPixmap(":/images/portes_ouverte.png)");
    imagePorte[1] = new QPixmap(":/images/portes_fermee.png)");
}

porte::~porte()
{
    delete ui;
    delete imagePorte[0];
    delete imagePorte[1];
}

void porte::deverouiller()
{
    ui->labelEtat->setText("La porte dévérouiller");
    ui->LabelIMage->setPixmap(*imagePorte[0]);

}

void porte::verouiller()
{
    ui->labelEtat->setText("La porte vérouiller");
    ui->LabelIMage->setPixmap(*imagePorte[1]);

}

