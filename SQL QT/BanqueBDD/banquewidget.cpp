#include "banquewidget.h"
#include "ui_banquewidget.h"

BanqueWidget::BanqueWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::BanqueWidget)
{
    ui->setupUi(this);
    QHeaderView *headers = ui->tableWidgetInfoCompte->horizontalHeader();
    headers->setSectionResizeMode(QHeaderView::Stretch);
}

BanqueWidget::~BanqueWidget()
{
    delete ui;
}


void BanqueWidget::on_pushButtonCONNEXION_clicked()
{
    bdd=QSqlDatabase::addDatabase("QMYSQL");
    bdd.setHostName(ui->lineEdit_IP->text());
    bdd.setDatabaseName(ui->lineEdit_BDD->text());
    bdd.setUserName(ui->lineEdit_Login->text());
    bdd.setPassword(ui->lineEdit_Mdp->text());

    if(!bdd.open()){
        QMessageBox Erreur;
        Erreur.setText(bdd.lastError().text());
        Erreur.exec();
    } else{
        qDebug()<<"Connecté à la base de données";
        ui->groupBox_ConnexionBDD->setDisabled(true);
        ui->groupBox_informationsBanques->setDisabled(false);

    }
}


void BanqueWidget::on_pushButtonAfficherInfo_clicked()
{
    QSqlQuery requete;
    requete.prepare("select comptes.nom, prenom, idCompte, solde, agences.nom, agences.Ville from comptes, agences ;");
    if (!requete.exec())
    {
        qDebug()<<requete.lastError().text();
    }
    //    QString nom, prenom, idCompte, soldes;
    while(requete.next())
    {
        //        nom=requete.value("nom").toString();
        //        prenom=requete.value("prenom").toString();
        //        idCompte=requete.value("idCompte").toString();
        //        soldes=requete.value("solde").toString();
        //        ui->textEdit->append(nom+" "+prenom+" "+idCompte+" "+soldes);

        ui->tableWidgetInfoCompte->insertRow(ui->tableWidgetInfoCompte->rowCount());

// ajouter le numéro de compte
        QTableWidgetItem *idCompteItem = new QTableWidgetItem(requete.value("idCompte").toString());
        ui->tableWidgetInfoCompte->setItem(ligne,col++,idCompteItem);
// ajouter un nom
        QTableWidgetItem *nomItem = new QTableWidgetItem(requete.value("comptes.nom").toString());
        ui->tableWidgetInfoCompte->setItem(ligne,col++,nomItem);
// ajouter un prénom
        QTableWidgetItem *prenomItem = new QTableWidgetItem(requete.value("prenom").toString());
        ui->tableWidgetInfoCompte->setItem(ligne,col++,prenomItem);
// ajouter le solde
        QTableWidgetItem *soldeItem = new QTableWidgetItem(requete.value("solde").toString());
        ui->tableWidgetInfoCompte->setItem(ligne,col++,soldeItem);
// ajouter la ville
        QTableWidgetItem *villeItem = new QTableWidgetItem(requete.value("agences.Ville").toString());
        ui->tableWidgetInfoCompte->setItem(ligne,col++,villeItem);
// ajouter l'agence
        QTableWidgetItem *agenceItem = new QTableWidgetItem(requete.value("agences.nom").toString());
        ui->tableWidgetInfoCompte->setItem(ligne,col++,agenceItem);

    }


}


