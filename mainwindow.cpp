#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "dbconnection.h"

const QString DRIVER("QSQLITE");

mainWindow::mainWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::mainWindow)
{
    ui->setupUi(this);

    //Check if sqlite driver is available
    if (!QSqlDatabase::drivers().contains(DRIVER))
        QMessageBox::critical(this, "Error loading database", "SQLITE driver not found");

    // Initialize the database
    QSqlError dbError = initDb();
    if (dbError.type() != QSqlError::NoError) {
        QMessageBox::critical(this, "Error initalizing database",
                              "Error: " + dbError.text());
        return;
    }

    model = new QSqlRelationalTableModel(ui->accountsTable);
    model->setEditStrategy(QSqlTableModel::OnManualSubmit);
    model->setTable("account");
    model->select();

    // Populate the model
    if (!model->select())
    {
        QMessageBox::critical(this, "Error populating accounts table data",
                                  "Error: " + model->lastError().text());
        return;
    }

}

/*
 * Method fired when addAccountButton is clicked
 * It shows a new accountForm window to add the account data
 */
void mainWindow::on_addAccountButton_clicked()
{
    //Show form window to add account
    accountFormWindow = new accountForm(this);
    accountFormWindow->setMinimumSize(400, 350);
    accountFormWindow->setMaximumSize(400, 350);
    accountFormWindow->exec();
}

bool mainWindow::addAccount(string accountName, account *newAccount)
{
    try
    {
        this->accounts.insert(std::make_pair(accountName, newAccount));
        return true;
    }
    catch (...)
    {
        QMessageBox::critical(this, "Error adding account object",
                                  "Error: couldn't add account object");
        return false;
    }
}

mainWindow::~mainWindow()
{
    delete ui;
}
