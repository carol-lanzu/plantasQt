#ifndef NEWNEWPLANT_H
#define NEWNEWPLANT_H

#include <QWidget>

namespace Ui {
class newnewplant;
}

class newnewplant : public QWidget
{
    Q_OBJECT

public:
    explicit newnewplant(QWidget *parent = nullptr);
    ~newnewplant();

private slots:
    void on_regarNewpushButton_clicked();

private:
    Ui::newnewplant *ui;
    int estagio=0;
    int valor=0;
    bool trocarEstagio= false;
};

#endif // NEWNEWPLANT_H
