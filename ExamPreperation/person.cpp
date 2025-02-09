#include "person.h"

Person::Person()
{}

Person::Person(QString s, QDate d) : name(s), birthDate(d)
{

}

QDate Person::getBirthDate() const
{
    return birthDate;
}

void Person::setBirthDate(const QDate &newBirthDate)
{
    birthDate = newBirthDate;
}

QString Person::getName() const
{
    return name;
}

void Person::setName(const QString &newName)
{
    name = newName;
}
