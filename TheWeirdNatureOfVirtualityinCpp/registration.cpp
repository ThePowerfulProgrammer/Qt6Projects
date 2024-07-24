#include "registration.h"

Registration::Registration(Person a) : attendee(a),
    bookingDate(QDate::currentDate()),
    STANDARD_FEE(500)
{

}

Person Registration::getAttendee() const
{
    return attendee;
}

void Registration::setAttendee(const Person &newAttendee)
{
    attendee = newAttendee;
}

QDate Registration::getBookingDate() const
{
    return bookingDate;
}

void Registration::setBookingDate(const QDate &newBookingDate)
{
    bookingDate = newBookingDate;
}

double Registration::calculateFee()
{
    return STANDARD_FEE;
}

QString Registration::toString()
{
    QString pRepr = attendee.toString();
    return QString("%1 Email:%2 Fee:%3").arg(pRepr).arg(getBookingDate().toString("dd.MM.yyyy")).arg(QString::number(calculateFee()));
}
