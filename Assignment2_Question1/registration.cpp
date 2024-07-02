#include "registration.h"


Registration::Registration(Person a) : m_Attendee(a), STANDARD_FEE(500), m_BookingDate(QDate::currentDate())
{

}

QDate Registration::getBookingDate()
{
    return m_BookingDate;
}

Person Registration::Attendee() const
{
    return m_Attendee;
}

double Registration::calculateFee()
{
    return STANDARD_FEE;
}

QString Registration::toString()
{
    return QString("%1 %2 %3").arg(m_Attendee.toString()).arg(m_BookingDate.toString("dd.MM.yyyy")).arg( QString::number(calculateFee())) ;
}



