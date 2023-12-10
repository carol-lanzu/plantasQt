#include "newplant.h"
#include "ui_newplant.h"
#include "iostream"
#define janelas_abrir 2

newPlant::newPlant(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::newPlant)
{
    ui->setupUi(this);
    ui->regarNewpushButton->setStyleSheet("QPushButton { \
                             color: rgb(0, 0, 127); \
                             background-color: rgb(161, 246, 255); \
                             background-color: rgb(120, 224, 255); \
                             border-radius: 20px; \
                             border-width: 1px; \
                             border-style: solid; \
                             } \
                             QPushButton:hover {background-color: rgb(0, 85, 127);}\
                             \
                             ");
    ui->ButtonNovaPlanta->setStyleSheet("QPushButton{\
                                         border-color: rgb(0, 85, 0);\
                                         border-width: 1px;\
                                         border-style: solid;\
                                         color: rgb(0, 0, 0);\
                                         background-color: rgb(184, 255, 195);\
                                           }\
                                         QPushButton:hover {background-color: rgb(85, 170, 127);}\
                                        ");
    ui->ButtonNovaPlanta->hide();
}

newPlant::~newPlant()
{
    delete ui;
    if (this->plant_window!= nullptr)
    {
        delete[] plant_window;
    }
}



void newPlant::on_regarNewpushButton_clicked()
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
        if(valor>75)
        {
            ui->superplanta->setText("SUA PRIMEIRA""\n""PLANTA CRESCEU""\n""SAUDAVEL!""\n""PARABENS!" "\n" "DESEJA CRIAR""\n""MAIS UMA""\n""PLANTA?");
            ui->ButtonNovaPlanta->show();
        }

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


void newPlant::on_ButtonNovaPlanta_clicked()
{
    plant_window = new newPlant[janelas_abrir];
    for (int i = 0; i < janelas_abrir; i++)
        plant_window[i].show();
}

