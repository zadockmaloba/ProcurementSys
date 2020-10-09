#include "csreditbill.h"

csrEditBill::csrEditBill(QWidget *parent)
	: QWidget(parent), ndb("naisys_test", "")
{
	ui.setupUi(this);
	ui.treeView->setModel(ndb.runQuerry("select * from customerbills where status='Open'"));
	std::vector<std::string> test = { "apples", "eggs", "tomatoes" };
	qDebug() << arrayToString(test);
}

csrEditBill::~csrEditBill()
{

}

QString csrEditBill::arrayToString(std::vector<std::string>& itmlist)
{
	QString nstr = "{ ";
	for (std::string v : itmlist) {
		nstr.append(QString::fromStdString(v)); nstr.append(" , ");
	}
	nstr.append(" }");
	return nstr;
}

void csrEditBill::addItems()
{

	ndb.runQuerry("");
}

void csrEditBill::removeItems()
{
}
