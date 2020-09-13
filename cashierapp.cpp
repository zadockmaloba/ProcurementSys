#include "cashierapp.h"

CashierApp::CashierApp(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	this->setAttribute(Qt::WA_DeleteOnClose);
	connect(ui.pushButton, SIGNAL(pressed()), this, SLOT(createNewBill()));
}

CashierApp::~CashierApp()
{
	delete(&ui);
	delete(newBill);
	delete(this);
	delete(ui.directCompos->layout());
}

void CashierApp::editBill()
{
}

void CashierApp::clearBill()
{
}

void CashierApp::mergeBill()
{
}

void CashierApp::voidBill()
{
}

void CashierApp::createNewBill()
{
	//newBill->setParent(ui.directCompos);
	ui.directCompos->setLayout(new QGridLayout);
	ui.directCompos->layout()->addWidget(newBill);
	
	//newBill->show();
}

void CashierApp::closeTab(QWidget* prntTab)
{
	
}
