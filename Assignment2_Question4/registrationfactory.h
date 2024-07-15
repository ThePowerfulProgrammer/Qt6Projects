#ifndef REGISTRATIONFACTORY_H
#define REGISTRATIONFACTORY_H

#include "registration.h"
#include <memory.h>
#include <QString>

class RegistrationFactory
{
public:
    RegistrationFactory() = default;
    static Registration *createRegistration(QString choice);

};

#endif // REGISTRATIONFACTORY_H
