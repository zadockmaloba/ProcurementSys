#ifndef DBDRIVER_H
#define DBDRIVER_H

#include <QSql>
#include <QtSql>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QSqlDatabase>
#include <QSqlDriver>
#include <QDateTime>
#include <QtSqlDepends>


class DbDriver
{
public:
    DbDriver(QString dbName, QString connName);
    ~DbDriver();
public:
    QSqlQueryModel* runQuerry(QString intr);
private:
    bool innitDB();
    bool connectDB();
    void closeDB();
    QSqlDatabase objectDb;
};

#endif // DBDRIVER_H
