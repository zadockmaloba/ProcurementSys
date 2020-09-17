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
    this->setAttribute(Qt::WA_Resized);
    this->setMouseTracking(true); 
    this->setBaseSize({ 1020,650 });

    ui.tabWidget->tabBar()->setAttribute(Qt::WA_DeleteOnClose);

    QObject::connect(ui.expandButton, SIGNAL(clicked()), this, SLOT(maxandminWindow()));
    QObject::connect(ui.closeButton, SIGNAL(clicked()), this, SLOT(close()));
    QObject::connect(ui.minimizeButton, SIGNAL(clicked()), this, SLOT(showMinimized()));
    connect(ui.tabWidget->tabBar(), &QTabBar::tabCloseRequested, ui.tabWidget->tabBar(), &QTabBar::removeTab);

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
    HtabIndx htemp = this->loadApplets(new CashierApp, "Cashier");
    ui.tabWidget->setCurrentIndex(htemp.indx);
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

void RestaurantSys::openStoreMngmt()
{
    HtabIndx htemp = this->loadApplets(new StoreApp, "Store Management");
    ui.tabWidget->setCurrentIndex(htemp.indx);
}

void RestaurantSys::closeCashierApplet()
{
    //defragmented
}

void RestaurantSys::closeAccountantApplet()
{
    //defragmented
}

void RestaurantSys::closeProcurementApplet()
{
    //defragmented
}

void RestaurantSys::closeHRApplet()
{
    //defragmented
}

void RestaurantSys::buttonMapper()
{
    QObject::connect(ui.pushButton, SIGNAL(clicked()), this, SLOT(openCashierApplet()));
    QObject::connect(ui.pushButton_13, SIGNAL(clicked()), this, SLOT(openStoreMngmt()));
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
