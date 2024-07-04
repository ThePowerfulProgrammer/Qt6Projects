#include "registrationlist.h"
#include <QDebug>

// complete
RegistrationList::RegistrationList() : m_AttendeeList(), m_StandardRegistered(0),
    m_StudentRegistered(0), m_GuestRegistered(0)
{

}

// complete
bool RegistrationList::addRegistration(Registration *r)
{
    for (int i=0;i<m_AttendeeList.size(); i++)
    {
        if ((m_AttendeeList[i]->getAttendee().getName() == r->getAttendee().getName())  &&
            (m_AttendeeList[i]->getAttendee().getEmail() == r->getAttendee().getEmail()) )
        {
            qDebug() << "Cannot add a registration with the same name and same email address \n";
            return false;
        }
    }
    m_AttendeeList.append(r);

    if (QString("Registration").compare(m_AttendeeList.last()->metaObject()->className()) == 0 )
    {
        m_StandardRegistered += 1;
    }
    else if (QString("StudentRegistration").compare(m_AttendeeList.last()->metaObject()->className()) == 0)
    {
        m_StudentRegistered += 1;
    }
    else
    {
        m_GuestRegistered += 1;
    }

    return true;
}

// complete
bool RegistrationList::isRegistered(QString n)
{
    for (int i=0;i<m_AttendeeList.size(); i++)
    {
        if (m_AttendeeList[i]->getAttendee().getName() == n)
        {
            return true;
        }
    }
    return false;
}


double RegistrationList::totalFee(QString t)
{
    double totalFees = 0.0;

    return totalFees;

}

int RegistrationList::totalRegistration(QString a)
{
    int totalRegistered = 0;
    for (int i=0;i<m_AttendeeList.size(); i++)
    {
        if (m_AttendeeList[i]->getAttendee().getAffliation() == a)
        {
            totalRegistered += 1;
        }
    }
    return totalRegistered;
}


// complete
RegistrationList::~RegistrationList()
{
    for (Registration *r: m_AttendeeList)
    {
        delete r;
    }
}
