#include "person.h"


Person::Person(QString n, QString a, QString e) : m_Name(n), m_Affliation(a), m_Email(e)
{
}

QString Person::getName()
{
    return m_Name;
}

QString Person::getAffliation()
{
    return m_Affliation;
}

QString Person::getEmail()
{
    return m_Email;
}

QString Person::toString()
{
    return QString("%1 %2 %3").arg(m_Name).arg(m_Affliation).arg(m_Email);
}
