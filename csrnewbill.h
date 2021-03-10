#pragma once

#include <QWidget>
#include "ui_csrnewbill.h"
#include <dbdriver.h>

class csrNewBill : public QWidget
{
	Q_OBJECT

public:
	csrNewBill(QWidget *parent = Q_NULLPTR);
	~csrNewBill();

private://private methods
	int getCurrBillNumber();

public slots:
	void commitNewBill();
	void showBillNumber();

private://private variables
	Ui::csrNewBill ui;
	DbDriver ndb;
};
