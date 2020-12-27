#include "hrappemployeeview.h"

HRAppEmployeeView::HRAppEmployeeView(QWidget *parent)
	: QWidget(parent), ndb("naisys_test","")
{
	ui.setupUi(this);
	ui.cardPageScrollArea->setLayout(new QGridLayout);

	loadEmployeeTableModel();

	QObject::connect(ui.pushButton, &QPushButton::clicked, this, [=]() {ui.stackedWidget->setCurrentIndex(0); loadEmployeeTableModel(); });
	QObject::connect(ui.pushButton_2, &QPushButton::clicked, this, [=]() {ui.stackedWidget->setCurrentIndex(1); loadEmployeeCardModel(); });
}

HRAppEmployeeView::~HRAppEmployeeView()
{

}

void HRAppEmployeeView::closeGridWidgets()
{
	QLayoutItem* xch;
	for (int i = 0; i <= ui.cardPageScrollArea->layout()->children().size(); i++)
		if ((xch = ui.cardPageScrollArea->layout()->takeAt(i)) != nullptr)
		{
			delete xch->widget();
			delete xch;
		}
	delete(ui.scrollAreaWidgetContents); //Whole Lotta Bugs !!!!!
}

void HRAppEmployeeView::loadEmployeeTableModel()
{
	ui.treeView->setModel(ndb.runQuerry("select * from employees ;"));
}

void HRAppEmployeeView::loadEmployeeCardModel()
{
	this->closeGridWidgets();
	for (int i = 0; i < 2; i++)
		ui.cardPageScrollArea->layout()->addWidget(new HRAppEmployeeCard);
}
