#ifndef NEWPLANT_H
#define NEWPLANT_H

#include <QWidget>
//#include "newnewplant.h"

namespace Ui {
class newPlant;
}

class newPlant : public QWidget
{
    Q_OBJECT

public:
    explicit newPlant(QWidget *parent = nullptr);
    ~newPlant();

private slots:
    void on_regarNewpushButton_clicked();

    void on_ButtonNovaPlanta_clicked();

private:
    Ui::newPlant *ui;
    int estagio=0;
    int valor=0;
    bool trocarEstagio= false;
    newPlant* plant_window = nullptr; //criar mais janelas
};

#endif // NEWPLANT_H
