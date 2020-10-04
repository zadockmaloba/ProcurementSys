#include "procurementsys.h"
#include <NaiSys_DbDriver/DbDriver.h>
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    RestaurantSys w;
    
    w.show();
    return a.exec();
}
