#include "guestregistration.h"


GuestRegistration::GuestRegistration(Person a, QString q) : Registration(a), m_Category(q)
{

}

double GuestRegistration::calculateFee()
{
    return Registration::calculateFee()*0.10;
}

QString GuestRegistration::toString()
{
    QString studentRegString = Registration::toString();
    studentRegString.append(m_Category);

    return studentRegString;
}
