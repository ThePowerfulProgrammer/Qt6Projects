#include <QApplication>
#include "person.h"
#include "registration.h"
#include <QDebug>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Person p1("Azura", "Affliated with the dogs of Doom", "pup@puppers.com");
    Registration reg1(p1);


    qDebug() << p1.getName() << " " << p1.getAffliation() << " " << p1.getEmail() << "\n";
    qDebug() << p1.toString() << "\n";

    qDebug() << reg1.toString() << "\n";
    return a.exec();
}
