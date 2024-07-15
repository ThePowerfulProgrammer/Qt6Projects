#ifndef REGISTRATIONFACTORY_H
#define REGISTRATIONFACTORY_H

#include "registration.h"
#include "abstractregistrationfactory.h"
#include "person.h"
#include <memory.h>
#include <QString>

class RegistrationFactory : public AbstractRegistrationFactory
{
public:
    RegistrationFactory() = default;
    Registration *createRegistration(Person p,QString choice, QString q, QString c);

};

#endif // REGISTRATIONFACTORY_H
