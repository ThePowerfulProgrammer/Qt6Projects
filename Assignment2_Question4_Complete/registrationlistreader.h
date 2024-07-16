#ifndef REGISTRATIONLISTREADER_H
#define REGISTRATIONLISTREADER_H

#include <QXmlStreamReader>
#include <QList>
#include "registration.h"
#include "registrationfactory.h"


class RegistrationListReader
{
public:
    RegistrationListReader();

    QList<Registration*> readXML(QString path);

private:
    QList<Registration*> m_AttendeeList;

    // Factory implementation
    RegistrationFactory *creator;
};

#endif // REGISTRATIONLISTREADER_H
