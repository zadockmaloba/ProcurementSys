#include "procurementsys.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    ProcurementSys w;
    w.show();
    return a.exec();
}
