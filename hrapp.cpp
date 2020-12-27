#include "hrapp.h"

HRApp::HRApp(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);

	ui.screenDC->setLayout(new QGridLayout);

	QObject::connect(ui.pushButton, &QPushButton::clicked, this, [=]() { this->viewEmployees(); });
}

HRApp::~HRApp()
{
	delete(ui.screenDC->layout());
}

void HRApp::viewEmployees()
{
	this->closeGridWidgets();
	ui.screenDC->layout()->addWidget(new HRAppEmployeeView);
}

void HRApp::closeGridWidgets()
{
	QLayoutItem* xch;
	for (int i = 0; i <= ui.screenDC->layout()->children().size(); i++)
		if ((xch = ui.screenDC->layout()->takeAt(i)) != nullptr)
		{
			delete xch->widget();
			delete xch;
		}
}
