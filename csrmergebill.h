#pragma once

#include <QWidget>
#include "ui_csrmergebill.h"

class csrMergeBill : public QWidget
{
	Q_OBJECT

public:
	csrMergeBill(QWidget *parent = Q_NULLPTR);
	~csrMergeBill();

private:
	Ui::csrMergeBill ui;
};
