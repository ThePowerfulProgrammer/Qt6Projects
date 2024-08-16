#ifndef BOOKWRITER_H
#define BOOKWRITER_H

#include <QFile>

class Book;
class QString;
class QtCore;
class QtXml;

class BookWriter
{
public:
    BookWriter(QString path);

    void saveBook(Book &b);
private:

    QFile file;
};

#endif // BOOKWRITER_H
