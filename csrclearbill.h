#pragma once

#include <QWidget>
#include "ui_csrclearbill.h"

class csrClearBill : public QWidget
{
	Q_OBJECT

public:
	csrClearBill(QWidget *parent = Q_NULLPTR);
	~csrClearBill();

private:
	Ui::csrClearBill ui;
};
