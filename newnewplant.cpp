#include "newnewplant.h"
#include "ui_newnewplant.h"

newnewplant::newnewplant(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::newnewplant)
{
    ui->setupUi(this);
}


void newnewplant::on_regarNewpushButton_clicked()
{
    int valor = ui->progressBarNew->value();
    valor+=25;
    if (estagio==0)
    {

        if (trocarEstagio == true)
        {
            valor=0;
            trocarEstagio= false;
        }
        ui->estagioNew->setText("BROTO");
    }
    else if (estagio==1)
    {
        if (trocarEstagio == true)
        {
            valor=0;
            trocarEstagio= false;
        }
        ui->estagioNew->setText("TAM MEDIO");

    }
    else if (estagio==2)
    {
        if (trocarEstagio == true)
        {
            valor=0;
            trocarEstagio= false;
        }
        ui->estagioNew->setText("TAM GRANDE");

    }
    else if(estagio==3)
    {
        if (trocarEstagio == true)
        {
            valor=0;
            trocarEstagio= false;
        }
        ui->estagioNew->setText("SUPERPLANTA");
    }
    //-------------------------------------setar tamanho
    if (valor == 25)
    {
        ui->label_2->setText("AGUA AGUA!");
    }
    else if (valor == 50)
    {
        ui->label_2->setText("QUE SEDEE!");
    }
    else if (valor == 75)
    {
        ui->label_2->setText("HMMM!");
    }
    else if (valor == 100)
    {
        ui->label_2->setText("BEM MELHOR!");
        estagio++;
        trocarEstagio = true;
    }
    ui->progressBarNew->setValue(valor);

}

newnewplant::~newnewplant()
{
    delete ui;
}
