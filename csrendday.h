#pragma once

#include <QWidget>
#include "ui_csrendday.h"

class csrEndDay : public QWidget
{
	Q_OBJECT

public:
	csrEndDay(QWidget *parent = Q_NULLPTR);
	~csrEndDay();

private:
	Ui::csrEndDay ui;
};
