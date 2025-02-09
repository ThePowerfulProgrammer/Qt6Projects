#include "mathutility.h"

MathUtility::MathUtility() {}

bool MathUtility::inRange(unsigned int low, unsigned int high, unsigned int x)
{
    // snake = {100,124}
    // food = {95,124}
    return ( (low <= x) &&  (x<= high) );

    // ( 100-10 <= 95 && 95 <= 110 )
}

bool MathUtility::CheckCollision(Vector2 &vec1, Vector2 &vec2 )
{
    return inRange(vec1.x  - 10, vec1.x + 10, vec2.x ) && inRange( vec1.y - 10, vec1.y + 10, vec2.y );

}
