#ifndef PERSON_H
#define PERSON_H

#include <QObject>
#include <QDate>

class Person : public QObject
{
    Q_OBJECT // allows for access to Signals and slots && access to MOC && access to Qt Reflective programming
    Q_PROPERTY(QString name READ getName WRITE setName CONSTANT)
    Q_PROPERTY(QDate birthDate READ getBirthDate WRITE setBirthDate CONSTANT)

public:
    explicit Person();
    Person(QString s, QDate d);

    QDate getBirthDate() const;
    void setBirthDate(const QDate &newBirthDate);

    QString getName() const;
    void setName(const QString &newName);

signals:

private:
    QString name;
    QDate birthDate;


};

#endif // PERSON_H
