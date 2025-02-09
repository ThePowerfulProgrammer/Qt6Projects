#ifndef FOOD_H
#define FOOD_H
#include "raylib.h"

/**

Entity intended to be consumed by a snake

A food object needs:
Size,
Position,
Color,

*/

class Food
{
public:
    Food();

    void setPosition();


    float size;
    Vector2 position;
    Color color;

};

#endif // FOOD_H
