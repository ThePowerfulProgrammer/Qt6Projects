#include "studentregistration.h"

StudentRegistration::StudentRegistration(Person a, QString q): Registration(a), qualification(q)
{
    STANDARD_FEE = STANDARD_FEE/2;
}

QString StudentRegistration::getQualification() const
{
    return qualification;
}

void StudentRegistration::setQualification(const QString &newQualification)
{
    qualification = newQualification;
}

QString StudentRegistration::toString()
{
    QString rRepr = Registration::toString();
    return QString("%1 %2").arg(rRepr).arg(getQualification());
}

double StudentRegistration::calculateFee()
{

    return STANDARD_FEE;
}
