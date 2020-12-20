#pragma once

#include <QWidget>
#include "ui_hrapp.h"

class HRApp : public QWidget
{
	Q_OBJECT

public:
	HRApp(QWidget *parent = Q_NULLPTR);
	~HRApp();

private:
	Ui::HRApp ui;
};
