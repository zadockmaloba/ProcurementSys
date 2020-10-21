#pragma once

#include <QWidget>
#include "ui_usercard.h"

class UserCard : public QWidget
{
	Q_OBJECT

public:
	UserCard(QWidget *parent = Q_NULLPTR);
	~UserCard();

private:
	Ui::UserCard ui;
    QString test;
};
