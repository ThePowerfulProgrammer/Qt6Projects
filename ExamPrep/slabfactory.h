#ifndef SLABFACTORY_H
#define SLABFACTORY_H

#include "chocolatefactory.h"
#include "slab.h"

class SlabFactory : public ChocolateFactory
{
public:
    Chocolate *createChocolate() override
    {
        return new Slab();
    }
};

#endif // SLABFACTORY_H
