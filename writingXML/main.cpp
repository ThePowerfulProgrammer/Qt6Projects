#include <QCoreApplication>
#include <QtCore>
#include <QtXml>
#include <QDebug>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QDomDocument document;

    // the root element
    QDomElement registrationListRoot = document.createElement("RegistrationList");

    // add it to the overall document
    document.appendChild(registrationListRoot);

    // add some elements to our parent
    for (int c=0; c<1;c++)
    {
        QDomElement registration = document.createElement("Registration");

        registration.setAttribute("Type: ", "Registration");

        registrationListRoot.appendChild(registration);

        for (int i=0;i<1;i++)
        {
            QDomElement attendee = document.createElement("attendee");
            registration.appendChild(attendee);

            for (int j=0; j<1;j++)
            {
                QDomElement name = document.createElement("name");
                QDomElement affiliation = document.createElement("affiliation");
                QDomElement email = document.createElement("email");

                attendee.appendChild(name);
                attendee.appendChild(affiliation);
                attendee.appendChild(email);
            }
            QDomElement bookingDate = document.createElement("bookingdate");
            registration.appendChild(bookingDate);
            QDomText t = document.createTextNode("Hllo World");
            bookingDate.appendChild(t);
            QDomElement registrationFee = document.createElement("registrationFee");
            registration.appendChild(registrationFee);
        }



    }


    // Write XML to a file
    QFile file("C:/Qt6 Projects/writingXML/MyXML.xml");
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text))
    {
        qDebug() << "File error" << file.error() << "\n";
        return -1;
    }
    else
    {
        QTextStream stream(&file);
        stream << document.toString();
        file.close();
        qDebug() << "Succesful";
    }
    return a.exec();
}
