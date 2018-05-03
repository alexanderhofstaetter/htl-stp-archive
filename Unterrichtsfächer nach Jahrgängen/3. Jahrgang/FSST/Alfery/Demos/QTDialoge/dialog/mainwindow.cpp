/////////////////////////////////////////////////////////////////////////////////////////////
//   Program : main.cpp
//
//
//
/////////////////////////////////////////////////////////////////////////////////////////////


#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFileDialog>
#include <QMessageBox>
#include <QInputDialog>
#include <QColor>
#include <QColorDialog>
#include <QFont>
#include <QFontDialog>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_FileOpenButton_clicked()
{
   QString filename;
   QFileDialog fd;                                           // Dateidialog instanzieren

   // File Dialog öffnen
   filename= fd.getOpenFileName(this,
                      "Open File ",                          // Beschriftung
                      "./",                                  // Startverzeichnis
                      " Open Files (*.*)");                  // Dateifilter


   // zur Anzeige ins Textfeld ausgeben
   ui->textEdit->setText(filename);



}

void MainWindow::on_FileSaveAsButton_clicked()
{  QString filename;
   QFileDialog fd;                                           // Dateidialog instanzieren

   // File Dialog öffnen
   filename = fd.getSaveFileName(this,                       // eigenes Fenster
                      tr("Save File"),                       // Beschriftung / tr -> international multiple language support
                      "./",                                  // Startverzeichnis
                      tr(" Save as (*.txt *.cpp )"));        // Dateifilter

   // zur Anzeige ins Textfeld ausgeben
   ui->textEdit->setText(filename);

}



void MainWindow::on_MessageButton_clicked()
{
    QMessageBox mb;                                          // Meldungsfenster instanzieren

    mb.information(this,
                   tr("Meldung"),                            // Fenstertitel
                   tr(" Fehler !"));                         // Meldung

}

void MainWindow::on_InputBox_clicked()
{
    bool ok;
    QString text;
    QInputDialog id;                                         // Eingabedialog instanzieren

    text= id.getText(this,
               tr(" Eingabe Dialog "),                       // Fenstertitel
               tr("User name:"),                             // Eingabe Beschriftung
               QLineEdit::Normal,                            // Eingabe Optionen
               tr(" Eingabe "),                              // Text
               &ok);                                         // OK Button

    ui->textEdit->setText(text);

}

void MainWindow::on_ColorDialogButton_clicked()
{
    QColor color;
    QColorDialog cd;                                         // Farbdialog instanzieren

    color = cd.getColor(Qt::white,this);

    ui->textEdit->setText(color.name());

}


void MainWindow::on_FontDialogButton_clicked()
{
    bool ok;
    QFont font;
    QFontDialog fd;                                          // Schriftdialog instanzieren
    QString style;

    font=fd.getFont(&ok,
                    QFont("Helvetica [Cronyx]",10),
                    this);

    if (ok)                                                  // Dialog mit OK beendet
    {   style = font.toString();
        ui->textEdit->setText(style);
    } else
    {   ui->textEdit->setText(" Abbruch ");
    }

}


void MainWindow::on_exitButton_clicked()
{
    exit(0);                                                 // Programm Ende
}



