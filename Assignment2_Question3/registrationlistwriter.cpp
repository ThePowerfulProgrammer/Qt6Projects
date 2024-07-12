#include "registrationlistwriter.h"
#include "registration.h"
#include <QList>
#include <QDebug>


// write the objects of regList to a xml file at the specified path
RegistrationListWriter::RegistrationListWriter(QString path, RegistrationList &regList)
{
    QDomDocument document;
    QList<Registration*> tempList = regList.getAttendeeList();

    // root node
    QDomElement registrationListRoot = document.createElement("registrationlist");
    document.appendChild(registrationListRoot);

    for (int i=0;i<tempList.size();i++)
    {
        QDomElement registrationNode = document.createElement("registration");
        registrationNode.setAttribute("Type", tempList[i]->metaObject()->className());
        registrationListRoot.appendChild(registrationNode);

        QDomElement attendeeNode = document.createElement("attendee");
        registrationNode.appendChild(attendeeNode);

        QDomElement nameNode = document.createElement("name");
        attendeeNode.appendChild(nameNode);
        QDomText nameText = document.createTextNode(tempList[i]->getAttendee().getName());
        nameNode.appendChild(nameText);

        QDomElement affliationNode = document.createElement("affiliation");
        attendeeNode.appendChild(affliationNode );
        QDomText affliationText = document.createTextNode(tempList[i]->getAttendee().getAffliation());
        affliationNode.appendChild(affliationText);

        QDomElement emailNode = document.createElement("email");
        attendeeNode.appendChild(emailNode);
        QDomText emailText = document.createTextNode(tempList[i]->getAttendee().getEmail());
        emailNode.appendChild(emailText);

        QDomElement bookingDateNode = document.createElement("bookingdate");
        registrationNode.appendChild(bookingDateNode);
        QDomText bookingDateText = document.createTextNode(tempList[i]->getBookingDate().toString("dd.MM.yyyy"));
        bookingDateNode.appendChild(bookingDateText);

        QDomElement registrationFeeNode = document.createElement("registrationfee");
        registrationNode.appendChild(registrationFeeNode);
        QString fee = QString::number(tempList[i]->calculateFee());
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
