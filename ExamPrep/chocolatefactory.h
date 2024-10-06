#ifndef CHOCOLATEFACTORY_H
#define CHOCOLATEFACTORY_H
#include "chocolate.h"

class ChocolateFactory
{
public:
    ChocolateFactory();

    virtual Chocolate* createChocolate() = 0;

    virtual ~ChocolateFactory() {};
};

#endif // CHOCOLATEFACTORY_H
