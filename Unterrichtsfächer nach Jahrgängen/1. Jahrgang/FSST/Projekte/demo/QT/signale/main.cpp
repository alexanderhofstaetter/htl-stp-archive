///////////////////////////////////////////////////////////////////////////////
//   main.cpp
//
//   progr. by di w.alfery
//   2009-10-02
//   version 1.0
//
///////////////////////////////////////////////////////////////////////////////


#include <QtGui/QApplication>
#include "mainwindow.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}
