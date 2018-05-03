/********************************************************************************
** Form generated from reading ui file 'mainwindow.ui'
**
** Created: Sun 16. Mar 14:40:09 2014
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
#include <QtGui/QComboBox>
#include <QtGui/QDateEdit>
#include <QtGui/QGroupBox>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QMainWindow>
#include <QtGui/QPushButton>
#include <QtGui/QRadioButton>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionOpen;
    QAction *actionSave;
    QWidget *centralWidget;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QDateEdit *dateEdit;
    QLabel *label_6;
    QLabel *label_7;
    QComboBox *comboBox;
    QLabel *label_8;
    QLineEdit *nameEdit;
    QLineEdit *vornameEdit;
    QLineEdit *adressEdit;
    QLineEdit *plzEdit;
    QLineEdit *alterEdit;
    QPushButton *anmeldeButton;
    QPushButton *resetButton;
    QPushButton *quitButton;
    QLabel *statusLabel;
    QGroupBox *groupBox;
    QRadioButton *radioMann;
    QRadioButton *radioFrau;
    QButtonGroup *buttonGroup;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(366, 308);
        MainWindow->setUnifiedTitleAndToolBarOnMac(false);
        actionOpen = new QAction(MainWindow);
        actionOpen->setObjectName(QString::fromUtf8("actionOpen"));
        actionSave = new QAction(MainWindow);
        actionSave->setObjectName(QString::fromUtf8("actionSave"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        label = new QLabel(centralWidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(20, 10, 361, 16));
        QFont font;
        font.setFamily(QString::fromUtf8("Arial"));
        font.setPointSize(11);
        label->setFont(font);
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(20, 40, 71, 16));
        label_3 = new QLabel(centralWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(20, 60, 71, 16));
        label_4 = new QLabel(centralWidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(20, 80, 71, 16));
        label_5 = new QLabel(centralWidget);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(20, 100, 71, 16));
        dateEdit = new QDateEdit(centralWidget);
        dateEdit->setObjectName(QString::fromUtf8("dateEdit"));
        dateEdit->setGeometry(QRect(140, 210, 161, 22));
        dateEdit->setDateTime(QDateTime(QDate(2014, 1, 1), QTime(0, 0, 0)));
        label_6 = new QLabel(centralWidget);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(20, 210, 61, 16));
        label_7 = new QLabel(centralWidget);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(20, 180, 81, 16));
        comboBox = new QComboBox(centralWidget);
        comboBox->setObjectName(QString::fromUtf8("comboBox"));
        comboBox->setGeometry(QRect(140, 180, 161, 22));
        label_8 = new QLabel(centralWidget);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setGeometry(QRect(20, 120, 71, 16));
        nameEdit = new QLineEdit(centralWidget);
        nameEdit->setObjectName(QString::fromUtf8("nameEdit"));
        nameEdit->setGeometry(QRect(140, 40, 161, 20));
        vornameEdit = new QLineEdit(centralWidget);
        vornameEdit->setObjectName(QString::fromUtf8("vornameEdit"));
        vornameEdit->setGeometry(QRect(140, 60, 161, 20));
        adressEdit = new QLineEdit(centralWidget);
        adressEdit->setObjectName(QString::fromUtf8("adressEdit"));
        adressEdit->setGeometry(QRect(140, 80, 161, 20));
        plzEdit = new QLineEdit(centralWidget);
        plzEdit->setObjectName(QString::fromUtf8("plzEdit"));
        plzEdit->setGeometry(QRect(140, 100, 71, 20));
        alterEdit = new QLineEdit(centralWidget);
        alterEdit->setObjectName(QString::fromUtf8("alterEdit"));
        alterEdit->setGeometry(QRect(140, 120, 71, 20));
        anmeldeButton = new QPushButton(centralWidget);
        anmeldeButton->setObjectName(QString::fromUtf8("anmeldeButton"));
        anmeldeButton->setGeometry(QRect(20, 250, 81, 23));
        resetButton = new QPushButton(centralWidget);
        resetButton->setObjectName(QString::fromUtf8("resetButton"));
        resetButton->setGeometry(QRect(190, 250, 51, 23));
        quitButton = new QPushButton(centralWidget);
        quitButton->setObjectName(QString::fromUtf8("quitButton"));
        quitButton->setGeometry(QRect(250, 250, 51, 23));
        statusLabel = new QLabel(centralWidget);
        statusLabel->setObjectName(QString::fromUtf8("statusLabel"));
        statusLabel->setGeometry(QRect(20, 280, 311, 16));
        groupBox = new QGroupBox(centralWidget);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(20, 140, 281, 31));
        radioMann = new QRadioButton(groupBox);
        buttonGroup = new QButtonGroup(MainWindow);
        buttonGroup->setObjectName(QString::fromUtf8("buttonGroup"));
        buttonGroup->addButton(radioMann);
        radioMann->setObjectName(QString::fromUtf8("radioMann"));
        radioMann->setGeometry(QRect(120, 10, 71, 17));
        radioFrau = new QRadioButton(groupBox);
        buttonGroup->addButton(radioFrau);
        radioFrau->setObjectName(QString::fromUtf8("radioFrau"));
        radioFrau->setGeometry(QRect(210, 10, 61, 17));
        radioFrau->setChecked(true);
        MainWindow->setCentralWidget(centralWidget);
        QWidget::setTabOrder(nameEdit, vornameEdit);
        QWidget::setTabOrder(vornameEdit, adressEdit);
        QWidget::setTabOrder(adressEdit, plzEdit);
        QWidget::setTabOrder(plzEdit, alterEdit);
        QWidget::setTabOrder(alterEdit, radioMann);
        QWidget::setTabOrder(radioMann, comboBox);
        QWidget::setTabOrder(comboBox, radioFrau);
        QWidget::setTabOrder(radioFrau, dateEdit);
        QWidget::setTabOrder(dateEdit, anmeldeButton);
        QWidget::setTabOrder(anmeldeButton, resetButton);
        QWidget::setTabOrder(resetButton, quitButton);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Anmeldung", 0, QApplication::UnicodeUTF8));
        actionOpen->setText(QApplication::translate("MainWindow", "Open", 0, QApplication::UnicodeUTF8));
        actionSave->setText(QApplication::translate("MainWindow", "Save", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("MainWindow", "Kursanmeldung", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("MainWindow", "Name", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("MainWindow", "Vorname", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("MainWindow", "Adresse", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("MainWindow", "PLZ", 0, QApplication::UnicodeUTF8));
        label_6->setText(QApplication::translate("MainWindow", "Datum", 0, QApplication::UnicodeUTF8));
        label_7->setText(QApplication::translate("MainWindow", "Kursauswahl", 0, QApplication::UnicodeUTF8));
        comboBox->clear();
        comboBox->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "Tennis", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "Golf", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "Surfen", 0, QApplication::UnicodeUTF8)
        );
        label_8->setText(QApplication::translate("MainWindow", "Alter", 0, QApplication::UnicodeUTF8));
        anmeldeButton->setText(QApplication::translate("MainWindow", "Anmeldung", 0, QApplication::UnicodeUTF8));
        resetButton->setText(QApplication::translate("MainWindow", "Reset", 0, QApplication::UnicodeUTF8));
        quitButton->setText(QApplication::translate("MainWindow", "Quit", 0, QApplication::UnicodeUTF8));
        statusLabel->setText(QString());
        groupBox->setTitle(QApplication::translate("MainWindow", "Geschlecht", 0, QApplication::UnicodeUTF8));
        radioMann->setText(QApplication::translate("MainWindow", "m\303\244nnlich", 0, QApplication::UnicodeUTF8));
        radioFrau->setText(QApplication::translate("MainWindow", "weiblich", 0, QApplication::UnicodeUTF8));
        Q_UNUSED(MainWindow);
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
