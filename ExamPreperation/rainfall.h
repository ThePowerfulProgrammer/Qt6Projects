#ifndef RAINFALL_H
#define RAINFALL_H

#include <QObject>
#include <QDate>

/*
The class responsible for holding rainfall data has been enhanced with reflective capabilities.
Specifically, a getData() function has been introduced to consolidate all the data within the
class into a single string. This function is associated with a property named data and is
accessible exclusively through the class's meta-object system. Importantly, the getData()
function is designed for internal use by the meta-object and is intentionally hidden from direct
access by users of the class. Write the class definition for this class showing how this would
be set up. You are not required to include functionality or data members not mentioned above,
or to code the implementation of the getData() function.
*/


class RainFall : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString data READ getData)

public:
    RainFall();
    QString toXML();


    QString getData();

private:
    QString data;


    QString m_station;
    QDate m_date;
    QString m_amtOfRainFall;

};

#endif // RAINFALL_H
