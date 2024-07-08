#ifndef REGISTRATIONLIST_H
#define REGISTRATIONLIST_H

#include "registration.h"

#include <QList>
#include <QMap>



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

private:
    QMap<QString, double> m_RegisteredPayments;
    QList<Registration*> m_AttendeeList;
};

#endif // REGISTRATIONLIST_H
