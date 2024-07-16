#ifndef REGISTRATIONLISTWRITER_H
#define REGISTRATIONLISTWRITER_H

#include <QtCore>
#include <QtXml>
#include "registrationlist.h"
class QTextStream;
class QString;

class RegistrationListWriter
{
public:
    RegistrationListWriter(QString path, RegistrationList &reglist);

};

#endif // REGISTRATIONLISTWRITER_H
