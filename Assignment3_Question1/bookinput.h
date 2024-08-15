#ifndef BOOKINPUT_H
#define BOOKINPUT_H

#include <QDialog>
#include "book.h"
class QPushButton;
class QDateEdit;
class QFileDialog;
class QSpinBox;
class QLineEdit;



class BookInput : public QDialog
{
    Q_OBJECT
public:
    BookInput(QWidget *parent = 0);

public slots:
    void addAuthor();
    void writeToFile();

private:

    // 1st row
    QLineEdit *addTitle;
    QLineEdit *addISBN;
    QDateEdit *addDate;
    QSpinBox *numberOfAuthors;
    QPushButton *submitBtn;
    QPushButton *writeBtn;

    // Container for authors
    QList<QString> authors;

    // Container for Books
    QList<Book> books;

    // function to create book object
    void createBook();
};

#endif // BOOKINPUT_H
