#include "studentregistration.h"


StudentRegistration::StudentRegistration(Person a, QString q) : Registration(a), m_Qualification(q)
{
    STANDARD_FEE = Registration::STANDARD_FEE*0.5;
}

double StudentRegistration::calculateFee()
{
    return STANDARD_FEE;
}

QString StudentRegistration::toString()
{
    QString studentRegString = Registration::toString();
    studentRegString.append(m_Qualification);

    return studentRegString;

}
