#pragma once

#include <QWidget>
#include "ui_strtransfer.h"
#include <NaiSys_DbDriver/DbDriver.h>

class StrTransfer : public QWidget
{
	Q_OBJECT

public:
	StrTransfer(QWidget *parent = Q_NULLPTR);
	~StrTransfer();

private:
	Ui::StrTransfer ui;
	DbDriver ndb;
};
