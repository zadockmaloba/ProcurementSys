#ifndef INFOSETUP_H
#define INFOSETUP_H

#include <QMainWindow>

namespace Ui {
class InfoSetup;
}

class InfoSetup : public QMainWindow
{
    Q_OBJECT

public:
    explicit InfoSetup(QWidget *parent = nullptr);
    ~InfoSetup();

private slots:
    void on_stackedWidget_currentChanged(int arg1);

    void on_pushButton_clicked(bool checked);

    void on_pushButton_2_clicked(bool checked);

    void on_pushButton_3_clicked(bool checked);

    void on_pushButton_6_clicked(bool checked);

    void on_pushButton_4_clicked(bool checked);

    void on_pushButton_7_clicked(bool checked);

    void on_pushButton_8_clicked(bool checked);

    void on_pushButton_5_clicked(bool checked);

    void on_pushButton_9_clicked(bool checked);

private:
    Ui::InfoSetup *ui;
};

#endif // INFOSETUP_H
