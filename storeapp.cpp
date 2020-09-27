#include "storeapp.h"

StoreApp::StoreApp(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	//this->setAttribute(Qt::WA_DeleteOnClose);
	ui.screenDC->setLayout(new QGridLayout);

	QObject::connect(ui.pushButton, SIGNAL(clicked()), this, SLOT(viewStocks()));
}

StoreApp::~StoreApp()
{
	
}

void StoreApp::editItems()
{

}

void StoreApp::transferItems()
{
}

void StoreApp::stockAnalysis()
{
}

void StoreApp::closeGridWidgets()
{
	QLayoutItem* xch;
	for (int i = 0; i <= ui.screenDC->layout()->children().size(); i++)
		if ((xch = ui.screenDC->layout()->takeAt(i)) != nullptr)
		{
			delete xch->widget();
			delete xch;
		}
}

void StoreApp::viewStocks()
{
	closeGridWidgets();
	ui.screenDC->layout()->addWidget(new strStock);
}
