#include <iostream>

#include "raylib.h"
#include "snake.h"
#include "food.h"
#include "mathutility.h"

Snake *snake = new Snake;
Food food;

// init the entities for the first frame if needed
void startGame()
{

}

// Initial drawing and handles all further rendering to the window
void draw()
{
    // draw snake
    DrawRectangle(snake->position.x, snake->position.y, snake->size.x, snake->size.y, snake->skinColor);
    DrawCircle(food.position.x, food.position.y,food.size,food.color);

    for (int i=0; i < snake->segments.size(); i++)
    {
        std::cout << snake->segments[i]->x << "," << snake->segments[i]->y << "\n";
        DrawRectangle(snake->segments[i]->x, snake->segments[i]->y, snake->size.x, snake->size.y, snake->getSkinColor()  );
    }



}

// Handles the interactions in the game
void play()
{
    if (IsKeyPressed( KEY_W ) && (snake->speed.y != 5) )
    {
        snake->speed.y = -5;
        snake->speed.x = 0;
    }
    else if (IsKeyPressed( KEY_S ) && (snake->speed.y != -5) )
    {
        snake->speed.y = 5;
        snake->speed.x = 0;
    }
    else if (IsKeyPressed( KEY_A ) && (snake->speed.x != 5) )
    {
        snake->speed.x = -5;
        snake->speed.y = 0;

    }
    else if (IsKeyPressed( KEY_D ) && (snake->speed.x != -5) )
    {
        snake->speed.x = 5;
        snake->speed.y = 0;

    }

    if ( MathUtility::CheckCollision(snake->position, food.position))
    {

        food.setPosition();
        snake->addSegment();

    }

    snake->Move();
    draw();
}



int main(int argc, char **argv)
{
    InitWindow(1080,720, "Snake Plus Plus");
    SetTargetFPS(60);

    startGame();

    while (!WindowShouldClose())
    {
        ClearBackground(BLACK);

        BeginDrawing();

        draw();
        play();

        EndDrawing();

    }

    CloseWindow();



    return 0;
}
