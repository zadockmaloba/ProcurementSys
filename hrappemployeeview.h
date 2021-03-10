#pragma once

#include <QWidget>
#include "ui_hrappemployeeview.h"
#include <dbdriver.h>
#include "hrappemployeecard.h"

class HRAppEmployeeView : public QWidget
{
	Q_OBJECT

public:
	HRAppEmployeeView(QWidget *parent = Q_NULLPTR);
	~HRAppEmployeeView();
	void closeGridWidgets();

private:
	Ui::HRAppEmployeeView ui;
	DbDriver ndb;
	void loadEmployeeTableModel();
	void loadEmployeeCardModel();
};
