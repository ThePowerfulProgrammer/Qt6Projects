#ifndef PERSON_H
#define PERSON_H
#include <QString>

class Person
{
public:
    Person();
    Person(QString n, QString a, QString e);
    QString toString();

    QString getName() const;
    void setName(const QString &newName);

    QString getAffiliation() const;
    void setAffiliation(const QString &newAffiliation);

    QString getEmail() const;
    void setEmail(const QString &newEmail);

private:
    QString name;
    QString affiliation;
    QString email;
};

#endif // PERSON_H
