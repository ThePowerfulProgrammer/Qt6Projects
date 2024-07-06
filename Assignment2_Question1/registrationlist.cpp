#include "registrationlist.h"
#include <QDebug>
#include <QMetaProperty>

// complete
RegistrationList::RegistrationList() : m_AttendeeList(), m_StandardRegistered(0),
    m_StudentRegistered(0), m_GuestRegistered(0), m_RegisteredPayments()
{

}

// OverKILL
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
        m_StudentRegistered += 1;

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
        m_GuestRegistered += 1;
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
    if (m_RegisteredPayments.find(t) == m_RegisteredPayments.end())
    {
        return m_RegisteredPayments["Registration"]
               + m_RegisteredPayments["StudentRegistration"]
               + m_RegisteredPayments["GuestRegistration"];
    }
    for (int i = 0; i< this->metaObject()->methodCount(); ++i)
    {
        qDebug() << this->metaObject()->method(i).name();
    }

    return m_RegisteredPayments[t];
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


// complete
RegistrationList::~RegistrationList()
{


    for (Registration *r: m_AttendeeList)
    {
        delete r;
    }
}
