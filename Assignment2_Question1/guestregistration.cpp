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
    const QMetaObject *metaObject = this->metaObject();
    qDebug() << "Class Name: " << metaObject->className() << "\n";
    qDebug() << "Class Name: " << metaObject->superClass() << "\n";
    QString studentRegString = Registration::toString();
    studentRegString.append(m_Category);

    return studentRegString;
}
