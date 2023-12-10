#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "newplant.h"
#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void closeEvent(QCloseEvent *event);
private slots:
    //void on_PLANTA_linkActivated(const QString &link);



    void on_pushButton_clicked();

    void on_ButtonNovaplanta_clicked();

private:
    Ui::MainWindow *ui;
    int estagio= 0;
    bool trocarEstagio = false;
    newPlant* plant_window = nullptr; //criar mais janelas

};
#endif // MAINWINDOW_H
