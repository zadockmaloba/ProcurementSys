#pragma once
#include <dbdriver.h>
#include <qwidget.h>

class DbInterface
{
public:
	static bool opentable(QString tablename);
	static bool createtable(QString tablename, QString columnList);
	static bool selectDatabase(QString dbname);
	static bool createDatabase(QString dbname);
	static bool addRowEntry(QString dbname, QVector<QVariant>& data);
	static bool bindModelToWidget(QWidget* widg, QSqlQuery* qry);
	static bool commitChanges();

private:
	DbDriver dbdrvr;

};

