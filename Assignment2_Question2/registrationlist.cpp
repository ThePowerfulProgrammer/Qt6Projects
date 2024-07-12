#include "registrationlist.h"
#include <QDebug>
#include <QMetaProperty>

// complete
RegistrationList::RegistrationList() : m_AttendeeList(), m_RegisteredPayments()
{

}

// copy ctor
RegistrationList::RegistrationList(const RegistrationList &otherList)
{
    m_RegisteredPayments.clear();
    m_AttendeeList.clear();

    m_RegisteredPayments = otherList.m_RegisteredPayments;
    m_AttendeeList = otherList.m_AttendeeList;
}

// OverKILL
bool RegistrationList::addRegistration(Registration *r)
{
    for (int i=0;i<m_AttendeeList.size(); i++)
    {
        if ((m_AttendeeList[i]->getAttendee().getName().compare(r->getAttendee().getName()) == 0 )  &&
            (m_AttendeeList[i]->getAttendee().getEmail().compare(r->getAttendee().getEmail()) == 0) )
        {
            qDebug() << "Cannot add a registration with the same name and same email address \n";
            return false;
        }
    }
    m_AttendeeList.append(r);

    if (QString("Registration").compare(m_AttendeeList.last()->metaObject()->className()) == 0 )
    {
        if (m_RegisteredPayments.find("Registration") != m_RegisteredPayments.end())
        {
            m_RegisteredPayments["Registration"] += m_AttendeeList.last()->calculateFee();
        }
        else
        {
            m_RegisteredPayments["Registration"] = m_AttendeeList.last()->calculateFee();
        }
    }
    else if (QString("StudentRegistration").compare(m_AttendeeList.last()->metaObject()->className()) == 0)
    {
        if (m_RegisteredPayments.find("StudentRegistration") != m_RegisteredPayments.end())
        {
            m_RegisteredPayments["StudentRegistration"] += m_AttendeeList.last()->calculateFee();
        }
        else
        {
            m_RegisteredPayments["StudentRegistration"] = m_AttendeeList.last()->calculateFee();
        }

    }
    else
    {
        if (m_RegisteredPayments.find("GuestRegistration") != m_RegisteredPayments.end())
        {
            m_RegisteredPayments["GuestRegistration"] += m_AttendeeList.last()->calculateFee();
        }
        else
        {
            m_RegisteredPayments["GuestRegistration"] = m_AttendeeList.last()->calculateFee();
        }
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

// complete
double RegistrationList::totalFee(QString t)
{
    if (t=="All")
    {
        return m_RegisteredPayments["Registration"]
               + m_RegisteredPayments["StudentRegistration"]
               + m_RegisteredPayments["GuestRegistration"];
    }
    else if (t == "Registration" || t == "StudentRegistration" || t == "GuestRegistration")
    {
        return m_RegisteredPayments[t];
    }

    return 0.0;
}

// complete ???
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

QList<Registration *> RegistrationList::getAttendeeList()
{
    return m_AttendeeList;
}




// complete
RegistrationList::~RegistrationList()
{
    for (Registration *r : m_AttendeeList)
    {
        delete r;
    }
}

