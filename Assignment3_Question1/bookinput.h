#ifndef BOOKINPUT_H
#define BOOKINPUT_H

#include <QDialog>
#include <QLineEdit>
#include <QDateEdit>
#include <QFileDialog>
#include <QSpinBox>

#include "book.h"
#include "bookwriter.h"


class BookInput : public QDialog
{
public:
    BookInput();

private:

    // 1st row
    QLineEdit *addTitle;
    QLineEdit *addISBN;
    QDateEdit *addDate;
    QSpinBox *numberOfAuthors;






};

#endif // BOOKINPUT_H
