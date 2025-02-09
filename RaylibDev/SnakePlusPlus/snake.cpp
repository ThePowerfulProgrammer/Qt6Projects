#include <iostream>
#include "snake.h"

/// 540, 360
Snake::Snake()
    : size{20,20},
    position{530,350},
    speed{5,0},
    skinColor{169,71,255,255},
    segments()
{


    for (int i=0;i<3;i++)
    {
        Rectangle *segment = new Rectangle;

        segment->x = position.x - (25*i);
        segment->y = position.y;

        segments.push_back(segment);
    }


}


Snake::Snake(Vector2 s, Vector2 pos, Vector2 sp, Color sC)
    : size(s),
    position(pos),
    speed(sp),
    skinColor(sC),
    segments()
{


    for (int i=0;i<3;i++)
    {
        Rectangle *segment = new Rectangle;
        segment->x = position.x - (20*i);
        segment->y = position.y;

        segments.push_back(segment);
    }
}

Color Snake::getSkinColor() const
{
    return skinColor;
}

void Snake::setSkinColor(const Color &newSkinColor)
{
    skinColor = newSkinColor;
}


void Snake::addSegment()
{
    Rectangle *newSegment = new Rectangle;
    segments.push_back(newSegment);
}

void Snake::Move()
{
    position.x += speed.x;
    position.y += speed.y;

    segments[0]->x = position.x;
    segments[0]->y = position.y;

    for (int i=segments.size()-1; i> 0 ; i--)
    {
        segments[i]->x = segments[i-1]->x;
        segments[i]->y = segments[i-1]->y;
    }
}

Snake::~Snake()
{

    if (segments.size() > 0)
    {
        for (Rectangle *rec: segments)
        {
            delete rec;
            rec = nullptr;
        }
    }
}
