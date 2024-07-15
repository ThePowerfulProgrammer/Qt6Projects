#include "registrationlistreader.h"
#include "person.h"
#include "studentregistration.h"
#include "guestregistration.h"
#include "abstractregistrationfactory.h"
#include "registrationfactory.h"
#include <QFile>
#include <QDebug>

RegistrationListReader::RegistrationListReader() {}

QList<Registration *> RegistrationListReader::readXML(QString path)
{
    QFile file(path);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text) )
    {
        QList<Registration*> list;
        return list;
    }

    QXmlStreamReader reader(&file);
    QString t = "";
    QString n = "";
    QString a = "";
    QString e = "";
    QString date = "";
    AbstractRegistrationFactory *factory = new RegistrationFactory();

    while (!reader.atEnd())
    {
        if (reader.isStartElement() && reader.name().toString() == "registration")
        {
            t = reader.attributes().value("Type").toString();
        }
        else if (reader.isStartElement() && reader.name().toString() == "name")
        {
            n = reader.readElementText(QXmlStreamReader::SkipChildElements);
        }
        else if (reader.isStartElement() && reader.name().toString() == "affiliation")
        {
            a = reader.readElementText(QXmlStreamReader::SkipChildElements);
        }
        else if (reader.isStartElement() && reader.name().toString() == "email")
        {
            e = reader.readElementText(QXmlStreamReader::SkipChildElements);
        }
        else if (reader.isStartElement() && reader.name().toString() == "bookingdate")
        {
            date = reader.readElementText(QXmlStreamReader::SkipChildElements);
        }

        if (t != "" && n != "" && a != "" && e != "" && date != "")
        {
            if (t == "Registration")
            {
                Person p(n,a,e);
                // Registration *r = new Registration(p);
                Registration *r = factory->createRegistration(p,"Registration", "", "");
                r->setBookingDate(QDate::fromString(date, "dd.MM.yyyy"));
                m_AttendeeList.append(r);
                t = "";
                n = "";
                a = "";
                e = "";
                date = "";
            }
            else if (t == "StudentRegistration")
            {
                Person p(n,a,e);

                Registration *sreg = factory->createRegistration(p,"StudentRegistration", "Undecided", "");
                StudentRegistration *r= dynamic_cast<StudentRegistration*>(sreg);
                r->setBookingDate(QDate::fromString(date, "dd.MM.yyyy"));
                m_AttendeeList.append(r);
                t = "";
                n = "";
                a = "";
                e = "";
            }
            else
            {
                Person p(n,a,e);

                Registration *greg = factory->createRegistration(p,"GuestRegistration", "", "Visitor");
                GuestRegistration *r= dynamic_cast<GuestRegistration*>(greg);
                r->setBookingDate(QDate::fromString(date, "dd.MM.yyyy"));

                m_AttendeeList.append(r);
                t = "";
                n = "";
                a = "";
                e = "";
            }
        }
        reader.readNext();
    }
    delete factory;

    return m_AttendeeList;
}
