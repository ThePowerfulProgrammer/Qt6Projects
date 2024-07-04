#ifndef REGISTRATION_H
#define REGISTRATION_H

#include "person.h"
#include <QDate>
#include <QString>

// fwd declarartions


class Registration : public QObject
{
    Q_OBJECT



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
};

#endif // REGISTRATION_H
