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
    //ui.tabWidget->setDocumentMode(true);

    QObject::connect(ui.expandButton, SIGNAL(clicked()), this, SLOT(maxandminWindow()));
    QObject::connect(ui.closeButton, SIGNAL(clicked()), this, SLOT(close()));
    QObject::connect(ui.pushButton, SIGNAL(clicked()), ui.tabWidget, SLOT(setCurrentIndex(2)));
    QObject::connect(ui.minimizeButton, SIGNAL(clicked()), this, SLOT(showMinimized()));
}

RestaurantSys::~RestaurantSys()
{
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
