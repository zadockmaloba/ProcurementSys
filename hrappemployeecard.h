#pragma once

#include <QWidget>
#include "ui_hrappemployeecard.h"

class HRAppEmployeeCard : public QWidget
{
	Q_OBJECT

public:
	HRAppEmployeeCard(QWidget *parent = Q_NULLPTR);
	~HRAppEmployeeCard();

private:
	Ui::HRAppEmployeeCard ui;
};
