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
