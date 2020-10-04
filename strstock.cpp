#include "strstock.h"

strStock::strStock(QWidget *parent)
	: QWidget(parent)
{ 
	ui.setupUi(this);
	DbDriver dbd("naisys_test", "B");
	QSqlQueryModel* bsd = dbd.runQuerry("select * from mytable");
	ui.treeView->setModel(bsd);
	qDebug() << bsd->index(1, 0).data();
}

strStock::~strStock()
{
	//delete(&ui);
}
