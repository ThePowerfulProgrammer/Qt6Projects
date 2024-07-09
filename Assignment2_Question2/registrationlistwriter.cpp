#include "registrationlistwriter.h"
#include <QDebug>


// write the objects of regList to a xml file at the specified path
RegistrationListWriter::RegistrationListWriter(QString path, RegistrationList &regList)
{
    QDomDocument document;

    // root node
    QDomElement registrationListRoot = document.createElement("registrationlist");
    document.appendChild(registrationListRoot);

    for (int i=0;i<regList.getAttendeeList().size();i++)
    {
        QDomElement registrationNode = document.createElement("registration");
        registrationNode.setAttribute("Type", regList.getAttendeeList()[i]->metaObject()->className());
        registrationListRoot.appendChild(registrationNode);

        QDomElement attendeeNode = document.createElement("attendee");
        registrationNode.appendChild(attendeeNode);

        QDomElement nameNode = document.createElement("name");
        attendeeNode.appendChild(nameNode);
        QDomText t = document.createTextNode(regList.getAttendeeList()[i]->getAttendee().getName());
        nameNode.appendChild(t);

        QDomElement affliationNode = document.createElement("affiliation");
        attendeeNode.appendChild(affliationNode );
        QDomText s = document.createTextNode(regList.getAttendeeList()[i]->getAttendee().getAffliation());
        affliationNode.appendChild(s);

        QDomElement emailNode = document.createElement("email");
        attendeeNode.appendChild(emailNode);
        QDomText u = document.createTextNode(regList.getAttendeeList()[i]->getAttendee().getEmail());
        emailNode.appendChild(u);

        QDomElement bookingDateNode = document.createElement("bookingdate");
        registrationNode.appendChild(bookingDateNode);
        QDomText v = document.createTextNode(regList.getAttendeeList()[i]->getBookingDate().toString("dd.MM.yyyy"));
        bookingDateNode.appendChild(v);

        QDomElement registrationFeeNode = document.createElement("registrationfee");
        registrationNode.appendChild(registrationFeeNode);
        QString fee = QString::number(regList.getAttendeeList()[i]->calculateFee());
        QDomText w = document.createTextNode(fee);
        registrationFeeNode.appendChild(w);
    }

    QFile file(path);
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text))
    {
        qDebug() << "File error: " << file.errorString() << "\n";
    }
    else
    {
        QTextStream stream(&file);
        stream << document.toString();
        file.close();
        qDebug() << "Written to file" << "\n";
    }
}

// C:/Qt6 Projects/Assignment2_Question2/MyXML.xml
