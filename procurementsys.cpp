#include "procurementsys.h"

RestaurantSys::RestaurantSys(QWidget *parent)
    : QMainWindow(parent), maxwin(false), indxcount(0)
{
    ui.setupUi(this);

    this->setWindowTitle("NaiSys | RestaurantSys");
    this->setAttribute(Qt::WA_TranslucentBackground);
    this->setWindowOpacity(0.998);
    this->setStyleSheet("background-color: #00FFFFFF;");
    this->setWindowFlags(Qt::FramelessWindowHint);
    this->setAttribute(Qt::WA_Resized);
    this->setMouseTracking(true); 
    this->setBaseSize({ 1020,650 });

    ui.tabWidget->tabBar()->setAttribute(Qt::WA_DeleteOnClose);
    ui.user_label->setContextMenuPolicy(Qt::CustomContextMenu);

    //this->setAcrylicOpacity();

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
    delete(nFile);
    //delete(&ui);
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
    indxcount += 1;
    return { ui.tabWidget->insertTab( indxcount ,prnt, appname), appname , prnt };
}

void RestaurantSys::closeApplets(int hindx)
{
    //ui.tabWidget->widget(hindx)->setUpdatesEnabled(false);
    this->deleteWidgetChildren(ui.tabWidget->widget(hindx));
    ui.tabWidget->tabBar()->removeTab(hindx);
}

void RestaurantSys::openHomePage()
{
    ui.tabWidget->setCurrentIndex(0);
}

void RestaurantSys::openCashierApplet()
{
    LstTabIndx.push_back( this->loadApplets(new CashierApp, "Cashier"));
    ui.tabWidget->setCurrentIndex(indxcount);
}

void RestaurantSys::openAccountantApplet()
{
    LstTabIndx.push_back(this->loadApplets(new FinanceApp, "Finance"));
    ui.tabWidget->setCurrentIndex(indxcount);
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
        delete(w) ;
   // pWidget->setUpdatesEnabled(false);
    qDeleteAll(pWidget->findChildren<QWidget*>("", Qt::FindDirectChildrenOnly));
    indxcount -= 1;
    pWidget->close();
   // pWidget->setUpdatesEnabled(true);
}

void RestaurantSys::customUserMenu(QPoint pos)
{
    //A lot of work needs to be done regarding the username context menu
    QMenu* menu = new QMenu(this);
    menu->setTitle("User : ");
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
    QObject::connect(ui.pushButton_2, SIGNAL(clicked()), this, SLOT(openAccountantApplet()));
    QObject::connect(ui.pushButton_9, SIGNAL(clicked()), this, SLOT(openHomePage()));
}

void RestaurantSys::garbageCollector()
{
    for (QObject* n : ui.tabWidget->children()) {
        delete(n);
    }
}

void RestaurantSys::setAcrylicOpacity()
{
    const HINSTANCE hModule = LoadLibrary(TEXT("user32.dll"));
    HWND m_hwnd = reinterpret_cast<HWND>(this->winId());
    if (hModule) {
        struct ACCENTPOLICY {
            int nAccentState;
            int nFlags;
            int nColor;
            int nAnimationId;
        };
        struct WINCOMPATTRDATA {
            int nAttribute;
            PVOID pData;
            ULONG ulDataSize;
        };
        enum class Accent {
            DISABLED = 0,
            GRADIENT = 1,
            TRANSPARENTGRADIENT = 2,
            BLURBEHIND = 3,
            ACRYLIC = 4,
            INVALID = 5
        };
        typedef BOOL(WINAPI* pSetWindowCompositionAttribute)(HWND, WINCOMPATTRDATA*);
        const pSetWindowCompositionAttribute SetWindowCompositionAttribute = (pSetWindowCompositionAttribute)GetProcAddress(hModule, "SetWindowCompositionAttribute");
        if (SetWindowCompositionAttribute) {
            ACCENTPOLICY policy = { 1, 0, 0, 0 }; // ACCENT_ENABLE_BLURBEHIND=3...
            WINCOMPATTRDATA data = { 19, &policy, sizeof(ACCENTPOLICY) }; // WCA_ACCENT_POLICY=19
            SetWindowCompositionAttribute(m_hwnd, &data);
        }
        FreeLibrary(hModule);
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
