#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QWidget>
#include <QtSql>

#include <accountform.h>
#include <account.h>

namespace Ui {
class mainWindow;
}

class mainWindow : public QWidget
{
    Q_OBJECT

public:
    explicit mainWindow(QWidget *parent = 0);
    bool addAccount(string accountName, account *newAccount);
    ~mainWindow();

private slots:
    void on_addAccountButton_clicked();

private:
    Ui::mainWindow *ui;
    QSqlRelationalTableModel *model;
    accountForm *accountFormWindow;
    map<string, account*> accounts;
};

#endif // MAINWINDOW_H
