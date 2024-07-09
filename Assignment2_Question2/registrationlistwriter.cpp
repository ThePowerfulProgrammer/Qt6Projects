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
        QDomText nameText = document.createTextNode(regList.getAttendeeList()[i]->getAttendee().getName());
        nameNode.appendChild(nameText);

        QDomElement affliationNode = document.createElement("affiliation");
        attendeeNode.appendChild(affliationNode );
        QDomText affliationText = document.createTextNode(regList.getAttendeeList()[i]->getAttendee().getAffliation());
        affliationNode.appendChild(affliationText);

        QDomElement emailNode = document.createElement("email");
        attendeeNode.appendChild(emailNode);
        QDomText emailText = document.createTextNode(regList.getAttendeeList()[i]->getAttendee().getEmail());
        emailNode.appendChild(emailText);

        QDomElement bookingDateNode = document.createElement("bookingdate");
        registrationNode.appendChild(bookingDateNode);
        QDomText bookingDateText = document.createTextNode(regList.getAttendeeList()[i]->getBookingDate().toString("dd.MM.yyyy"));
        bookingDateNode.appendChild(bookingDateText);

        QDomElement registrationFeeNode = document.createElement("registrationfee");
        registrationNode.appendChild(registrationFeeNode);
        QString fee = QString::number(regList.getAttendeeList()[i]->calculateFee());
        QDomText feeText = document.createTextNode(fee);
        registrationFeeNode.appendChild(feeText);
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
