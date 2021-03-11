#include "infosetup.h"
#include "ui_infosetup.h"

InfoSetup::InfoSetup(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::InfoSetup)
{
    ui->setupUi(this);
}

InfoSetup::~InfoSetup()
{
    delete ui;
}

void InfoSetup::on_stackedWidget_currentChanged(int arg1)
{

}

void InfoSetup::on_pushButton_clicked(bool checked)
{
    ui->stackedWidget->setCurrentIndex(0);
}

void InfoSetup::on_pushButton_2_clicked(bool checked)
{
    ui->stackedWidget->setCurrentIndex(1);
}

void InfoSetup::on_pushButton_3_clicked(bool checked)
{
    ui->stackedWidget->setCurrentIndex(2);
}

void InfoSetup::on_pushButton_6_clicked(bool checked)
{
    ui->stackedWidget->setCurrentIndex(3);
}

void InfoSetup::on_pushButton_7_clicked(bool checked)
{
    ui->stackedWidget->setCurrentIndex(4);
}

void InfoSetup::on_pushButton_8_clicked(bool checked)
{
    ui->stackedWidget->setCurrentIndex(5);
}

void InfoSetup::on_pushButton_5_clicked(bool checked)
{
    ui->stackedWidget->setCurrentIndex(6);
}

void InfoSetup::on_pushButton_4_clicked(bool checked)
{
    ui->stackedWidget->setCurrentIndex(7);
}

void InfoSetup::on_pushButton_9_clicked(bool checked)
{
    ui->stackedWidget->setCurrentIndex(8);
}
