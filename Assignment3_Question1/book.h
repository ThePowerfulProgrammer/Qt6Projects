#ifndef BOOK_H
#define BOOK_H
#include <QString>
#include <QStringList>
#include <QDate>

class Book
{
public:
    Book();
    Book(QString t, QStringList a, QString i, QDate p);

    QString getTitle() const;
    void setTitle(const QString &newTitle);

    QStringList getAuthors() const;
    void setAuthors(const QStringList &newAuthors);

    QString getIsbn() const;
    void setIsbn(const QString &newIsbn);

    QDate getPublicationDate() const;
    void setPublicationDate(const QDate &newPublicationDate);



private:
    QString title;
    QStringList authors;
    QString isbn;
    QDate publicationDate;

};

#endif // BOOK_H
