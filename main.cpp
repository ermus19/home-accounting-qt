#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QCoreApplication::setApplicationName("home-accounting-qt");

    mainWindow mainWin;
    mainWin.setMinimumSize(800, 600);
    mainWin.show();

    return a.exec();
}
