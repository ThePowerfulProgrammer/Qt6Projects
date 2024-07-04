#ifndef REGISTRATION_H
#define REGISTRATION_H

#include "person.h"
#include <QDate>
#include <QString>
#include <QMultiMap>

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
private:
    Person m_Attendee;
    QDate m_BookingDate;
            // Name: Email
    static QMultiMap<QString, QString> allRegistrations;


    // A:x@.com
    // B: x@.com
    // A:x@.com NO NO RedunDanT
};

#endif // REGISTRATION_H
