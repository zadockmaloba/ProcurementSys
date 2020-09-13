#include "cashierapp.h"

CashierApp::CashierApp(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	this->setAttribute(Qt::WA_DeleteOnClose);
}

CashierApp::~CashierApp()
{

}

void CashierApp::closeTab(QWidget* prntTab)
{
	
}
