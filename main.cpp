#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QCoreApplication::setApplicationName("home-accounting-qt");

    mainWindow mainWin;
    mainWin.setMinimumSize(700, 500);
    mainWin.show();

    return a.exec();
}
