#ifndef digicode_H
#define digicode_H
#include <QWidget>
#include <QGridLayout>
#include <QLineEdit>
#include <QPushButton>
#include <QMessageBox>
#include <QTimer>
#include "porte.h"
#include "bouttonpoussoir.h"

QT_BEGIN_NAMESPACE

namespace Ui { class digicode; }

QT_END_NAMESPACE


class digicode : public QWidget
{

  Q_OBJECT

public:
  digicode(QWidget *parent = nullptr);
  ~digicode();

private slots:

  void onQPushButton_clicked();
  void onTimerTempoGache_timeout();
  void onTimerTempoVerouillage_timeout();
  void onBoutonPoussoirActionne();


private:

  Ui::digicode *ui;
  QPushButton *touches[4][3];
  QGridLayout *grille;
  QLineEdit *afficheur;
  QString code;
  QString codeSecret = "1234";
  int Incrementation = 0;
  QTimer tempoGache;
  QTimer tempoVerouillage;
  porte *LaPorte;
  Bouttonpoussoir *leBoutonPoussoir;
  void clavieractif (bool etat);

};

#endif // digicode_H


