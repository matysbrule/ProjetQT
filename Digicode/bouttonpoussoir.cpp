#include "bouttonpoussoir.h"
#include "ui_bouttonpoussoir.h"

Bouttonpoussoir::Bouttonpoussoir(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Bouttonpoussoir)
{
    ui->setupUi(this);
}

Bouttonpoussoir::~Bouttonpoussoir()
{
    delete ui;
}

void Bouttonpoussoir::on_PushButtonBP_clicked()
{
    emit action();
}


