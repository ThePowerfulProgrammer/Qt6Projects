#include "studentregistration.h"


StudentRegistration::StudentRegistration(Person a, QString q) : Registration(a), m_Qualification(q)
{

}

double StudentRegistration::calculateFee()
{
    return Registration::calculateFee()/2.0;
}

QString StudentRegistration::toString()
{
    QString studentRegString = Registration::toString();
    studentRegString.append(m_Qualification);

    return studentRegString;

}
