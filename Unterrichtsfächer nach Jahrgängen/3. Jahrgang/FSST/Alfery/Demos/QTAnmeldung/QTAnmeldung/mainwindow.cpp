/////////////////////////////////////////////////////////////////////////////////////////////
//   Program : mainwindow.cpp
//
//   w.alfery
//   Demo zu Widgets
//
/////////////////////////////////////////////////////////////////////////////////////////////

#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFile>
#include <QTextStream>
#include <QDate>
#include <QEventLoop>
#include <QTimer>


MainWindow::MainWindow(QWidget *parent) :                  // Konstruktor
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->dateEdit->setDate(QDate::currentDate());           // aktuelles Datum einstellen

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_anmeldeButton_clicked()                // Anmeldung
{
    QDate datum;
    int kursindex;
    QString geschlecht;
    int neueDatei;

    // Daten auf Datei schreiben
    QFile datei("anmeldeDaten.txt");                       // File Objekt anlegen
    QTextStream out(&datei);                               // Stream auf Textdatei

    if (datei.exists())                                    // Datei bereits vorhanden ?
    {  ui->statusLabel->setText("  auf existierende Datei schreiben ");
       neueDatei=0;
    }
    else
    {  ui->statusLabel->setText("  Datei neu angelegen ");
       neueDatei=1;
    }

    MainWindow::sleep(1000);                               // 1s warten

    if (!datei.open(QIODevice::Append))                    // Datei anhängend schreiben öffnen
    {  ui->statusLabel->setText("  Datei Fehler  ");
       return;
    }
    else
    {
       ui->statusLabel->setText("   speichern ...  ");     // Status Anzeige

       // bei neuangelegter Datei den CSV-Kopf schreiben
       if (neueDatei)
       {  out << "Name; Vorname; Adresse;PLZ; Alter; Geschlecht; Kurs; Datum  " << endl;
       }

       // Anmeldedaten auf Datei schreiben
       // CSV-Daten schreiben
       out << ui->nameEdit->text()<<"; ";                  // Name speichern
       out << ui->vornameEdit->text()<<"; ";               // Vorname speichern
       out << ui->adressEdit->text()<<"; ";                //  ...
       out << ui->plzEdit->text()<<"; ";
       out << ui->alterEdit->text()<<"; ";
       if ( ui->radioMann->isChecked() )                   // Geschlecht abfragen
            geschlecht = " männlich ";                     //
       else geschlecht = " weiblich ";
       out << geschlecht<<"; ";                            // und speichern
       kursindex = ui->comboBox->currentIndex();           // gewählten Kurs abfragen
       out << ui->comboBox->itemText(kursindex)<<"; ";     // und speichern
       datum = ui->dateEdit->date();                       // Datum übernehmen
       out << datum.toString(" dd-MM-yyyy ")<<"; ";        // und als Text formatiert speichern
       out << endl;

       datei.close();                                      // Datei schließen

       MainWindow::sleep(1000);                            // 1s warten
       ui->statusLabel->setText("  abgeschlossen   ");     // Status Anzeige

    }
}


void MainWindow::on_resetButton_clicked()                  // Reset
{
       ui->statusLabel->setText ("   Eingaben löschen  ");

       ui->nameEdit->clear();                              // alle Eingabefelder löschen und zurücksetzen
       ui->vornameEdit->clear();
       ui->adressEdit->clear();
       ui->plzEdit->clear();
       ui->alterEdit->clear();
       ui->radioFrau->click();
       ui->comboBox->setCurrentIndex(0);
       ui->dateEdit->setDate(QDate::currentDate());

       MainWindow::sleep(1000);                            // 1s warten
       ui->statusLabel->setText("  abgeschlossen   ");     // Status Anzeige

   }


void MainWindow::on_quitButton_clicked()                   // Quit
{
    exit(0);                                               // Programm exit
}


void MainWindow::sleep(int ms)                             // Hilfsmethode sleep
{
    QEventLoop loop;
    QTimer::singleShot(ms, &loop, SLOT(quit()));
    loop.exec();
}
