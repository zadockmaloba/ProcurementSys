#pragma once

#include <QWidget>
#include "ui_cashierapp.h"
#include "csr_include.h"

class CashierApp : public QWidget
{
	Q_OBJECT

public:
	CashierApp(QWidget *parent = Q_NULLPTR);
	~CashierApp();

public slots:
	void createNewBill();
	void editBill();
	void clearBill();
	void mergeBill();
	void voidBill();

private:
	Ui::CashierApp ui;
	void closeTab(QWidget * prntTab);
	void closeGridWidgets();

private:
	csrNewBill* newBill = new csrNewBill();
	csrEditBill* edit_Bill = new	csrEditBill();
};
