#include "payment.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Payment w;
    w.show();

    return a.exec();
}
