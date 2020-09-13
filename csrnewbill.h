#pragma once

#include <QWidget>
#include "ui_csrnewbill.h"

class csrNewBill : public QWidget
{
	Q_OBJECT

public:
	csrNewBill(QWidget *parent = Q_NULLPTR);
	~csrNewBill();

private:
	Ui::csrNewBill ui;
};
