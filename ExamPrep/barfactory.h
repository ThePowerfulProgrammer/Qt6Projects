#ifndef BARFACTORY_H
#define BARFACTORY_H
#include "chocolatefactory.h"
#include "bar.h"


class BarFactory : public ChocolateFactory
{
public:
    Chocolate* createChocolate() override
    {
        return new Bar();
    }
};

#endif // BARFACTORY_H
