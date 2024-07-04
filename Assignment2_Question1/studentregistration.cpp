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
    const QMetaObject *metaObject = this->metaObject();
    qDebug() << "Class Name: " << metaObject->className() << "\n";
    qDebug() << "Class Name: " << metaObject->superClass() << "\n";
    QString studentRegString = Registration::toString();
    studentRegString.append(m_Qualification);

    return studentRegString;

}
