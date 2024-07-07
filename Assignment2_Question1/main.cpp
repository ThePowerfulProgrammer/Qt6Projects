#include <QApplication>
#include <QDebug>

#include "registrationdialog.h"


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);


    RegistrationDialog dialog;
    dialog.show();
    return a.exec();
}
