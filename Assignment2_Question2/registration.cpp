#include "registration.h"
#include <QString>

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
    return QString("%1 %2 ").arg(m_Attendee.toString()).arg(m_BookingDate.toString("dd.MM.yyyy"));
}

void Registration::setBookingDate(const QDate &newBookingDate)
{
    m_BookingDate = newBookingDate;
}



