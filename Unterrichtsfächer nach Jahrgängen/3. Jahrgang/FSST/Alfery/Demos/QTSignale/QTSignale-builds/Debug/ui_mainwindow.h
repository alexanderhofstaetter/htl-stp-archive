/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>
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
    QGraphicsView *graphicsView;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(700, 400);
        MainWindow->setAutoFillBackground(false);
        MainWindow->setStyleSheet(QStringLiteral("background-color: rgb(234, 247, 255);"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(230, 10, 241, 21));
        QFont font;
        font.setPointSize(11);
        font.setBold(true);
        font.setWeight(75);
        label->setFont(font);
        label->setStyleSheet(QStringLiteral("color: rgb(85, 85, 127);"));
        label->setAlignment(Qt::AlignCenter);
        dcButton = new QPushButton(centralWidget);
        dcButton->setObjectName(QStringLiteral("dcButton"));
        dcButton->setGeometry(QRect(570, 50, 91, 31));
        QFont font1;
        font1.setBold(true);
        font1.setWeight(75);
        dcButton->setFont(font1);
        sinusButton = new QPushButton(centralWidget);
        sinusButton->setObjectName(QStringLiteral("sinusButton"));
        sinusButton->setGeometry(QRect(570, 80, 91, 31));
        sinusButton->setFont(font1);
        rectButton = new QPushButton(centralWidget);
        rectButton->setObjectName(QStringLiteral("rectButton"));
        rectButton->setGeometry(QRect(570, 110, 91, 31));
        rectButton->setFont(font1);
        rampButton = new QPushButton(centralWidget);
        rampButton->setObjectName(QStringLiteral("rampButton"));
        rampButton->setGeometry(QRect(570, 140, 91, 31));
        rampButton->setFont(font1);
        noiseButton = new QPushButton(centralWidget);
        noiseButton->setObjectName(QStringLiteral("noiseButton"));
        noiseButton->setGeometry(QRect(570, 170, 91, 31));
        noiseButton->setFont(font1);
        resetButton = new QPushButton(centralWidget);
        resetButton->setObjectName(QStringLiteral("resetButton"));
        resetButton->setGeometry(QRect(570, 220, 91, 31));
        resetButton->setFont(font1);
        exitButton = new QPushButton(centralWidget);
        exitButton->setObjectName(QStringLiteral("exitButton"));
        exitButton->setGeometry(QRect(570, 300, 91, 41));
        exitButton->setFont(font1);
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(30, 280, 81, 21));
        label_2->setFont(font1);
        label_5 = new QLabel(centralWidget);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(30, 300, 81, 21));
        label_5->setFont(font1);
        label_3 = new QLabel(centralWidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(30, 320, 81, 21));
        label_3->setFont(font1);
        amplitude = new QLineEdit(centralWidget);
        amplitude->setObjectName(QStringLiteral("amplitude"));
        amplitude->setGeometry(QRect(120, 280, 113, 20));
        amplitude->setStyleSheet(QStringLiteral("background-color: rgb(255, 255, 255);"));
        frequenz = new QLineEdit(centralWidget);
        frequenz->setObjectName(QStringLiteral("frequenz"));
        frequenz->setGeometry(QRect(120, 300, 113, 20));
        frequenz->setStyleSheet(QStringLiteral("background-color: rgb(255, 255, 255);"));
        phase = new QLineEdit(centralWidget);
        phase->setObjectName(QStringLiteral("phase"));
        phase->setGeometry(QRect(120, 320, 113, 20));
        phase->setStyleSheet(QStringLiteral("background-color: rgb(255, 255, 255);"));
        superCheck = new QCheckBox(centralWidget);
        superCheck->setObjectName(QStringLiteral("superCheck"));
        superCheck->setGeometry(QRect(310, 280, 171, 18));
        superCheck->setFont(font1);
        scope = new grafik(centralWidget);
        scope->setObjectName(QStringLiteral("scope"));
        scope->setGeometry(QRect(30, 50, 500, 200));
        scope->setStyleSheet(QStringLiteral("background-color: rgb(255, 255, 255);"));
        graphicsView = new QGraphicsView(centralWidget);
        graphicsView->setObjectName(QStringLiteral("graphicsView"));
        graphicsView->setGeometry(QRect(310, 330, 256, 192));
        MainWindow->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QString());
        label->setText(QApplication::translate("MainWindow", "Signalgenerator", 0));
        dcButton->setText(QApplication::translate("MainWindow", "&DC", 0));
        sinusButton->setText(QApplication::translate("MainWindow", "S&inus", 0));
        rectButton->setText(QApplication::translate("MainWindow", "R&echteck", 0));
        rampButton->setText(QApplication::translate("MainWindow", "R&ampe", 0));
        noiseButton->setText(QApplication::translate("MainWindow", "Ra&uschen", 0));
        resetButton->setText(QApplication::translate("MainWindow", "&Reset", 0));
        exitButton->setText(QApplication::translate("MainWindow", "&Exit", 0));
        label_2->setText(QApplication::translate("MainWindow", "Amplitude", 0));
        label_5->setText(QApplication::translate("MainWindow", "Frequenz", 0));
        label_3->setText(QApplication::translate("MainWindow", "Phase", 0));
        superCheck->setText(QApplication::translate("MainWindow", "\303\234berlagerung", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
