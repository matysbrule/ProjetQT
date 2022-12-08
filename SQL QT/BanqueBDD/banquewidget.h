#ifndef BANQUEWIDGET_H
#define BANQUEWIDGET_H

#include <QWidget>
#include <QSqlDatabase>
#include <QDebug>
#include <QSqlError>
#include <QSqlQuery>
#include <QFileInfo>
#include <QMessageBox>
#include <QSettings>
#include <QHeaderView>

QT_BEGIN_NAMESPACE
namespace Ui { class BanqueWidget; }
QT_END_NAMESPACE

class BanqueWidget : public QWidget
{
    Q_OBJECT

public:
    BanqueWidget(QWidget *parent = nullptr);
    ~BanqueWidget();
    int ligne = 0;
    int col = 0;

private slots:
    void on_pushButtonCONNEXION_clicked();

    void on_pushButtonAfficherInfo_clicked();

private:
    Ui::BanqueWidget *ui;
       QSqlDatabase bdd;
       QSqlQuery *requete;
       QHeaderView *headers;
};
#endif // BANQUEWIDGET_H
