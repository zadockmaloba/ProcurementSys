#include "dbdriver.h"

DbDriver::DbDriver(QString dbName, QString connName)
{

}

DbDriver::~DbDriver()
{

}

QSqlQueryModel *DbDriver::runQuerry(QString intr)
{
    return new QSqlQueryModel();
}

bool DbDriver::innitDB()
{
    return false;
}

bool DbDriver::connectDB()
{
    return false;
}

void DbDriver::closeDB()
{

}
