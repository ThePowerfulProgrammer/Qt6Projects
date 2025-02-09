#include "product.h"

Product::Product()
{}

Product::Product(QString name, double price) : name(name), price(price)
{

}

void Product::setName(const QString &newName)
{
    name = newName;
}

QString Product::getName() const
{
    return name;
}

double Product::getPrice() const
{
    return price;
}

void Product::setPrice(double newPrice)
{
    price = newPrice;
}
