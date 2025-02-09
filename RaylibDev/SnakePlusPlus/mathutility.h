#ifndef MATHUTILITY_H
#define MATHUTILITY_H

#include "raylib.h"

class MathUtility
{
public:
    MathUtility();

    static bool inRange(unsigned low, unsigned high, unsigned x);
    static bool CheckCollision(Vector2 &vec1, Vector2 &vec2);
};

#endif // MATHUTILITY_H
