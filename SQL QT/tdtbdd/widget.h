#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QSqlDatabase>
#include <QDebug>
#include <QSqlError>
#include <QString>
#include <QSqlQuery>

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

private slots:
    void on_pushButtonConnexion_clicked();

    void on_pushListeDepartement_clicked();

    void on_pushButtonLIste2_clicked();

    void on_pushButtonQuitter_clicked();

private:
    Ui::Widget *ui;
    QSqlDatabase bd;

};
#endif // WIDGET_H
