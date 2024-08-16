#include "bookinput.h"
#include "bookwriter.h"

#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QDebug>
#include <QLineEdit>
#include <QSpinBox>
#include <QDateEdit>
#include <QPushButton>
#include <QInputDialog>
#include <QLabel>
#include <QString>
#include <QFileDialog>

BookInput::BookInput(QWidget *parent) : QDialog(parent), authors(), books()
{
    addTitle = new QLineEdit(this);
    addTitle->setPlaceholderText("Title: ");

    addISBN = new QLineEdit(this);
    addISBN->setPlaceholderText("Isbn: ");

    addDate = new QDateEdit(this);
    addDate->setDate(QDate::currentDate());
    addDate->setCalendarPopup(true);

    numberOfAuthors = new QSpinBox(this);
    numberOfAuthors->setValue(1);
    numberOfAuthors->setRange(1,100);

    QLabel *label = new QLabel("Number of Authors: ", this);
    label->setBuddy(numberOfAuthors);

    submitBtn = new QPushButton("Submit", this);

    writeBtn = new QPushButton("Save", this);

    QHBoxLayout *firstRow = new QHBoxLayout();
    firstRow->addWidget(addTitle,2);
    firstRow->addWidget(addISBN,2);
    firstRow->addWidget(addDate,3);
    firstRow->addWidget(label,1);
    firstRow->addWidget(numberOfAuthors,1);

    QHBoxLayout *secondRow = new QHBoxLayout();
    secondRow->addWidget(submitBtn,Qt::AlignCenter);

    QHBoxLayout *thirdRow = new QHBoxLayout();
    thirdRow->addWidget(writeBtn);

    QVBoxLayout *mainLayout = new QVBoxLayout();
    mainLayout->addLayout(firstRow);
    mainLayout->addLayout(secondRow);
    mainLayout->addLayout(thirdRow);

    // S & S
    connect(submitBtn, SIGNAL(clicked()), this, SLOT(addAuthor()));
    connect(writeBtn, SIGNAL(clicked()), this, SLOT(writeToFile()));


    // set layout apperance
    setLayout(mainLayout);
    this->setMinimumSize(700,100);
}

void BookInput::addAuthor()
{
    if (addTitle->text() != "" && addISBN->text() != "")
    {
        for (int i=0; i<numberOfAuthors->value(); i++)
        {
            bool ok;
            QString name = QInputDialog::getText(this,"Author Details", QString("Author %1 ").arg(i+1), QLineEdit::Normal, "Name: ", &ok).trimmed();

            if (ok)
            {
                authors.append(name);
                qDebug() << "Authors: " << authors.size() << "\n";
                qDebug() << authors.last() << "\n";
            }
            else
            {
                qDebug() << "Cannot Process a blank Author name";
                i -=1;
            }
        }

        createBook();
        numberOfAuthors->setValue(1);
    }
    else
    {
        qDebug() << "Add Data to the fields";
    }

}

void BookInput::writeToFile()
{
    if (books.size() > 0)
    {
        QString path = QFileDialog::getSaveFileName(nullptr,"Create or Select XML File", QDir::currentPath(), "XML Files (*.xml)");

        if (path == "")
        {
            return;
        }

        BookWriter writer(path);

        for (int i=0; i<books.size();i++)
        {
            writer.saveBook(*books[i]);
        }
        books.clear();

    }
    else
    {
        qDebug() << "Nothing to write \n";
    }
}

void BookInput::createBook()
{
    Book *book = new Book();
    book->setTitle(addTitle->text());
    book->setIsbn(addISBN->text());
    book->setPublicationDate(addDate->date());

    addTitle->clear();
    addTitle->setPlaceholderText("Title: ");
    addISBN->clear();
    addISBN->setPlaceholderText("ISBN: ");


    QStringList listOfAuthors;
    for (int i=0;i<authors.size();i++)
    {
        listOfAuthors << authors[i];
    }

    book->setAuthors(listOfAuthors);
    books.append(book);

    authors.clear();
}







