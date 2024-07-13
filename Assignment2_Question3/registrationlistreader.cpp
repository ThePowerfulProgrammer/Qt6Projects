#include "registrationlistreader.h"
#include "person.h"
#include "studentregistration.h"
#include "guestregistration.h"
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
            qDebug()<< QString("Person(%1,%2,%3) ").arg(n).arg(a).arg(e);
            qDebug() << "Type : " <<t << "\n";
            if (t == "Registration")
            {
                Person p(n,a,e);
                Registration *r = new Registration(p);
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
                StudentRegistration *r = new StudentRegistration(p, QString("Undecided"));
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
                GuestRegistration *r = new GuestRegistration(p, QString("Visitor"));
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

    return m_AttendeeList;
}
