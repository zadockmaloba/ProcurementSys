#include "csreditbill.h"

csrEditBill::csrEditBill(QWidget *parent)
	: QWidget(parent), ndb("naisys_test", "")
{
	ui.setupUi(this);
	ui.treeView->setModel(ndb.runQuerry("select * from customerbills where status='Open'"));
}

csrEditBill::~csrEditBill()
{
}
