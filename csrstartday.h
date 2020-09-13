#pragma once

#include <QWidget>
#include "ui_csrstartday.h"

class csrStartDay : public QWidget
{
	Q_OBJECT

public:
	csrStartDay(QWidget *parent = Q_NULLPTR);
	~csrStartDay();

private:
	Ui::csrStartDay ui;
};
