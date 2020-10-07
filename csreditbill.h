#pragma once

#include <QWidget>
#include "ui_csreditbill.h"
#include <NaiSys_DbDriver/DbDriver.h>

class csrEditBill : public QWidget
{
	Q_OBJECT

public:
	csrEditBill(QWidget *parent = Q_NULLPTR);
	~csrEditBill();

private:
	Ui::csrEditBill ui;
	DbDriver ndb;
};
