#include "chocolate.h"


int Chocolate::count = 1;

Chocolate::Chocolate(QString n, bool flag)
    : name(n), isVegan(flag)
{
    serialNumber = count;
    count +=1;
}

Chocolate::~Chocolate()
{
    // implemented in child class
}

QString Chocolate::toString()
{
    // pure virtual method can be defined in base class
    // this part is common to all derived  classes
    // base class implementation is used in all child classess

    QString outString(QString("Name: %1, Vegan: %2, Serial Number: %3").arg(name).arg(isVegan).arg(serialNumber));

    return outString;

}
