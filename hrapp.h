#pragma once

#include <QWidget>
#include "ui_hrapp.h"
#include "hrappemployeeview.h"

class HRApp : public QWidget
{
	Q_OBJECT

public:
	HRApp(QWidget *parent = Q_NULLPTR);
	~HRApp();

public slots:
	void viewEmployees();

private:
	Ui::HRApp ui;
	void closeGridWidgets();
};
