#ifndef REGISTRATIONFACTORY_H
#define REGISTRATIONFACTORY_H
#include "registration.h"
#include "person.h"


#include <QString>

class RegistrationFactory
{
public:
    Registration *FactoryMethod(QString t,Person p, QString additionalInformation);

    static RegistrationFactory *GetInstance();

    RegistrationFactory(RegistrationFactory &other) = delete;
    void operator=(const RegistrationFactory &) = delete;

protected:
    RegistrationFactory();

    static RegistrationFactory* singleton_m;
};


#endif // REGISTRATIONFACTORY_H
