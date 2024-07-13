#ifndef REGISTRATIONLISTREADER_H
#define REGISTRATIONLISTREADER_H

#include <QXmlStreamReader>
#include <QList>
#include "registration.h"

class RegistrationListReader
{
public:
    RegistrationListReader();

    QList<Registration*> readXML(QString path);

private:
    QList<Registration*> m_AttendeeList;
};

#endif // REGISTRATIONLISTREADER_H
