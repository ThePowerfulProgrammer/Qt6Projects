#include "registrationlist.h"
#include <QDebug>

bool RegistrationList::addRegistration(Registration *r)
{
    m_AttendeeList.append(r);
    return true;
}

bool RegistrationList::isRegistered(QString n)
{
    for (int i=0; i<m_AttendeeList.size(); i++)
    {
        qDebug() << n << " ?= " << m_AttendeeList[i]->getAttendee().getName() << "\n";
    }
    return false;
}

double RegistrationList::totalFee(QString t)
{

    return 0.0;
}

int RegistrationList::totalRegistration(QString a)
{
    return 0;
}

RegistrationList::~RegistrationList()
{
    for (Registration *r: m_AttendeeList)
    {
        delete r;
    }
}
