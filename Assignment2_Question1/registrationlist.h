#ifndef REGISTRATIONLIST_H
#define REGISTRATIONLIST_H

#include <QList>

#include "registration.h"

class RegistrationList :  public QObject
{
    Q_OBJECT

public:

    bool addRegistration(Registration *r);
    bool isRegistered(QString n);
    double totalFee(QString t);
    int totalRegistration(QString a);

    ~RegistrationList(); // deallocate memeory from the heap

private:
    QList<Registration*> m_AttendeeList;
};

#endif // REGISTRATIONLIST_H
