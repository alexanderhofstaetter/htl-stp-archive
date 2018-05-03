///////////////////////////////////////////////////////////////////////////////
//   mainwindow.cpp
//
//   progr. by di w.alfery
//   2009-10-02
//   version 1.0
//
///////////////////////////////////////////////////////////////////////////////


#include "mainwindow.h"
#include "grafik.h"
#include "ui_mainwindow.h"
#include <QString>
#include <math.h>


MainWindow::MainWindow(QWidget *parent): QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    NMAX = ui->scope->getN();
    samples = ui->scope->getsamples();

    for (int i=0;i<NMAX;i++)
    {  samples[i]=0;
    }
    am=0;fr=1;phi=0;
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::getAm()                         // Amplitude übernehmen
{   bool ok;

    am = QString(ui->amplitude->text()).toFloat(&ok);
    if (!ok) am = 0;
    if (am<AM_MIN) am=AM_MIN;
    if (am>AM_MAX) am=AM_MAX;

    ui->amplitude->setText(QString("%1").arg(am));
}

void MainWindow::getFre()                        // Frequenz übernehmen
{   bool ok;

    fr = QString(ui->frequenz->text()).toInt(&ok);
    if (!ok) fr = 0;
    if (fr<FR_MIN) fr=FR_MIN;
    if (fr>FR_MAX) fr=FR_MAX;

    ui->frequenz->setText(QString("%1").arg(fr));
}

void MainWindow::getPhi()                        // Phase übernehmen
{   bool ok;

    phi = QString(ui->phase->text()).toInt(&ok);
    if (!ok) phi = 0;
    if (phi<PHI_MIN) phi=PHI_MIN;
    if (phi>PHI_MAX) phi=PHI_MAX;
    ui->phase->setText(QString("%1").arg(phi));
}

void MainWindow::getSu()                         // Checkbox - Überlagerung abfragen
{
    if(ui->superCheck->isChecked()==true) su=1;
    else su=0;
}

            
void MainWindow::on_dcButton_clicked()           // DC - Samples erzeugen
{
    getAm();
    getSu();
    int i;
    for (i=0;i<NMAX;i++)
    {  samples[i]=am + su*samples[i];
    }
    ui->scope->update();
}

void MainWindow::on_exitButton_clicked()
{
    close();                                     //  Programm beenden

}

