#include "cashierapp.h"

CashierApp::CashierApp(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	this->setAttribute(Qt::WA_DeleteOnClose);

	connect(ui.pushButton, SIGNAL(pressed()), this, SLOT(createNewBill()));
	connect(ui.pushButton_2, SIGNAL(pressed()), this, SLOT(editBill()));
}

CashierApp::~CashierApp()
{
	delete(&ui);
	delete(newBill);
	delete(ui.directCompos->layout());
	delete(this);
}

void CashierApp::editBill()
{
	ui.directCompos->setLayout(new QGridLayout);
	ui.directCompos->layout()->addWidget(edit_Bill);
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
	ui.directCompos->setLayout(new QGridLayout);
	ui.directCompos->layout()->addWidget(newBill);
}

void CashierApp::closeTab(QWidget* prntTab)
{
	
}
