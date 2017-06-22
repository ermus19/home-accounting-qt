#ifndef DBCONNECTION_H
#define DBCONNECTION_H

#include <QSqlDatabase>
#include <QSqlDriver>
#include <QSqlQuery>
#include <QSqlError>

#include <QStandardPaths>
#include <QMessageBox>
#include <QDir>

QSqlError initDb()
{
    QSqlDatabase db;
    QString dbName;

    //Datapath for apps data
    QString dataDir = QStandardPaths::writableLocation(QStandardPaths::DataLocation);
    QDir dir(dataDir);
    dir.mkpath(dir.path());

    //Datapath to the db file
    dbName = dir.filePath("test.sqlite");

    //Instance of db using the datapath to the db   
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName(dbName);

    //Openning db and capturing error
    if (!db.open()) {
        QMessageBox::critical(0, "DB connection error.", db.lastError().text());
        return db.lastError();
    }

    //Initial queries
    QSqlQuery query;
    if (!query.exec(QLatin1String("PRAGMA foreign_keys = ON")))
        return query.lastError();

    if(!query.exec("CREATE TABLE IF NOT EXISTS account("
                   "account_id INTEGER PRIMARY KEY NOT NULL,"
                   "name VARCHAR NOT NULL,"
                   "balance REAL NOT NULL,"
                   "creation_date DATETIME DEFAULT CURRENT_TIMESTAMP,"
                   "CONSTRAINT name_unique UNIQUE (name)"
                   ")"))
        return query.lastError();

    if(!query.exec("CREATE TABLE IF NOT EXISTS income("
                   "income_id INTEGER PRIMARY KEY NOT NULL,"
                   "account_id INTEGER NOT NULL,"
                   "date DATETIME DEFAULT CURRENT_TIMESTAMP,"
                   "periodic INTEGER NOT NULL,"
                   "concept VARCHAR NOT NULL,"
                   "description VARCHAR,"
                   "FOREIGN KEY(account_id) REFERENCES account(account_id)"
                   ")"))
        return query.lastError();

    if(!query.exec("CREATE TABLE IF NOT EXISTS expense("
                   "expense_id INTEGER PRIMARY KEY NOT NULL,"
                   "account_id INTEGER NOT NULL,"
                   "date DATETIME DEFAULT CURRENT_TIMESTAMP,"
                   "concept VARCHAR NOT NULL,"
                   "description VARCHAR,"
                   "FOREIGN KEY(account_id) REFERENCES account(account_id)"
                   ")"))
        return query.lastError();

    if(!query.exec("CREATE TABLE IF NOT EXISTS transfer("
                   "transfer_id INTEGER PRIMARY KEY NOT NULL,"
                   "origin_account_id INTEGER NOT NULL,"
                   "destination_account_id INTEGER NOT NULL,"
                   "date DATETIME DEFAULT CURRENT_TIMESTAMP,"
                   "concept VARCHAR NOT NULL,"
                   "description VARCHAR,"
                   "FOREIGN KEY(origin_account_id) REFERENCES account(account_id),"
                   "FOREIGN KEY(destination_account_id) REFERENCES account(account_id)"
                   ")"))
        return query.lastError();

    return QSqlError();

}

#endif // DBCONNECTION_H
