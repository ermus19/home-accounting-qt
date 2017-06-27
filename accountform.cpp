#include "accountform.h"
#include "ui_accountform.h"

accountForm::accountForm(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::accountForm)
{
    ui->setupUi(this);

    //SpinBox balance range set
    ui->balanceValue->setRange(0, 99999999.99);

    //Disconnect accepted event:
    //window only closes if input is valid or clicking cancel.
    disconnect(ui->buttonBox, SIGNAL(accepted()), this, SLOT(accept()));
}

void accountForm::on_buttonBox_accepted()
{
    QString accountName = ui->accountNameEdit->text();
    QString accountDescription = ui->accountDescriptionEdit->toPlainText();
    double balance = ui->balanceValue->value();

    if(accountName.isEmpty())
    {
        //Show message on blank account name
        QMessageBox::critical(this, "Error saving account",
                                  "Error: account name not set!");
    } else {

        newAccount = new account(
                        accountName.toStdString(),
                        accountDescription.toStdString(),
                        balance);

        this->destroy();
    }
}

void QWidget::closeEvent(QCloseEvent *close)
{
    close->accept();
    return;
}

accountForm::~accountForm()
{
    delete ui;
}
