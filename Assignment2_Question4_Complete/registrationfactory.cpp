#include "registrationfactory.h"
#include "person.h"
#include "studentregistration.h"
#include "guestregistration.h"

RegistrationFactory* RegistrationFactory::singleton_m = nullptr;

Registration *RegistrationFactory::FactoryMethod(QString t, Person p, QString additionalInformation)
{
    if (t == "Registration")
    {
        Registration *r = new Registration(p);
        return r;
    }
    else if (t == "StudentRegistration")
    {
        Registration *r = new StudentRegistration(p, additionalInformation);
        return r;
    }
    else if (t == "GuestRegistration")
    {
        Registration *r = new GuestRegistration(p, additionalInformation);
        return r;
    }

    return nullptr;
}

RegistrationFactory *RegistrationFactory::GetInstance()
{
    if (singleton_m == nullptr)
    {
        singleton_m = new RegistrationFactory();
    }
    return singleton_m;
}

RegistrationFactory::RegistrationFactory()
{

}
