#pragma once

#include <QWidget>
#include "ui_hrappemployeeview.h"
#include <NaiSys_DbDriver/DbDriver.h>

class HRAppEmployeeView : public QWidget
{
	Q_OBJECT

public:
	HRAppEmployeeView(QWidget *parent = Q_NULLPTR);
	~HRAppEmployeeView();

private:
	Ui::HRAppEmployeeView ui;
	DbDriver ndb;
	void loadEmployeeTableModel();
	void loadEmployeeCardModel();
	
};
