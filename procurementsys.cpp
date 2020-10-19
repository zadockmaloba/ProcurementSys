#include "procurementsys.h"

RestaurantSys::RestaurantSys(QWidget *parent)
    : QMainWindow(parent), maxwin(false), indxcount(0)
{
    ui.setupUi(this);

    this->setWindowTitle("NaiSys | RestaurantSys");
    this->setAttribute(Qt::WA_TranslucentBackground);
    this->setWindowOpacity(0.978);
    this->setStyleSheet("background-color: #00FFFFFF;");
    this->setWindowFlags(Qt::FramelessWindowHint);
    this->setAttribute(Qt::WA_Resized);
    this->setMouseTracking(true); 
    this->setBaseSize({ 1020,650 });

    ui.tabWidget->tabBar()->setAttribute(Qt::WA_DeleteOnClose);
    ui.user_label->setContextMenuPolicy(Qt::CustomContextMenu);

    QObject::connect(ui.expandButton, SIGNAL(clicked()), this, SLOT(maxandminWindow()));
    QObject::connect(ui.closeButton, SIGNAL(clicked()), this, SLOT(close()));
    QObject::connect(ui.minimizeButton, SIGNAL(clicked()), this, SLOT(showMinimized()));
    QObject::connect(ui.user_label, SIGNAL(customContextMenuRequested(QPoint)), this, SLOT(customUserMenu(QPoint)));
    //connect(ui.tabWidget->tabBar(), &QTabBar::tabCloseRequested, ui.tabWidget->tabBar(), &QTabBar::removeTab);
    QObject::connect(ui.tabWidget->tabBar(), &QTabBar::tabCloseRequested, this, &RestaurantSys::closeApplets);

    this->buttonMapper();
}

RestaurantSys::~RestaurantSys()
{
    delete(csApp);
    delete(strApp);
    //delete(&ui);
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
    indxcount++;
    return { ui.tabWidget->insertTab( indxcount ,prnt, appname), appname , prnt };
}

void RestaurantSys::closeApplets(int hindx)
{
    ui.tabWidget->widget(hindx)->setUpdatesEnabled(false);
    this->deleteWidgetChildren(ui.tabWidget->widget(hindx));
    ui.tabWidget->tabBar()->removeTab(hindx);
}

void RestaurantSys::openCashierApplet()
{
    LstTabIndx.push_back( this->loadApplets(new CashierApp, "Cashier"));
    ui.tabWidget->setCurrentIndex(indxcount);
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
    ui.tabWidget->setCurrentIndex(indxcount);
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

void RestaurantSys::deleteWidgetChildren(QWidget* pWidget)
{
    while (QObject* w = pWidget->findChild<QObject*>())
        delete (w) ;
    pWidget->setUpdatesEnabled(false);
    qDeleteAll(pWidget->findChildren<QWidget*>("", Qt::FindDirectChildrenOnly));
    pWidget->setUpdatesEnabled(true);
}

void RestaurantSys::customUserMenu(QPoint pos)
{
    QMenu* menu = new QMenu(this);
    menu->setTitle("User : ");
    QLineEdit* ld = new QLineEdit(menu);
    menu->setPalette(this->palette());
    menu->setStyleSheet("background-color: qlineargradient(spread : pad, x1 : 1, y1 : 1, x2 : 1, y2 : 0, stop : 0 rgba(108, 171, 147, 255), stop : 0.994318 rgba(186, 230, 230, 255)); border-radius : 6px;");
    menu->addAction(new QAction("Action 1", this));
    menu->addAction(new QAction("Action 2", this));
    menu->addAction(new QAction("Action 3", this));
    menu->popup(ui.user_label->mapToGlobal(pos += {1, 1}));
}


void RestaurantSys::buttonMapper()
{
    QObject::connect(ui.pushButton, SIGNAL(clicked()), this, SLOT(openCashierApplet()));
    QObject::connect(ui.pushButton_13, SIGNAL(clicked()), this, SLOT(openStoreMngmt()));
}

void RestaurantSys::garbageCollector()
{
    for (QObject* n : ui.tabWidget->children()) {
        delete(n);
    }
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
