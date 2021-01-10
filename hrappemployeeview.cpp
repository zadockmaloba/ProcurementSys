#include "hrappemployeeview.h"

HRAppEmployeeView::HRAppEmployeeView(QWidget *parent)
	: QWidget(parent), ndb("naisys_test","")
{
	ui.setupUi(this);

	loadEmployeeTableModel();

	QObject::connect(ui.pushButton, &QPushButton::clicked, this, [=]() {ui.stackedWidget->setCurrentIndex(0); loadEmployeeTableModel(); });
	QObject::connect(ui.pushButton_2, &QPushButton::clicked, this, [=]() {ui.stackedWidget->setCurrentIndex(1); loadEmployeeCardModel(); });
}

HRAppEmployeeView::~HRAppEmployeeView()
{

}

void HRAppEmployeeView::closeGridWidgets()
{
	
}

void HRAppEmployeeView::loadEmployeeTableModel()
{
	ui.treeView->setModel(ndb.runQuerry("select * from employees ;"));
}

void HRAppEmployeeView::loadEmployeeCardModel()
{
	ui.listView->setModel(ndb.runQuerry("select emp_name from employees ;"));
}
