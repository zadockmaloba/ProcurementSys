#pragma once

#include <QWidget>
#include "ui_csrnewbill.h"
#include <NaiSys_DbDriver/DbDriver.h>

class csrNewBill : public QWidget
{
	Q_OBJECT

public:
	csrNewBill(QWidget *parent = Q_NULLPTR);
	~csrNewBill();

public slots:
	void commitNewBill();

private:
	Ui::csrNewBill ui;
	DbDriver ndb;
};
