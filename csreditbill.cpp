#include "csreditbill.h"

csrEditBill::csrEditBill(QWidget *parent)
	: QWidget(parent), ndb("naisys_test", ""), currentbill("")
{
	ui.setupUi(this);
	ui.treeView->setModel(ndb.runQuerry("select * from customerbills where status='Open'"));
	//ui.treeView_2->setModel((QAbstractItemModel*)ui.treeView->currentIndex().model());

	QObject::connect(ui.pushButton, SIGNAL(pressed()), this, SLOT(addItems()));
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
	QModelIndex indx { ui.treeView->currentIndex()};
	QString billno { ui.treeView->model()->data(indx).toString() };
	currentbill = billno;
	//qDebug() << "DEBUG BILL NO : " + billno;

	QString itm_name = ui.comboBox_3->currentText();
	QString itm_quantity; // quantity will be taken from spinbox

	ndb.runQuerry("");
}

void csrEditBill::removeItems()
{
}
