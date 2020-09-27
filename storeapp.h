#pragma once

#include <QWidget>
#include "ui_storeapp.h"
#include "strstock.h"

class StoreApp : public QWidget
{
	Q_OBJECT

public:
	StoreApp(QWidget *parent = Q_NULLPTR);
	~StoreApp();

public slots:
	void viewStocks();
	void editItems();
	void transferItems();
	void stockAnalysis();

private:
	Ui::StoreApp ui;
	void closeGridWidgets();
};
