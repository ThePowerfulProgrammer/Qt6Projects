#include <QApplication>
#include "validatordialog.h"
#include <QDate>


class TransactionMemento
{
public:
    TransactionMemento(QString customer, QDate date, QList<QString> items)
        : customer(customer), date(date), items(items) {}
private:
    QString customer;
    QDate date;
    QList<QString> items;

    // Grant access to Transaction class only
    friend class Transaction;
};

class Transaction
{
public:
    Transaction(QString c, QDate d, QList<QString> s);

    TransactionMemento *getBackup() const
    {
        return new TransactionMemento(customer, date, items);
    }


private:
    QString customer;
    QDate date;
    QList<QString> items;
};



int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    validatorDialog dialog;
    dialog.show();
    return a.exec();
}
