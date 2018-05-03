/********************************************************************************
** Form generated from reading ui file 'mainwindow.ui'
**
** Created: Wed 9. Dec 22:11:44 2009
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
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
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
    QPushButton *nincButton;
    grafik *zeichenbereich;
    QPushButton *quitButton;
    QLabel *label;
    QPushButton *ndecButton;
    QLabel *NLabel;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(476, 341);
        MainWindow->setAutoFillBackground(false);
        MainWindow->setStyleSheet(QString::fromUtf8("background-color: rgb(234, 247, 255);"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        nincButton = new QPushButton(centralWidget);
        nincButton->setObjectName(QString::fromUtf8("nincButton"));
        nincButton->setGeometry(QRect(240, 280, 31, 31));
        QFont font;
        font.setBold(true);
        font.setWeight(75);
        nincButton->setFont(font);
        zeichenbereich = new grafik(centralWidget);
        zeichenbereich->setObjectName(QString::fromUtf8("zeichenbereich"));
        zeichenbereich->setGeometry(QRect(25, 25, 425, 225));
        zeichenbereich->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        quitButton = new QPushButton(centralWidget);
        quitButton->setObjectName(QString::fromUtf8("quitButton"));
        quitButton->setGeometry(QRect(360, 280, 91, 31));
        quitButton->setFont(font);
        label = new QLabel(centralWidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(30, 280, 141, 31));
        QFont font1;
        font1.setPointSize(9);
        font1.setBold(false);
        font1.setWeight(50);
        label->setFont(font1);
        ndecButton = new QPushButton(centralWidget);
        ndecButton->setObjectName(QString::fromUtf8("ndecButton"));
        ndecButton->setGeometry(QRect(280, 280, 31, 31));
        ndecButton->setFont(font);
        NLabel = new QLabel(centralWidget);
        NLabel->setObjectName(QString::fromUtf8("NLabel"));
        NLabel->setGeometry(QRect(180, 280, 41, 31));
        NLabel->setFont(font1);
        MainWindow->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Grafik", 0, QApplication::UnicodeUTF8));
        nincButton->setText(QApplication::translate("MainWindow", "+", 0, QApplication::UnicodeUTF8));
        quitButton->setText(QApplication::translate("MainWindow", "&Quit", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("MainWindow", "Anzahl der Oberwellen = ", 0, QApplication::UnicodeUTF8));
        ndecButton->setText(QApplication::translate("MainWindow", "-", 0, QApplication::UnicodeUTF8));
        NLabel->setText(QApplication::translate("MainWindow", "1", 0, QApplication::UnicodeUTF8));
        Q_UNUSED(MainWindow);
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
