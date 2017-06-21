#ifndef DBCONNECTION_H
#define DBCONNECTION_H

#include <QSqlDatabase>
#include <QSqlDriver>
#include <QSqlQuery>
#include <QSqlError>



QSqlError initDb()
{
    //Datapath for apps data
    QString dataDir = QStandardPaths::writableLocation(QStandardPaths::DataLocation);
    QDir dir(dataDir);
    dir.mkpath(dir.path());

    //Datapath to the db file
    dbName = dir.filePath(dbName+".sqlite");

    //Instance of db using the datapath to the db   
    db = QSqlDatabase::addDatabase("QSQLITE", dbName);
    db.setDatabaseName(dbName);

    //Openning db and capturing error
    if (!db.open()) {
        QMessageBox::critical(0, "DB connection error.", db.lastError().text());
        return db.lastError();
    }

    //Initial queries
    QsqlQuery query;
    if (!query.exec(QLatin1String("PRAGMA foreign_keys = ON")))
        return query.lastError();

    if(!query.exec("CREATE TABLE IF NOT EXISTS account(account_id INTEGER PRIMARY KEY NOT NULL, name VARCHAR NOT NULL, balance REAL NULL, CONSTRAINT name_unique UNIQUE (name))"))
        return query.lastError();

    if(!query.exec(QLatin1String("")))
        return query.lastError();

}

#endif // DBCONNECTION_H
