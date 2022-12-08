#ifndef BOUTTONPOUSSOIR_H
#define BOUTTONPOUSSOIR_H

#include <QWidget>

namespace Ui {
class Bouttonpoussoir;
}

class Bouttonpoussoir : public QWidget
{
    Q_OBJECT

public:
    explicit Bouttonpoussoir(QWidget *parent = nullptr);
    ~Bouttonpoussoir();

private:
    Ui::Bouttonpoussoir *ui;
private slots:
  void on_PushButtonBP_clicked();

signals:
  void action();
};

#endif // BOUTTONPOUSSOIR_H
