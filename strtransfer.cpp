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
