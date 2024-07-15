#include "abstractregistrationfactory.h"
#include "studentregistration.h"
#include "guestregistration.h"

Registration *AbstractRegistrationFactory::createRegistration(Person p,QString choice, QString q, QString c)
{
    if (choice == "Registration")
    {
        return new Registration(p);
    }
    else if (choice == "StudentRegistration")
    {
        return new StudentRegistration(p,q);
    }
    else
    {
        return new GuestRegistration(p,c);
    }
}

