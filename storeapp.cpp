#include "storeapp.h"

StoreApp::StoreApp(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	this->setAttribute(Qt::WA_DeleteOnClose);
}

StoreApp::~StoreApp()
{
}
