#ifndef BOOK_H
#define BOOK_H
#include <QString>
#include <QStringList>
#include <QDate>
#include <QObject>

class Book: public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString title READ getTitle WRITE setTitle   NOTIFY titleChanged)
    Q_PROPERTY(QString isbn READ getIsbn WRITE setIsbn NOTIFY isbnChanged)
    Q_PROPERTY(QDate publicationDate READ getPublicationDate WRITE setPublicationDate NOTIFY publicationDateChanged)

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

signals:
    void titleChanged();
    void isbnChanged();
    void publicationDateChanged();

private:
    QString title;
    QStringList authors;
    QString isbn;
    QDate publicationDate;

};

#endif // BOOK_H
