//////////////////////////////////
// Autor:      Hofstätter
//////////////////////////////////

#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent),ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    x = 0;                      //operation = 0
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_plusButton_clicked()
{
    QString input;

    input = ui->display->text();
    x = input.toDouble();
    operation = 1;              //Operand 1 übernehmen für Addition

    ui->display->setText("");   //Display löschen
    ui->display->setFocus();    //Cursor auf Display
    ui->display->selectAll();   //Text im Display auswählen

}

void MainWindow::on_minusButton_clicked()
{
    QString input;

    input = ui->display->text();
    x = input.toDouble();
    operation = 2;              //Operand 2 übernehmen für Subtraktion

    ui->display->setText("");   //Display löschen
    ui->display->setFocus();    //Cursor auf Display
    ui->display->selectAll();   //Text im Display auswählen
}

void MainWindow::on_multiplyButton_clicked()
{
    QString input;

    input = ui->display->text();
    x = input.toDouble();
    operation = 3;              //Operand 2 übernehmen für Subtraktion

    ui->display->setText("");   //Display löschen
    ui->display->setFocus();    //Cursor auf Display
    ui->display->selectAll();   //Text im Display auswählen
}

void MainWindow::on_divideButton_clicked()
{
    QString input;

    input = ui->display->text();
    x = input.toDouble();
    operation = 4;              //Operand 2 übernehmen für Subtraktion

    ui->display->setText("");   //Display löschen
    ui->display->setFocus();    //Cursor auf Display
    ui->display->selectAll();   //Text im Display auswählen
}

void MainWindow::on_equalsButton_clicked()
{
    QString input;
    QString output;

    input = ui->display->text();
    switch(operation)
    {
        case 1:
        x += input.toDouble();  //Operation + ausführen
        break;

        case 2:
        x -= input.toDouble();
        break;

        case 3:
        x *= input.toDouble();
        break;

        case 4:
        x /= input.toDouble();
        break;
    }
    output = QString().number(x);

    ui->display->setFocus();                //Cursor auf Eingabefeld setzen
    ui->display->selectAll();               //Text im Display auswählen
    ui->display->setText(output);           //ergebnis anzeigen

}

void MainWindow::on_clearButton_clicked()
{
    ui->display->setText("");   //Display löschen
}
