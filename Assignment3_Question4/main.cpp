#include <QApplication>
#include <QThread>

#include "primeDialog.h"



int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    PrimeDialog dialog;
    dialog.show();
    return a.exec();
}
