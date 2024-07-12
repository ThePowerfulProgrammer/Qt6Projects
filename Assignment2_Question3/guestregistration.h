#ifndef GUESTREGISTRATION_H
#define GUESTREGISTRATION_H

#include "registration.h"

class GuestRegistration : public Registration
{
    Q_OBJECT
public:
    GuestRegistration(Person a, QString q);
    double calculateFee();
    QString toString();

private:
    QString m_Category;

};

#endif // GUESTREGISTRATION_H
