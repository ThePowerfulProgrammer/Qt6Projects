#ifndef PERSON_H
#define PERSON_H

#include <QString>


class Person
{
public:
    Person(QString n, QString a, QString e);

    QString getName();
    QString getAffliation();
    QString getEmail();
    QString toString();

private:
    QString m_Name;
    QString m_Affliation;
    QString m_Email;

};

#endif // PERSON_H
