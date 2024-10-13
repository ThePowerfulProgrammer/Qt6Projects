#include "customer.h"

Customer::Customer() {}

Customer::Customer(QString n)
{

}

Customer::~Customer()
{

}

QString Customer::getName() const
{
    return name;
}

void Customer::setName(const QString &newName)
{
    name = newName;
}

QString Customer::listToXml() const
{

}

void Customer::listFromXml(QString s)
{

}

QList<Customer *> *Customer::getList()
{

}
