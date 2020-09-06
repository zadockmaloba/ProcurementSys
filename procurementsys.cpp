#include "procurementsys.h"

RestaurantSys::RestaurantSys(QWidget *parent)
    : QMainWindow(parent), maxwin(false)
{
    ui.setupUi(this);
    //nFile->open(QIODevice::ReadOnly);
    //QString nStyle = QLatin1String( nFile->readAll() );
    this->setWindowTitle("NaiSys | RestaurantSys");
    this->setAttribute(Qt::WA_TranslucentBackground);
    this->setWindowOpacity(0.978);
    this->setStyleSheet("background-color: #00FFFFFF;");
    this->setWindowFlags(Qt::FramelessWindowHint);
    this->setMouseTracking(true); 
    this->setBaseSize({ 1020,650 });
    this->loadApplets(new CashierApp, "zApp");

    QObject::connect(ui.expandButton, SIGNAL(clicked()), this, SLOT(maxandminWindow()));
    QObject::connect(ui.closeButton, SIGNAL(clicked()), this, SLOT(close()));
    QObject::connect(ui.minimizeButton, SIGNAL(clicked()), this, SLOT(showMinimized()));

    this->buttonMapper();
}

RestaurantSys::~RestaurantSys()
{
    delete(csApp);
    delete(&ui);
    delete(nFile);
}

void RestaurantSys::mouseMoveEvent (QMouseEvent* evnt)
{
    if (evnt->buttons() & Qt::LeftButton && ui.custom_titlebar->underMouse())
    {
        QPoint npos = evnt->pos();
        QPoint diff = npos - mpos;
        this->move(this->pos() + diff);
    }
}

void RestaurantSys::mousePressEvent(QMouseEvent* evnt)
{
    mpos = evnt->pos();
}

void RestaurantSys::resizeEvent(QResizeEvent* evnt)
{

}

RestaurantSys::HtabIndx RestaurantSys::loadApplets(QWidget *prnt, QString appname)
{
    return { ui.tabWidget->addTab(prnt, appname), appname };
}

void RestaurantSys::openCashierApplet()
{
    this->loadApplets(new CashierApp, "cashier");
}

void RestaurantSys::openAccountantApplet()
{
}

void RestaurantSys::openProcurementApplet()
{
}

void RestaurantSys::openHRApplet()
{
}

void RestaurantSys::closeCashierApplet()
{
}

void RestaurantSys::closeAccountantApplet()
{
}

void RestaurantSys::closeProcurementApplet()
{
}

void RestaurantSys::closeHRApplet()
{
}

void RestaurantSys::buttonMapper()
{
    QObject::connect(ui.pushButton, SIGNAL(clicked()), this, SLOT(openCashierApplet()));
}

void RestaurantSys::maxandminWindow()
{
    if (maxwin)
    {
        this->showNormal();
        maxwin = false;
    }
    else if(!maxwin)
    {
        this->showMaximized();
        maxwin = true;
    }
}
