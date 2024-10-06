#ifndef CHOCOLATE_H
#define CHOCOLATE_H
#include <QString>


class Chocolate
{
public:
    Chocolate();
    virtual QString toString() = 0;

private:

    QString m_Name;
    bool m_isVegan;
    static int serialNumber;
};

#endif // CHOCOLATE_H
