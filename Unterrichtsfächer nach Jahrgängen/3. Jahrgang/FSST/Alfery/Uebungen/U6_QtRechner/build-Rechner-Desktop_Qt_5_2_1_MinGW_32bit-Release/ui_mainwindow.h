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
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionStandard;
    QAction *actionWissenschaftlich;
    QAction *actionHTL;
    QWidget *centralWidget;
    QPushButton *minusButton;
    QLineEdit *display;
    QPushButton *multiplyButton;
    QPushButton *clearButton;
    QPushButton *plusButton;
    QPushButton *equalsButton;
    QPushButton *divideButton;
    QToolButton *toolButton;
    QStatusBar *statusBar;
    QMenuBar *menuBar;
    QMenu *menuAnsicht;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(438, 477);
        QPalette palette;
        QBrush brush(QColor(199, 207, 232, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Button, brush);
        QBrush brush1(QColor(255, 255, 255, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Base, brush1);
        QBrush brush2(QColor(203, 213, 232, 255));
        brush2.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Window, brush2);
        palette.setBrush(QPalette::Inactive, QPalette::Button, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Base, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Window, brush2);
        palette.setBrush(QPalette::Disabled, QPalette::Button, brush);
        palette.setBrush(QPalette::Disabled, QPalette::Base, brush2);
        palette.setBrush(QPalette::Disabled, QPalette::Window, brush2);
        MainWindow->setPalette(palette);
        actionStandard = new QAction(MainWindow);
        actionStandard->setObjectName(QStringLiteral("actionStandard"));
        actionWissenschaftlich = new QAction(MainWindow);
        actionWissenschaftlich->setObjectName(QStringLiteral("actionWissenschaftlich"));
        actionHTL = new QAction(MainWindow);
        actionHTL->setObjectName(QStringLiteral("actionHTL"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        minusButton = new QPushButton(centralWidget);
        minusButton->setObjectName(QStringLiteral("minusButton"));
        minusButton->setGeometry(QRect(70, 60, 31, 31));
        display = new QLineEdit(centralWidget);
        display->setObjectName(QStringLiteral("display"));
        display->setGeometry(QRect(30, 20, 311, 21));
        QFont font;
        font.setFamily(QStringLiteral("Calibri"));
        font.setPointSize(13);
        display->setFont(font);
        multiplyButton = new QPushButton(centralWidget);
        multiplyButton->setObjectName(QStringLiteral("multiplyButton"));
        multiplyButton->setGeometry(QRect(130, 60, 31, 31));
        clearButton = new QPushButton(centralWidget);
        clearButton->setObjectName(QStringLiteral("clearButton"));
        clearButton->setGeometry(QRect(240, 60, 101, 41));
        plusButton = new QPushButton(centralWidget);
        plusButton->setObjectName(QStringLiteral("plusButton"));
        plusButton->setGeometry(QRect(30, 60, 31, 31));
        QPalette palette1;
        QBrush brush3(QColor(195, 200, 209, 255));
        brush3.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Active, QPalette::AlternateBase, brush3);
        palette1.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush3);
        palette1.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush3);
        plusButton->setPalette(palette1);
        equalsButton = new QPushButton(centralWidget);
        equalsButton->setObjectName(QStringLiteral("equalsButton"));
        equalsButton->setGeometry(QRect(240, 110, 101, 41));
        divideButton = new QPushButton(centralWidget);
        divideButton->setObjectName(QStringLiteral("divideButton"));
        divideButton->setGeometry(QRect(180, 60, 31, 31));
        toolButton = new QToolButton(centralWidget);
        toolButton->setObjectName(QStringLiteral("toolButton"));
        toolButton->setGeometry(QRect(190, 110, 25, 19));
        MainWindow->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 438, 21));
        menuAnsicht = new QMenu(menuBar);
        menuAnsicht->setObjectName(QStringLiteral("menuAnsicht"));
        MainWindow->setMenuBar(menuBar);

        menuBar->addAction(menuAnsicht->menuAction());
        menuAnsicht->addAction(actionStandard);
        menuAnsicht->addAction(actionWissenschaftlich);
        menuAnsicht->addAction(actionHTL);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Taschenrechner", 0));
        actionStandard->setText(QApplication::translate("MainWindow", "Standard", 0));
        actionWissenschaftlich->setText(QApplication::translate("MainWindow", "Wissenschaftlich", 0));
        actionHTL->setText(QApplication::translate("MainWindow", "HTL", 0));
        minusButton->setText(QApplication::translate("MainWindow", "-", 0));
        multiplyButton->setText(QApplication::translate("MainWindow", "*", 0));
        clearButton->setText(QApplication::translate("MainWindow", "c", 0));
        plusButton->setText(QString());
        equalsButton->setText(QApplication::translate("MainWindow", "=", 0));
        divideButton->setText(QApplication::translate("MainWindow", "/", 0));
        toolButton->setText(QApplication::translate("MainWindow", "...", 0));
        menuAnsicht->setTitle(QApplication::translate("MainWindow", "Ansicht", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
