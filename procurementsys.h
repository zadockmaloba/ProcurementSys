#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_procurementsys.h"
#include <qfile.h>
#include <qdebug.h>
#include <qmouseeventtransition.h>
#include <qevent.h>

class ProcurementSys : public QMainWindow
{
    Q_OBJECT

public:
    ProcurementSys(QWidget *parent = Q_NULLPTR);
    ~ProcurementSys();
    void mouseMoveEvent(QMouseEvent * evnt) override ;
    void mousePressEvent(QMouseEvent* evnt) override;
    

private:
    Ui::ProcurementSysClass ui;
    QFile* nFile = new QFile("qss/zedqss/zed.qss");
    QPoint mpos;
};
