
#include <QApplication>
#include <QtCore>
#include <QtXml>
#include <QXmlStreamReader>
#include <QDebug>
#include <QFileDialog>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    // QDomDocument document;

    // // the root element
    // QDomElement registrationListRoot = document.createElement("RegistrationList");

    // // add it to the overall document
    // document.appendChild(registrationListRoot);

    // // add some elements to our parent
    // for (int c=0; c<1;c++)
    // {
    //     QDomElement registration = document.createElement("Registration");

    //     registration.setAttribute("Type: ", "Registration");

    //     registrationListRoot.appendChild(registration);

    //     for (int i=0;i<1;i++)
    //     {
    //         QDomElement attendee = document.createElement("attendee");
    //         registration.appendChild(attendee);

    //         for (int j=0; j<1;j++)
    //         {
    //             QDomElement name = document.createElement("name");
    //             QDomElement affiliation = document.createElement("affiliation");
    //             QDomElement email = document.createElement("email");

    //             attendee.appendChild(name);
    //             attendee.appendChild(affiliation);
    //             attendee.appendChild(email);
    //         }
    //         QDomElement bookingDate = document.createElement("bookingdate");
    //         registration.appendChild(bookingDate);
    //         QDomText t = document.createTextNode("Hllo World");
    //         bookingDate.appendChild(t);
    //         QDomElement registrationFee = document.createElement("registrationFee");
    //         registration.appendChild(registrationFee);
    //     }



    // }


    // Write XML to a file
    // QFile file("C:/Qt6 Projects/writingXML/MyXML.xml");
    // if (!file.open(QIODevice::WriteOnly | QIODevice::Text))
    // {
    //     qDebug() << "File error" << file.error() << "\n";
    //     return -1;
    // }
    // else
    // {
    //     QTextStream stream(&file);
    //     stream << document.toString();
    //     file.close();
    //     qDebug() << "Succesful";
    // }

    // read from xml file
    QString path = QFileDialog::getOpenFileName(nullptr, "Find XML File", QDir::currentPath(), "Xml Files (*.xml)");
    QFile readFile(path);
    if (!readFile.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        qDebug() << "File Error" << "Reading file errror " << readFile.error() << "\n";
        return -1;
    }
    else
    {
        QXmlStreamReader reader(&readFile);

        while(!reader.atEnd())
        {
            if (reader.isStartElement() && reader.name().toString() == "registration")
            {
                qDebug() << "Registration Type: " << reader.attributes().value("Type").toString() << "\n";
            }
            else if (reader.isStartElement() && reader.name().toString() == "name")
            {
                qDebug() << reader.readElementText(QXmlStreamReader::SkipChildElements) << "\n";
            }
            else if (reader.isStartElement() && reader.name().toString() == "affiliation")
            {
                qDebug() << reader.readElementText(QXmlStreamReader::SkipChildElements) << "\n";
            }
            else if (reader.isStartElement() && reader.name().toString() == "email")
            {
                qDebug() << reader.readElementText(QXmlStreamReader::SkipChildElements) << "\n";
            }
            else if (reader.isStartElement() && reader.name().toString() == "bookingdate")
            {
                qDebug() << reader.readElementText(QXmlStreamReader::SkipChildElements) << "\n";
            }
            else if (reader.isStartElement() && reader.name().toString() == "registrationfee")
            {
                qDebug() << reader.readElementText(QXmlStreamReader::SkipChildElements) << "\n";
            }

            reader.readNext();
        }
    }


    return a.exec();
}
