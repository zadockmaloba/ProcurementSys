#pragma once

#include <QWidget>
#include "ui_csrvoidbill.h"

class csrVoidBill : public QWidget
{
	Q_OBJECT

public:
	csrVoidBill(QWidget *parent = Q_NULLPTR);
	~csrVoidBill();

private:
	Ui::csrVoidBill ui;
};
