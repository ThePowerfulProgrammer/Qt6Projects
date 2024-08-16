#include "bookwriter.h"

#include <QtCore>
#include <QtXml>
#include <QString>
#include <QTextStream>
#include <QStringList>
#include <QDebug>
#include "book.h"

BookWriter::BookWriter(QString path) : file(path)
{

}


void BookWriter::saveBook(Book &b)
{

    QDomDocument document;

    // root node
    QDomElement bookRoot = document.createElement("bookNode");
    document.appendChild(bookRoot);



    QDomElement titleNode = document.createElement(b.metaObject()->property(1).name());
    bookRoot.appendChild(titleNode);


    QDomText titleText = document.createTextNode(b.getTitle());
    titleNode.appendChild(titleText);

    QDomElement isbnNode = document.createElement(b.metaObject()->property(2).name());
    bookRoot.appendChild(isbnNode);
    QDomText isbnText = document.createTextNode(b.getIsbn());
    isbnNode.appendChild(isbnText);

    QDomElement dateNode = document.createElement(b.metaObject()->property(3).name());
    bookRoot.appendChild(dateNode);
    QDomText dateText = document.createTextNode(b.getPublicationDate().toString("yyyy/MM/dd"));
    dateNode.appendChild(dateText);



    QStringList list = b.getAuthors();

    for (int i=0; i<list.size(); i++)
    {
        QDomElement authorNode = document.createElement("author");
        bookRoot.appendChild(authorNode);
        QDomText authorText = document.createTextNode(list[i]);
        authorNode.appendChild(authorText);
    }

    if (!file.open(QIODevice::Append | QIODevice::Text))
    {
        qDebug() << "File error \n";
    }
    else
    {
        QTextStream stream(&file);
        stream << document.toString();
        file.close();
        qDebug() << "Written to file \n";
    }

}
