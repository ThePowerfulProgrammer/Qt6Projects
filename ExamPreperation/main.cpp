#include <QApplication>
#include <QDebug>
#include <QObject>
#include <QMetaProperty>
#include <QMetaObject>
#include <QRegularExpression>

#include "person.h"
#include "product.h"








void outputMetaProperties(QObject* obj)
{
    const QMetaObject *metaObj = obj->metaObject();
    for (int i=metaObj->propertyOffset(); i<metaObj->propertyCount(); i++)
    {
        const QMetaProperty prop = metaObj->property(i);
        QString propertyName = prop.name(); // The name from Q_PROPERTY(Name)
        QVariant value = prop.read(obj); // The READ from Q_PROPERTY(NAME READ)
        QString valueStr = value.toString();

        qDebug() << propertyName << " " << valueStr << "\n";
    }
}


QVariant CustomTableModel::data(const QModelIndex &index, int role) const
{
    /* assume the rest is taken of*/
    switch(index.column())
    {
        case Cost:
        return QString::number(customer.cost, 'f', 2); // round to show 2 decimal places
    }
}

/*

<fileCounts>
 <file name="filename_1">
<count>23</count>
 <file name="filename_2">
<count>5</count>
 . . .
</fileCounts>

Using the partial code given below, and assuming that QStringList listOfFiles and
QList<int> counts are accessible by this code, complete the code as indicated so that
the required XML text above will be generated using DOM.
// set up any initial variables if required
// loop through all the items adding them to the XML text as necessary


QDomDocument document;
QDomElement root = document.createElement(“fileCounts”); creates parent node fileCounts
document.appendChild(root);

for (int i=0;i<listOfFiles.size();i++)
{
    QDomElement file = document.createElement("file");
    file.setAttribute("name", listOfFiles[i]);
    root.appendChild(file);



    QDomElement count = document.createElement("count");
    file.appendChild(count);
    QDomText countText = document.createTextNode(QString::number(counts[i]));
    count.appendChild(countText);
}



*/

/*
Assuming that the string list passed to WriteToXML has been saved to strList in the
class constructor, write the code for the doWrite() function so that each line in the
string list is written to file in the format above, using DOM. A portion of the code is given
below and you have to add the missing parts in the appropriate places.

void WriteToXML::doWrite()
{
    QDomDocument doc;
    QDomElement root = doc.createElement("communications");
    doc.appendChild(root);

    foreach (QString s, strList)
    {
        // Split the line into channel and message parts
        QStringList parts = s.split(": ", Qt::SkipEmptyParts);
        if (parts.size() != 2)
            continue; // Skip if the line doesn't have both parts

        QString channel = parts[0];
        QString messageContent = parts[1];

        // Create XML elements
        QDomElement communication = doc.createElement("communication");
        communication.setAttribute("channel", channel.trimmed());

        QDomElement message = doc.createElement("message");
        QDomText messageText = doc.createTextNode(messageContent.trimmed());
        message.appendChild(messageText);

        // Build the XML structure
        communication.appendChild(message);
        root.appendChild(communication);
    }

    QFile file("data.xml");
    if (file.open(QIODevice::WriteOnly))
    {
        QTextStream out(&file);
        out << doc.toString();
        file.close();
    }
}

*/


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    Person *p1 = new Person("Ash", QDate::currentDate());
    Product *product1 = new Product("Soap", 12.50);

    outputMetaProperties(p1);
    outputMetaProperties(product1);

    QRegularExpression re;
    re.setPattern("(vegan chocolate| vegan chocolates)"); // but this this wrong

    // QString pattern{"\\bvegan chocolate[s]?\\b"};




    return a.exec();
}
