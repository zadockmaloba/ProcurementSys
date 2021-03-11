#include "procurementsys.h"
#include "infosetup.h"
#include <dbdriver.h>
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    RestaurantSys w;
    InfoSetup inf;
    w.show();
    inf.show();
    return a.exec();
}
