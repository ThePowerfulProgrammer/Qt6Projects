#ifndef REGISTRATIONLISTREADER_H
#define REGISTRATIONLISTREADER_H

#include <QXmlStreamReader>
#include <QFileDialog>
#include <QList>
#include <QDebug>
#include "registration.h"
#include "registrationlist.h"


class RegistrationListReader
{
public:
    RegistrationListReader();

    RegistrationList readFile(QString path);

private:
    RegistrationList list;
};

#endif // REGISTRATIONLISTREADER_H
