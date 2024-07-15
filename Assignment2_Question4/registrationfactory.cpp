#include "registrationfactory.h"


Registration *RegistrationFactory::createRegistration(Person p,QString choice, QString q, QString c)
{
    return AbstractRegistrationFactory::createRegistration(p,choice,q,c);
}
