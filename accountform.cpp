#include "accountform.h"
#include "ui_accountform.h"
#include "mainwindow.h"

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

/*
 * This function is fired when the buttonBox accept button is accepted
 * Tries to create a new account
 */
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

        //Creation of new account
        newAccount = new account(
                        accountName.toStdString(),
                        accountDescription.toStdString(),
                        balance);

        //Accessor to parent window variables
        mainWindow* parent = qobject_cast<mainWindow*>(this->parent());

        //Adding the new account to the collection
        parent->addAccount("test", newAccount);

        //Destroy dialog when addition is completed
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
