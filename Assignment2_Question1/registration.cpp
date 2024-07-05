#include "registration.h"
#include <QDebug>

Registration::Registration(Person a) : m_Attendee(a), STANDARD_FEE(500),
    m_BookingDate(QDate::currentDate())
{
}

QDate Registration::getBookingDate()
{
    return m_BookingDate;
}

Person Registration::getAttendee()
{
    return m_Attendee;
}

double Registration::calculateFee()
{
    return STANDARD_FEE;
}

QString Registration::toString()
{
    const QMetaObject *metaObject = this->metaObject();
    qDebug() << "Class Name: " << metaObject->className() << "\n";
    qDebug() << "Class Name: " << metaObject->superClass() << "\n";
    return QString("%1 %2 ").arg(m_Attendee.toString()).arg(m_BookingDate.toString("dd.MM.yyyy"));
}



