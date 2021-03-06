#pragma once

#include <QWidget>
#include "ui_strtransfer.h"
#include <dbdriver.h>

class StrTransfer : public QWidget
{
	Q_OBJECT

public:
	StrTransfer(QWidget *parent = Q_NULLPTR);
	~StrTransfer();

public slots:
	void issueItems();
	void receiveItems();

private:
	Ui::StrTransfer ui;
	DbDriver ndb;
};
