#pragma once

#include <QWidget>
#include "ui_financeapp.h"

class FinanceApp : public QWidget
{
	Q_OBJECT

public:
	FinanceApp(QWidget *parent = Q_NULLPTR);
	~FinanceApp();

private:
	Ui::FinanceApp ui;
};
