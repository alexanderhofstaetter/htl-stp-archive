/********************************************************************************
** Form generated from reading ui file 'mainwindow.ui'
**
** Created: Mon 21. Dec 20:07:19 2009
**      by: Qt User Interface Compiler version 4.5.1
**
** WARNING! All changes made in this file will be lost when recompiling ui file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QCheckBox>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QMainWindow>
#include <QtGui/QPushButton>
#include <QtGui/QStatusBar>
#include <QtGui/QWidget>
#include "grafik.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QLabel *label;
    QPushButton *dcButton;
    QPushButton *sinusButton;
    QPushButton *rectButton;
    QPushButton *rampButton;
    QPushButton *noiseButton;
    QPushButton *resetButton;
    QPushButton *exitButton;
    QLabel *label_2;
    QLabel *label_5;
    QLabel *label_3;
    QLineEdit *amplitude;
    QLineEdit *frequenz;
    QLineEdit *phase;
    QCheckBox *superCheck;
    grafik *scope;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(700, 400);
        MainWindow->setAutoFillBackground(false);
        MainWindow->setStyleSheet(QString::fromUtf8("background-color: rgb(234, 247, 255);"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        label = new QLabel(centralWidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(230, 10, 241, 21));
        QFont font;
        font.setPointSize(11);
        font.setBold(true);
        font.setWeight(75);
        label->setFont(font);
        label->setStyleSheet(QString::fromUtf8("color: rgb(85, 85, 127);"));
        label->setAlignment(Qt::AlignCenter);
        dcButton = new QPushButton(centralWidget);
        dcButton->setObjectName(QString::fromUtf8("dcButton"));
        dcButton->setGeometry(QRect(570, 50, 91, 31));
        QFont font1;
        font1.setBold(true);
        font1.setWeight(75);
        dcButton->setFont(font1);
        sinusButton = new QPushButton(centralWidget);
        sinusButton->setObjectName(QString::fromUtf8("sinusButton"));
        sinusButton->setGeometry(QRect(570, 80, 91, 31));
        sinusButton->setFont(font1);
        rectButton = new QPushButton(centralWidget);
        rectButton->setObjectName(QString::fromUtf8("rectButton"));
        rectButton->setGeometry(QRect(570, 110, 91, 31));
        rectButton->setFont(font1);
        rampButton = new QPushButton(centralWidget);
        rampButton->setObjectName(QString::fromUtf8("rampButton"));
        rampButton->setGeometry(QRect(570, 140, 91, 31));
        rampButton->setFont(font1);
        noiseButton = new QPushButton(centralWidget);
        noiseButton->setObjectName(QString::fromUtf8("noiseButton"));
        noiseButton->setGeometry(QRect(570, 170, 91, 31));
        noiseButton->setFont(font1);
        resetButton = new QPushButton(centralWidget);
        resetButton->setObjectName(QString::fromUtf8("resetButton"));
        resetButton->setGeometry(QRect(570, 220, 91, 31));
        resetButton->setFont(font1);
        exitButton = new QPushButton(centralWidget);
        exitButton->setObjectName(QString::fromUtf8("exitButton"));
        exitButton->setGeometry(QRect(570, 300, 91, 41));
        exitButton->setFont(font1);
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(30, 280, 81, 21));
        label_2->setFont(font1);
        label_5 = new QLabel(centralWidget);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(30, 300, 81, 21));
        label_5->setFont(font1);
        label_3 = new QLabel(centralWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(30, 320, 81, 21));
        label_3->setFont(font1);
        amplitude = new QLineEdit(centralWidget);
        amplitude->setObjectName(QString::fromUtf8("amplitude"));
        amplitude->setGeometry(QRect(120, 280, 113, 20));
        amplitude->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        frequenz = new QLineEdit(centralWidget);
        frequenz->setObjectName(QString::fromUtf8("frequenz"));
        frequenz->setGeometry(QRect(120, 300, 113, 20));
        frequenz->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        phase = new QLineEdit(centralWidget);
        phase->setObjectName(QString::fromUtf8("phase"));
        phase->setGeometry(QRect(120, 320, 113, 20));
        phase->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        superCheck = new QCheckBox(centralWidget);
        superCheck->setObjectName(QString::fromUtf8("superCheck"));
        superCheck->setGeometry(QRect(310, 280, 171, 18));
        superCheck->setFont(font1);
        scope = new grafik(centralWidget);
        scope->setObjectName(QString::fromUtf8("scope"));
        scope->setGeometry(QRect(30, 50, 500, 200));
        scope->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        MainWindow->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QString());
        label->setText(QApplication::translate("MainWindow", "Signalgenerator", 0, QApplication::UnicodeUTF8));
        dcButton->setText(QApplication::translate("MainWindow", "&DC", 0, QApplication::UnicodeUTF8));
        sinusButton->setText(QApplication::translate("MainWindow", "S&inus", 0, QApplication::UnicodeUTF8));
        rectButton->setText(QApplication::translate("MainWindow", "R&echteck", 0, QApplication::UnicodeUTF8));
        rampButton->setText(QApplication::translate("MainWindow", "R&ampe", 0, QApplication::UnicodeUTF8));
        noiseButton->setText(QApplication::translate("MainWindow", "Ra&uschen", 0, QApplication::UnicodeUTF8));
        resetButton->setText(QApplication::translate("MainWindow", "&Reset", 0, QApplication::UnicodeUTF8));
        exitButton->setText(QApplication::translate("MainWindow", "&Exit", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("MainWindow", "Amplitude", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("MainWindow", "Frequenz", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("MainWindow", "Phase", 0, QApplication::UnicodeUTF8));
        superCheck->setText(QApplication::translate("MainWindow", "\303\234berlagerung", 0, QApplication::UnicodeUTF8));
        Q_UNUSED(MainWindow);
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
