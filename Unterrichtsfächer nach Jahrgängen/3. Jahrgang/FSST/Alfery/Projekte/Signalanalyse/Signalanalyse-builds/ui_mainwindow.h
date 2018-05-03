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
#include <QtWidgets/QFrame>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QWidget>
#include "grafik.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionDatei_laden;
    QWidget *centralWidget;
    QFrame *frame;
    QLabel *label;
    QLabel *label_rms;
    QLabel *label_9;
    QLabel *label_10;
    QLabel *label_mittel;
    QLabel *label_ss;
    QLabel *label_3;
    QLabel *label_2;
    grafik *scope;
    QFrame *frame_2;
    QLabel *label_6;
    QLabel *label_rms_3;
    QLabel *label_13;
    QLabel *label_14;
    QLabel *label_mittel_3;
    QLabel *label_ss_3;
    QLabel *label_7;
    QLabel *label_15;
    QMenuBar *menuBar;
    QMenu *menuDatei;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(1196, 482);
        MainWindow->setMinimumSize(QSize(1196, 482));
        MainWindow->setMaximumSize(QSize(1196, 482));
        actionDatei_laden = new QAction(MainWindow);
        actionDatei_laden->setObjectName(QStringLiteral("actionDatei_laden"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        frame = new QFrame(centralWidget);
        frame->setObjectName(QStringLiteral("frame"));
        frame->setGeometry(QRect(1030, 100, 151, 111));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        label = new QLabel(frame);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(10, 30, 41, 16));
        label_rms = new QLabel(frame);
        label_rms->setObjectName(QStringLiteral("label_rms"));
        label_rms->setGeometry(QRect(60, 30, 61, 16));
        label_9 = new QLabel(frame);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setGeometry(QRect(10, 50, 41, 16));
        label_10 = new QLabel(frame);
        label_10->setObjectName(QStringLiteral("label_10"));
        label_10->setGeometry(QRect(10, 70, 41, 16));
        label_mittel = new QLabel(frame);
        label_mittel->setObjectName(QStringLiteral("label_mittel"));
        label_mittel->setGeometry(QRect(60, 50, 61, 16));
        label_ss = new QLabel(frame);
        label_ss->setObjectName(QStringLiteral("label_ss"));
        label_ss->setGeometry(QRect(60, 70, 61, 20));
        label_3 = new QLabel(frame);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(10, 10, 71, 16));
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(10, 570, 1011, 32));
        scope = new grafik(centralWidget);
        scope->setObjectName(QStringLiteral("scope"));
        scope->setGeometry(QRect(20, 20, 1001, 411));
        scope->setStyleSheet(QStringLiteral("background-color: rgb(255, 255, 255);"));
        frame_2 = new QFrame(centralWidget);
        frame_2->setObjectName(QStringLiteral("frame_2"));
        frame_2->setGeometry(QRect(1030, 220, 151, 111));
        frame_2->setFrameShape(QFrame::StyledPanel);
        frame_2->setFrameShadow(QFrame::Raised);
        label_6 = new QLabel(frame_2);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(10, 30, 41, 16));
        label_rms_3 = new QLabel(frame_2);
        label_rms_3->setObjectName(QStringLiteral("label_rms_3"));
        label_rms_3->setGeometry(QRect(60, 30, 61, 16));
        label_13 = new QLabel(frame_2);
        label_13->setObjectName(QStringLiteral("label_13"));
        label_13->setGeometry(QRect(10, 50, 41, 16));
        label_14 = new QLabel(frame_2);
        label_14->setObjectName(QStringLiteral("label_14"));
        label_14->setGeometry(QRect(10, 70, 41, 16));
        label_mittel_3 = new QLabel(frame_2);
        label_mittel_3->setObjectName(QStringLiteral("label_mittel_3"));
        label_mittel_3->setGeometry(QRect(60, 50, 61, 16));
        label_ss_3 = new QLabel(frame_2);
        label_ss_3->setObjectName(QStringLiteral("label_ss_3"));
        label_ss_3->setGeometry(QRect(60, 70, 61, 20));
        label_7 = new QLabel(frame_2);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(10, 10, 71, 16));
        label_15 = new QLabel(centralWidget);
        label_15->setObjectName(QStringLiteral("label_15"));
        label_15->setGeometry(QRect(20, 440, 701, 16));
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1196, 21));
        menuDatei = new QMenu(menuBar);
        menuDatei->setObjectName(QStringLiteral("menuDatei"));
        MainWindow->setMenuBar(menuBar);

        menuBar->addAction(menuDatei->menuAction());
        menuDatei->addAction(actionDatei_laden);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Signalanalyse", 0));
        actionDatei_laden->setText(QApplication::translate("MainWindow", "Datei laden", 0));
        label->setText(QApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:10pt; font-weight:600;\">RMS:</span></p></body></html>", 0));
        label_rms->setText(QApplication::translate("MainWindow", "<html><head/><body><p align=\"center\"><span style=\" font-size:10pt;\">-</span></p></body></html>", 0));
        label_9->setText(QApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:10pt; font-weight:600;\">Mittel:</span></p></body></html>", 0));
        label_10->setText(QApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:10pt; font-weight:600;\">SS:</span></p></body></html>", 0));
        label_mittel->setText(QApplication::translate("MainWindow", "<html><head/><body><p align=\"center\"><span style=\" font-size:10pt;\">-</span></p></body></html>", 0));
        label_ss->setText(QApplication::translate("MainWindow", "<html><head/><body><p align=\"center\"><span style=\" font-size:10pt;\">-</span></p></body></html>", 0));
        label_3->setText(QApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:10pt; font-weight:600; color:#0000ff;\">Kanal 1</span></p></body></html>", 0));
        label_2->setText(QApplication::translate("MainWindow", "<html><head/><body><p><br/></p></body></html>", 0));
        label_6->setText(QApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:10pt; font-weight:600;\">RMS:</span></p></body></html>", 0));
        label_rms_3->setText(QApplication::translate("MainWindow", "<html><head/><body><p align=\"center\"><span style=\" font-size:10pt;\">-</span></p></body></html>", 0));
        label_13->setText(QApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:10pt; font-weight:600;\">Mittel:</span></p></body></html>", 0));
        label_14->setText(QApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:10pt; font-weight:600;\">SS:</span></p></body></html>", 0));
        label_mittel_3->setText(QApplication::translate("MainWindow", "<html><head/><body><p align=\"center\"><span style=\" font-size:10pt;\">-</span></p></body></html>", 0));
        label_ss_3->setText(QApplication::translate("MainWindow", "<html><head/><body><p align=\"center\"><span style=\" font-size:10pt;\">-</span></p></body></html>", 0));
        label_7->setText(QApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:10pt; font-weight:600; color:#ff0000;\">Kanal 2</span></p></body></html>", 0));
        label_15->setText(QString());
        menuDatei->setTitle(QApplication::translate("MainWindow", "Datei", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
