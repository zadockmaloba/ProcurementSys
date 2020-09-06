#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_procurementsys.h"
#include <qfile.h>
#include <qdebug.h>
#include <qmouseeventtransition.h>
#include <qevent.h>
#include <qsizegrip.h>

#include "global_custom_widgets.h"


class RestaurantSys : public QMainWindow
{
    Q_OBJECT

public:
    RestaurantSys(QWidget *parent = Q_NULLPTR);
    ~RestaurantSys();
    void mouseMoveEvent(QMouseEvent * evnt) override ;
    void mousePressEvent(QMouseEvent* evnt) override;
    void resizeEvent(QResizeEvent* evnt) override;
    void loadApplets(QWidget *prnt, QString appname);


public slots:
    void maxandminWindow();

private:
    CashierApp* csApp = new CashierApp();
    Ui::ProcurementSysClass ui;
    QFile* nFile = new QFile("qss/zedqss/zed.qss");
    QPoint mpos;
    bool maxwin;
};
