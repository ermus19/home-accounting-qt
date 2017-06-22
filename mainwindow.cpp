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

    // initialize the database
    QSqlError dbError = initDb();
    if (dbError.type() != QSqlError::NoError) {
        QMessageBox::critical(this, "Error initalizing database",
                              "Error: " + dbError.text());
        return;
    }
}

mainWindow::~mainWindow()
{
    delete ui;
}
