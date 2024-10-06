#ifndef SLAB_H
#define SLAB_H

#include "chocolate.h"

class Slab : public Chocolate
{
public:
    Slab();

    QString toString();

private:

    int numberOfBlocks;

};

#endif // SLAB_H
