#include "book.h"

Book::Book() : title(""), authors(QStringList() ), isbn(""), publicationDate(QDate::currentDate())
{

}

Book::Book(QString t, QStringList a, QString i, QDate p) : title(t), authors(a), isbn(i), publicationDate(p)
{

}

QString Book::getTitle() const
{
    return title;
}

void Book::setTitle(const QString &newTitle)
{
    title = newTitle;
}

QStringList Book::getAuthors() const
{
    return authors;
}

void Book::setAuthors(const QStringList &newAuthors)
{
    authors = newAuthors;
}

QString Book::getIsbn() const
{
    return isbn;
}

void Book::setIsbn(const QString &newIsbn)
{
    isbn = newIsbn;
}

QDate Book::getPublicationDate() const
{
    return publicationDate;
}

void Book::setPublicationDate(const QDate &newPublicationDate)
{
    publicationDate = newPublicationDate;
}
