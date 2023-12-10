#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "iostream"
#define janelas_abrir 1

using namespace std;


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    //ui->ButtonNovaplanta->hide();
    plant_window = new newPlant[janelas_abrir];
    for (int i = 0; i < janelas_abrir; i++)
        plant_window[i].hide();
    ui->setupUi(this);
    ui->pushButton->setStyleSheet("QPushButton { \
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

    ui->ButtonNovaplanta->setStyleSheet("QPushButton{\
                                         border-color: rgb(0, 85, 0);\
                                         border-width: 1px;\
                                         border-style: solid;\
                                         color: rgb(0, 0, 0);\
                                         background-color: rgb(184, 255, 195);\
                                           }\
                                         QPushButton:hover {background-color: rgb(85, 170, 127);}\
                                        ");
    ui->ButtonNovaplanta->hide();
}

MainWindow::~MainWindow()
{
    delete ui;
    if (plant_window != nullptr)
        delete[] plant_window;
}

void MainWindow::closeEvent(QCloseEvent *event)
{
    if (plant_window != nullptr)
        for (int i = 0; i < janelas_abrir; i++)
            plant_window[i].close();
    QMainWindow::closeEvent(event);
}

//void MainWindow::on_PLANTA_linkActivated(const QString &link)
//{

    //ui->PLANTA->setText(Qt::green);
    //ui->PLANTA->setBackgroundRole(QPalette::Active);
//}


//QString cs1 = "QPushButton:hover {"
  //            "background-color: rgb(120, 224, 255)";
//ui->pushButton->setStyleSheet(cs1);

void MainWindow::on_pushButton_clicked()
{

    //cout<< "botao pressionado";
    //-----------------------------------arrumar estagio
    int valor = ui->progressBar->value();

    if (estagio== 0)
    {
        ui->label_2->show();
        ui->label_3->setVisible(false);
        ui->label_4->setVisible(false);
        ui->label_5->setVisible(false);
    }
    else if (estagio == 1)
    {

        if (trocarEstagio == true)
        {
            valor=0;
            trocarEstagio= false;
        }
        ui->label_3->show();
        ui->label_2->setVisible(false);
        ui->label_4->setVisible(false);
        ui->label_5->setVisible(false);
    }
    else if (estagio ==2)
    {
        if (trocarEstagio == true)
        {
            valor=0;
            trocarEstagio= false;
        }
        ui->label_4->show();
        ui->label_3->setVisible(false);
        ui->label_2->setVisible(false);
        ui->label_5->setVisible(false);
    }
    else if (estagio ==3)
        //SUPERPLANTA
    {
        if (trocarEstagio == true)
        {
            valor=0;
            trocarEstagio= false;
        }
        ui->label_5->show();
        ui->label_2->setVisible(false);
        ui->label_3->setVisible(false);
        ui->label_4->setVisible(false);

        if(valor==75)
        {
            ui->superplanta->setText("SUA PRIMEIRA PLANTA  CRESCEU SAUDAVEL!""\n"" PARABENS!" "\n" " DESEJA CRIAR MAIS UMA PLANTA?");
            ui->ButtonNovaplanta->show();
        }

    }

    //----------------------------------------arrumar label
    valor+=25;
    if (valor == 25)
    {
        ui->label->setText("AGUA AGUA!");
    }
    else if (valor == 50)
    {
        ui->label->setText("QUE SEDEE!");
    }
    else if (valor == 75)
    {
        ui->label->setText("HMMM!");
    }
    else if (valor == 100)
    {
        ui->label->setText("BEM MELHOR!");
        estagio++;
        trocarEstagio = true;
    }
    ui->progressBar->setValue(valor);

}


void MainWindow::on_ButtonNovaplanta_clicked()
{
    for (int i = 0; i < janelas_abrir; i++)
        plant_window[i].show();
}

