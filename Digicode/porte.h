#ifndef PORTE_H
#define PORTE_H

#include <QWidget>
#include <QPixmap>
#include <QDebug>

namespace Ui {
class porte;
}

class porte : public QWidget
{
    Q_OBJECT

public:
    explicit porte(QWidget *parent = nullptr);
    ~porte();
    void deverouiller();
    void verouiller();

private:
    Ui::porte *ui;
    QPixmap *imagePorte[2];


private slots :

};

#endif // PORTE_H
