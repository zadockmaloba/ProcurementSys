#include "strtransfer.h"

StrTransfer::StrTransfer(QWidget *parent)
	: QWidget(parent), ndb("naisys_test","a")
{
	ui.setupUi(this);
	ui.comboBox->setModel(ndb.runQuerry("select item from mytable"));
}

StrTransfer::~StrTransfer()
{
}

void StrTransfer::receiveItems()
{
	QString item_name = ui.comboBox->currentText();

	ndb.runQuerry("");
}

void StrTransfer::issueItems()
{
	ndb.runQuerry("");
}
