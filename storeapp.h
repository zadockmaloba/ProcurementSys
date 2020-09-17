#pragma once

#include <QWidget>
#include "ui_storeapp.h"

class StoreApp : public QWidget
{
	Q_OBJECT

public:
	StoreApp(QWidget *parent = Q_NULLPTR);
	~StoreApp();

private:
	Ui::StoreApp ui;
};
