#include "procurementsys.h"
#include <NaiSys_DbDriver/DbDriver.h>
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    RestaurantSys w;
    DbDriver dbd("naisys_test");
    dbd.runQuerry("select * from mytable");
    
    w.show();
    return a.exec();
}
