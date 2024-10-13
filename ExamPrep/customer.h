#ifndef CUSTOMER_H
#define CUSTOMER_H
#include <QString>

class Customer
{
public:
    Customer();
    Customer(QString n);
    ~Customer();


    QString getName() const;
    void setName(const QString &newName);

    QString listToXml() const;
    void listFromXml(QString s);

    QList<Customer*> *getList();

private:
    QString name;
    QList<Customer*> *list;


};

#endif // CUSTOMER_H
