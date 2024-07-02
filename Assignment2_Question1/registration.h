#ifndef REGISTRATION_H
#define REGISTRATION_H

#include "person.h"
#include <QDate>
#include <QString>

// fwd declarartions


class Registration
{
public:
    Registration(Person a);
    Person getAttendee();
    QDate getBookingDate();
    double calculateFee();
    QString toString();


    double STANDARD_FEE;
    Person Attendee() const;

    void setBookingDate(const QDate &newBookingDate);

private:
    Person m_Attendee;
    QDate m_BookingDate;

};

#endif // REGISTRATION_H
