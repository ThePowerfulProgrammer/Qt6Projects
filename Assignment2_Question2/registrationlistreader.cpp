#include "registrationlistreader.h"
#include "studentregistration.h"
#include "guestregistration.h"

RegistrationListReader::RegistrationListReader() : list()
{

}

RegistrationList RegistrationListReader::readFile(QString path)
{
    QFile readFile(path);
    if (!readFile.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        qDebug() << "File Error: " << readFile.error() << "\n";
        return list;
    }
    else
    {
        QXmlStreamReader reader(&readFile);
        QString t = "";
        QString n = "";
        QString a = "";
        QString e = "";

        QString d = "";
        QString fee = "";

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
                d = reader.readElementText(QXmlStreamReader::SkipChildElements);
            }
            else if (reader.isStartElement() && reader.name().toString() == "registrationfee")
            {
                fee = reader.readElementText(QXmlStreamReader::SkipChildElements);
            }

            if (t != "" && n != "" && a != "" && e != "" && d != "" && fee != "")
            {
                Person p(n,a,e);
                if (t == "Registration")
                {
                    Registration *r = new Registration(p);
                    list.addRegistration(r);
                    t = "";
                    n = "";
                    a = "";
                    e = "";
                    d = "";
                    fee = "";

                }
                else if (t == "StudentRegistration")
                {
                    StudentRegistration *s = new StudentRegistration(p, "N/A");
                    list.addRegistration(s);
                    t = "";
                    n = "";
                    a = "";
                    e = "";
                    d = "";
                    fee = "";
                }
                else
                {
                    GuestRegistration *g = new GuestRegistration(p, "N/A");
                    list.addRegistration(g);
                    t = "";
                    n = "";
                    a = "";
                    e = "";
                    d = "";
                    fee = "";
                }

            }

            reader.readNext();

        }
    }
    return list;
}
