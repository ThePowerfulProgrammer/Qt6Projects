#ifndef SNAKE_H
#define SNAKE_H

#include <vector>
#include "raylib.h"



/*
A snake needs a size(width,height),
A color,
A starting Position(x,y),
A speed (sx, sy)
An array of segments

A snake will be drawn and controlled as a series of rects :)
*/


class Snake
{
public:
    Snake();
    Snake(Vector2 s, Vector2 pos, Vector2 sp, Color sC);
    ~Snake();

    void Move();
    void addSegment();

    Vector2 size;
    Vector2 position;
    Vector2 speed;
    Color skinColor;
    std::vector<Rectangle*> segments;

    Color getSkinColor() const;
    void setSkinColor(const Color &newSkinColor);
};

#endif // SNAKE_H
