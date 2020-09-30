#include "DbInterface.h"

bool DbInterface::opentable(QString tablename)
{
	return false;
}

bool DbInterface::createtable(QString tablename, QString columnList)
{
	return false;
}

bool DbInterface::selectDatabase(QString dbname)
{
	return false;
}

bool DbInterface::createDatabase(QString dbname)
{
	return false;
}

bool DbInterface::addRowEntry(QString dbname, QVector<QVariant>& data)
{
	return false;
}

bool DbInterface::bindModelToWidget(QWidget* widg, QSqlQuery* qry)
{
	QSqlQueryModel mdl;
	mdl.setQuery(*qry);
	return false;
}

bool DbInterface::commitChanges()
{
	return false;
}
