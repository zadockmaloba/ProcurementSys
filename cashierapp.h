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

private:
	Ui::CashierApp ui;
	void closeTab(QWidget * prntTab);
};
