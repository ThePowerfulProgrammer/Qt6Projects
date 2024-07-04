#ifndef REGISTRATIONLIST_H
#define REGISTRATIONLIST_H

#include <QList>

#include "registration.h"

class RegistrationList : public QObject
{
    Q_OBJECT

public:
    RegistrationList(); // I added a default ctor

    bool addRegistration(Registration *r);
    bool isRegistered(QString n);
    double totalFee(QString t);
    int totalRegistration(QString a);

    ~RegistrationList(); // deallocate memeory from the heap

    int m_StandardRegistered;
    int m_StudentRegistered;
    int m_GuestRegistered;

private:
    QList<Registration*> m_AttendeeList;

};

#endif // REGISTRATIONLIST_H
