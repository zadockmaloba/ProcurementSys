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
    struct HtabIndx {
        int indx; QString tabId;
    };
    void mouseMoveEvent(QMouseEvent * evnt) override ;
    void mousePressEvent(QMouseEvent* evnt) override;
    void resizeEvent(QResizeEvent* evnt) override;


public slots:
    void maxandminWindow();
    HtabIndx loadApplets(QWidget* prnt, QString appname);
    void closeApplets(int hindx);
    void openCashierApplet();
    void openAccountantApplet();
    void openProcurementApplet();
    void openHRApplet();
    void openStoreMngmt();
    void closeCashierApplet();
    void closeAccountantApplet();
    void closeProcurementApplet();
    void closeHRApplet();
    void deleteWidgetChildren(QWidget* pWidget);

private:
    void buttonMapper();
    void garbageCollector();

private:
    CashierApp* csApp = new CashierApp();
    StoreApp* strApp = new StoreApp();
    Ui::ProcurementSysClass ui;
    QFile* nFile = new QFile("qss/zedqss/zed.qss");
    QPoint mpos;
    bool maxwin;
};
