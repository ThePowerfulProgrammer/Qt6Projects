#include "registrationfactory.h"
#include "studentregistration.h"
#include "guestregistration.h"

Registration *RegistrationFactory::createRegistration(QString choice)
{
    if (choice == "Registration")
    {
        Person p("Emil", "yt","emilCosman@gmail.com");
        return new Registration(p);
    }
    else if (choice == "StudentRegistration")
    {
        Person p("Emila", "yt","emilCosman@gmail.com");
        return new StudentRegistration(p,"BA Law");
    }
    else
    {
        Person p("Emilly", "yt","emilCosman@gmail.com");
        return new GuestRegistration(p,"Visitor");
    }
}
