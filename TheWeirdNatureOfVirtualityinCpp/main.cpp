#include <QCoreApplication>
#include "registration.h"
#include "studentregistration.h"
#include <QDebug>

void callCalculateFee(Registration &r)
{
    qDebug() << r.calculateFee();
}

void printToString(Registration &r)
{
    qDebug() << r.toString();
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    Registration re(Person("Ash", "yt", "ash0301@gmail.com"));
    StudentRegistration s(Person("Ash", "yt", "ash0301@gmail.com"), "BSc Comp SCi");



    qDebug() << re.toString() << "\n";

    callCalculateFee(re);
    qDebug() << "\n";
    callCalculateFee(s);

    printToString(re);
    qDebug() << "\n";
    printToString(s);


    return a.exec();
}
