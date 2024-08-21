#include <QApplication>
#include "primefinder.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    PrimeFinder finder;
    finder.show();

    return a.exec();
}
