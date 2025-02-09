#ifndef PRODUCT_H
#define PRODUCT_H

#include <QObject>

class Product : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString name READ getName WRITE setName CONSTANT)
    Q_PROPERTY(double price READ getPrice WRITE setPrice CONSTANT)

public:
    explicit Product();
    Product(QString name,double price);


    void setName(const QString &newName);
    QString getName() const;

    double getPrice() const;
    void setPrice(double newPrice);



signals:

private:
    QString name;
    double price;
};

#endif // PRODUCT_H
