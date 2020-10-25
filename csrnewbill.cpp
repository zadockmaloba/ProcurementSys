#include "csrnewbill.h"

csrNewBill::csrNewBill(QWidget *parent)
	: QWidget(parent), ndb("naisys_test", "")
{
	ui.setupUi(this);

	this->showBillNumber();

	QObject::connect(ui.pushButton, SIGNAL(pressed()), this, SLOT(commitNewBill()));
}

csrNewBill::~csrNewBill()
{
}

int csrNewBill::getCurrBillNumber()
{
	QString qry("Select bill_number from customerbills");
	auto mdl = ndb.runQuerry(qry);
	int billnum = mdl->record(mdl->rowCount()-1).value("bill_number").toInt();
	return billnum += 1;
}

void csrNewBill::showBillNumber()
{
	ui.lineEdit->setText(QString::number(getCurrBillNumber()));
}

void csrNewBill::commitNewBill()
{
	QString regKey = QString::number(1201);
	QString	gSitting = QString::number(ui.spinBox->value());
	QString menutype = ui.comboBox->currentText();
	QString stat = "Open";
	QString initdate = QDate::currentDate().toString();
	QString inittime = QTime::currentTime().toString();
	QString bind = "'"+menutype + "' , '" + gSitting + "' , '" + stat + "' , '" + initdate + "' , '" + inittime+"'";
	QString cmnd = "insert into customerbills (menu_type, sitting, status, date_initiated, time_initiated) values ("+bind+")";

	ndb.runQuerry(cmnd);
	this->showBillNumber();
}
