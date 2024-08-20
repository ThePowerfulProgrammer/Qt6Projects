#include <QApplication>
#include "validatordialog.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    validatorDialog dialog;
    dialog.show();
    return a.exec();
}
