#ifndef ACCOUNTFORM_H
#define ACCOUNTFORM_H

#include <QDialog>
#include <QMessageBox>

#include <account.h>

namespace Ui {
class accountForm;
}

class accountForm : public QDialog
{
    Q_OBJECT

public:
    explicit accountForm(QWidget *parent = 0);
    ~accountForm();

private slots:
    void on_buttonBox_accepted();

private:
    Ui::accountForm *ui;
    account *newAccount;

};

#endif // ACCOUNTFORM_H
