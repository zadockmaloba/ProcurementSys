#include "cashierapp.h"

CashierApp::CashierApp(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	//this->setAttribute(Qt::WA_DeleteOnClose);

	ui.directCompos->setLayout(new QGridLayout);

	connect(ui.pushButton, SIGNAL(pressed()), this, SLOT(createNewBill()));
	connect(ui.pushButton_2, SIGNAL(pressed()), this, SLOT(editBill()));
	connect(ui.pushButton_5, SIGNAL(pressed()), this, SLOT(mergeBill()));
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
	this->closeGridWidgets();
	ui.directCompos->layout()->addWidget(new csrEditBill);
}

void CashierApp::clearBill()
{
}

void CashierApp::mergeBill()
{
	this->closeGridWidgets();
	ui.directCompos->layout()->addWidget(new csrMergeBill);
}

void CashierApp::voidBill()
{
}

void CashierApp::createNewBill()
{
	this->closeGridWidgets();
	ui.directCompos->layout()->addWidget(new csrNewBill);
}

void CashierApp::closeTab(QWidget* prntTab)
{
	
}

void CashierApp::closeGridWidgets()
{
	QLayoutItem* xch;
	for(int i=0; i <= ui.directCompos->layout()->children().size(); i++)
	if ((xch = ui.directCompos->layout()->takeAt(i)) != nullptr)
	{
		delete xch->widget();
		delete xch;
	}
}
