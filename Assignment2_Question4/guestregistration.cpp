#include "guestregistration.h"


GuestRegistration::GuestRegistration(Person a, QString q) : Registration(a), m_Category(q)
{
    STANDARD_FEE = Registration::STANDARD_FEE*0.10;
}

double GuestRegistration::calculateFee()
{
    return STANDARD_FEE;
}

QString GuestRegistration::toString()
{
    QString studentRegString = Registration::toString();
    studentRegString.append(m_Category);

    return studentRegString;
}
