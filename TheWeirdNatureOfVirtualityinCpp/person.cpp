#include "person.h"

Person::Person() {}

Person::Person(QString n, QString a, QString e) : name(n),
    affiliation(a),
    email(e)
{

}

QString Person::toString()
{
    return QString("Name:%1 Affiliation:%2 Email:%3 ").arg(name).arg(affiliation).arg(email);
}

QString Person::getName() const
{
    return name;
}

void Person::setName(const QString &newName)
{
    name = newName;
}

QString Person::getAffiliation() const
{
    return affiliation;
}

void Person::setAffiliation(const QString &newAffiliation)
{
    affiliation = newAffiliation;
}

QString Person::getEmail() const
{
    return email;
}

void Person::setEmail(const QString &newEmail)
{
    email = newEmail;
}
