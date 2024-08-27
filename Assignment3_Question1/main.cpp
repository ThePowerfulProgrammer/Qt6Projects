#include <QApplication>
#include "bookinput.h"
#include <QDebug>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    BookInput *dialog = new BookInput();
    dialog->show();


    return a.exec();
}
