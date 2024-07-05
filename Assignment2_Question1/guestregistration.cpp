#include "guestregistration.h"


GuestRegistration::GuestRegistration(Person a, QString q) : Registration(a), m_Category(q)
{
    STANDARD_FEE = Registration::STANDARD_FEE*0.10;
}

double GuestRegistration::calculateFee()
{
    double originalFee = Registration::calculateFee();
    qDebug() << "Guest Fee running";
    return originalFee*0.10;
}

QString GuestRegistration::toString()
{
    const QMetaObject *metaObject = this->metaObject();
    qDebug() << "Class Name: " << metaObject->className() << "\n";
    qDebug() << "Class Name: " << metaObject->superClass() << "\n";
    QString studentRegString = Registration::toString();
    studentRegString.append(m_Category);

    return studentRegString;
}
