#ifndef CHOCOLATE_H
#define CHOCOLATE_H
#include <QString>

class Chocolate
{
public:
    Chocolate(QString n="", bool flag=false);
    virtual QString toString() = 0; // must be pure virtual

    virtual ~Chocolate(); // if not virtual then child class destructors are not called, so this is important

protected:
    QString name;
    bool isVegan;
    int serialNumber;

private:
    static int count;
};

#endif // CHOCOLATE_H
