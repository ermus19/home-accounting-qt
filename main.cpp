#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QCoreApplication::setApplicationName("home-accounting-qt");

    //Creation of the the app main window
    mainWindow mainWin;
    mainWin.setMinimumSize(650, 350);
    mainWin.setMaximumSize(900, 700);
    mainWin.show();

    return a.exec();
}
