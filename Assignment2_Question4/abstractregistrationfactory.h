#ifndef ABSTRACTREGISTRATIONFACTORY_H
#define ABSTRACTREGISTRATIONFACTORY_H

#include "registration.h"
#include "person.h"
#include <memory.h>
#include <QString>

class AbstractRegistrationFactory
{
public:
    AbstractRegistrationFactory() = default;
    virtual Registration *createRegistration(Person p,QString choice, QString q, QString c);

};

#endif // ABSTRACTREGISTRATIONFACTORY_H
