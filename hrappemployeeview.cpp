#include "hrappemployeeview.h"

HRAppEmployeeView::HRAppEmployeeView(QWidget *parent)
	: QWidget(parent), ndb("naisys_test","")
{
	ui.setupUi(this);

	QObject::connect(ui.pushButton, &QPushButton::clicked, this, [=]() {ui.stackedWidget->setCurrentIndex(0); loadEmployeeTableModel(); });
	QObject::connect(ui.pushButton_2, &QPushButton::clicked, this, [=]() {ui.stackedWidget->setCurrentIndex(1); });
}

HRAppEmployeeView::~HRAppEmployeeView()
{

}

void HRAppEmployeeView::loadEmployeeTableModel()
{
	ui.treeView->setModel(ndb.runQuerry("select * from employees ;"));
}

void HRAppEmployeeView::loadEmployeeCardModel()
{
}
