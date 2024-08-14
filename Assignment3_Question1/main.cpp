#include <QApplication>
#include "book.h"
#include "bookwriter.h"
#include <QDebug>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Book book;
    book.setTitle("Berserk Volume 1");
    book.setAuthors(QStringList() << "Kentaro Miura" << "Some Dude");
    book.setIsbn("1018356438389");
    book.setPublicationDate(QDate(2024,6,4));


    qDebug() << book.getTitle() << "\n";

    for (const auto&item: book.getAuthors())
    {
        qDebug() << item << "\n";
    }

    qDebug() << book.getIsbn() << "\n";

    qDebug() << book.getPublicationDate().toString("yyyy/MM/dd");


    BookWriter writer("./test.xml");

    writer.saveBook(book);
    return a.exec();
}
