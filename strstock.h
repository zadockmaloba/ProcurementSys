#pragma once

#include <QWidget>
#include "ui_strstock.h"

class strStock : public QWidget
{
	Q_OBJECT

public:
	strStock(QWidget *parent = Q_NULLPTR);
	~strStock();

private:
	Ui::strStock ui;
};
