#include "digicode.h"
#include "ui_digicode.h"

digicode::digicode(QWidget *parent)
  : QWidget(parent)
  , ui(new Ui::digicode)
{
  ui->setupUi(this);
  int colonne=0, ligne=0;
  grille = new QGridLayout(this);
  afficheur = new QLineEdit(this);
  afficheur->setReadOnly(true);
  afficheur->setAlignment(Qt::AlignRight);
  afficheur->setEchoMode(QLineEdit::Password);
  afficheur->setMinimumHeight(80);
  grille->addWidget(afficheur,ligne,colonne,1,3);
  leBoutonPoussoir = new Bouttonpoussoir;
  LaPorte = new porte;
  // Création du clavier
  QString TableDesSymboles[4][3] = {
    {"7","8","9"},
    {"4","5","6"},
    {"1","2","3"},
    {"On","0","Ok"}
  };

  QPushButton *touches;
  for(int ligne2 = 0; ligne2 < 4; ligne2++)
    {
      for(int colonne2 = 0; colonne2 < 3; colonne2++)
        {
          touches = new QPushButton(TableDesSymboles[ligne2][colonne2]);
          touches->setMaximumWidth(80);
          touches->setMaximumHeight(80);
          touches->setStyleSheet("background-color: grey");
          grille->addWidget(touches,ligne + ligne2 + 1, colonne + colonne2);
          connect(touches,&QPushButton::clicked,this,&digicode::onQPushButton_clicked);
        }
    }

  this->setLayout(grille);
  tempoGache.setSingleShot(true);
  connect(&tempoGache,&QTimer::timeout,this,&digicode::onTimerTempoGache_timeout);
  tempoVerouillage.setSingleShot(true);
  connect(&tempoVerouillage,&QTimer::timeout,this,&digicode::onTimerTempoVerouillage_timeout);
  connect(leBoutonPoussoir,&Bouttonpoussoir::actions,this,&digicode::onBoutonPoussoirActionne); 
                                                                                                
}                                                                                              
digicode::~digicode()

{
  delete ui;
}
void digicode::onQPushButton_clicked()

{
  QPushButton *touches = qobject_cast<QPushButton *>(sender());
  qDebug() << touches->text();
  Incrementation++;
  QMessageBox porte;
  porte.setStyleSheet("QMessageBox {background-color: #808080; font-size: 36px;};");

  if(touches->text() != "Ok" && touches->text() != "On")

    {
      code += touches->text();
      afficheur->insert(touches->text());
    }
  qDebug() << code;
  qDebug() << Incrementation;
  if(code == codeSecret)
    {
      porte.setText("La porte est ouverte");
      porte.exec();
      code = "";
      Incrementation = 0;
      afficheur->clear();
    }
  else if(Incrementation == 4)

    {
      porte.setText("Mauvaise combinaison");
      porte.exec();
    }

}
void digicode::clavieractif(bool etat)
{
for (int i=0; i<4; i++){
    for(int j=0; j<3; j++){
        touches[i][j]->setEnabled(etat);

    }
}
}

void digicode::onTimerTempoGache_timeout()
{
LaPorte->verouiller();
}

void digicode::onTimerTempoVerouillage_timeout()
{
if (Incrementation < 4)
{
  this->clavieractif(true);
}
}

void digicode::onBoutonPoussoirActionne()
{
    LaPorte->show();
    LaPorte->deverouiller();
    tempoGache.start(3000);
}





