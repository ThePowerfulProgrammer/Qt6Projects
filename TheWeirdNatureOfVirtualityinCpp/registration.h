#ifndef REGISTRATION_H
#define REGISTRATION_H
#include "person.h"
#include <QDate>

class Registration
{
public:
    Registration(Person a);

    Person getAttendee() const;
    void setAttendee(const Person &newAttendee);

    QDate getBookingDate() const;
    void setBookingDate(const QDate &newBookingDate);

    double calculateFee();

    virtual QString toString();

    double STANDARD_FEE;
private:
    Person attendee;
    QDate bookingDate;


};

#endif // REGISTRATION_H
