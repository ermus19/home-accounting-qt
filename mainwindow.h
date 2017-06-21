#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QWidget>

namespace Ui {
class mainWindow;
}

class mainWindow : public QWidget
{
    Q_OBJECT

public:
    explicit mainWindow(QWidget *parent = 0);
    ~mainWindow();

private:
    Ui::mainWindow *ui;
};

#endif // MAINWINDOW_H
