#include "studentregistration.h"


StudentRegistration::StudentRegistration(Person a, QString q) : Registration(a), m_Qualification(q)
{
    STANDARD_FEE = Registration::STANDARD_FEE*0.5;
}

double StudentRegistration::calculateFee()
{
    double originalFee = Registration::calculateFee();
    qDebug() << "Student Fee running";
    return originalFee/2.0;
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
