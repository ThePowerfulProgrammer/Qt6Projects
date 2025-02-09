#include "raylib.h"
#include <ctime>
#include <cstdlib>

using namespace std;

const int screenWidth = 900;
const int screenHeight = 720;

struct Paddle
{
    Vector2 position; // <x,y> == <posx, posy>
    Vector2 size; // <x,y> == <width, height>
    Color color;
};

struct Ball
{
    Vector2 position;
    Vector2 speed;
    float r;
    Color c;
};

struct Brick
{
    Vector2 position;
    Vector2 size;
    bool active; // Determines if a brick should be drawn or not

    Brick()
    {
        position.x = 0;
        position.y = 0;

        size.x = 0;
        size.y = 0;

        active = false;
    }

    Brick(float x, float y, float length, float width, bool act=true)
    {
        position.x = x;
        position.y = y;

        size.x = length;
        size.y = width;

        active = act;
    }

 };


 const int rows = 2;
 const int cols = 20;

 Brick bricks[rows][cols];
 Paddle paddle;
 Ball ball;



 // Init the starting variables of the game
 void startGame()
 {
     // creates starting bricks
     float startingX = 0; // refers to the starting x coordinate of the bricks
     float startingY = 40;

     float l = 45;
     float w = 45;

     for (int i=0;i<rows;i++)
     {
         for (int j=0;j<cols;j++)
         {
             Brick brick(startingX, startingY, l,w);
             bricks[i][j] = brick;
             startingX += w;
         }
         startingX = 0;
         startingY +=l;
     }

     // the PADDLE
     paddle.position = {400,650};
     paddle.size = {100,25};
     paddle.color = BLACK;

     // the BalL
     ball.position = {450,620};
     ball.speed = {0,-5};
     ball.r = 10;
     ball.c = DARKBLUE;

}

// draw the frames
 void draw()
{



    // draw bricks
    for (int i=0;i<rows;i++)
    {
        for (int j=0;j<cols;j++)
        {
            Brick brick = bricks[i][j];

            if ( ((i+j) % 2== 0) && brick.active )
            {
                DrawRectangle(brick.position.x, brick.position.y, brick.size.x,
                              brick.size.y, BLUE);
            }
            else if ( ((i+j) % 2 != 0) && brick.active )
            {
                DrawRectangle(brick.position.x, brick.position.y, brick.size.x,
                              brick.size.y, BLACK);

            }
        }
    }


    // draw paddle
    DrawRectangle(paddle.position.x, paddle.position.y, paddle.size.x, paddle.size.y, paddle.color);

    // Draw the ball
    DrawCircle(ball.position.x, ball.position.y, ball.r, ball.c);

}

bool inRange(unsigned low, unsigned high, unsigned target)
{
    // low == 100, high = 145, target = 101: 100<=101 && 101<=145
    return (low <= target && target <= high);
}


// updates the variables and essentially the frames of the game
void playGame()
{
    if (!(ball.position.y >=  screenHeight))
    {
        // move the paddle
        if (IsKeyDown(KEY_LEFT) && paddle.position.x > 10)
        {
            paddle.position.x -= 5;
        }
        else if (IsKeyDown(KEY_RIGHT) && paddle.position.x < 790)
        {
            paddle.position.x += 5;
        }

        ball.position.y += ball.speed.y;
        ball.position.x += ball.speed.x;

        // check collision of ball and screenHeight
        if (ball.position.y <= 0)
        {
            ball.speed.y *=-1;
            ball.c = RED;
        }

        // check collision of ball and paddle
        if (CheckCollisionCircleRec(ball.position, ball.r,
                                    Rectangle{paddle.position.x, paddle.position.y, paddle.size.x, paddle.size.y}))
        {
            ball.speed.y *= -1;
            int distancePlayer_Ball = ball.position.x - paddle.position.x;
            ball.speed.x = distancePlayer_Ball/(paddle.size.x/2)*5;
        }

        // check collision of ball and side walls
        if (ball.position.x <= 0)
        {
            ball.speed.x *= -1;
        }
        else if (ball.position.x >= 900)
        {
            ball.speed.x *= -1;
        }

        // Math to detect collision of ball and ANY brick?
        for (int i=0;i<rows; i++)
        {
            for (int j=0;j<cols;j++)
            {
                // (100,145, ball.x) && (100, 145, ball.y)
                if (inRange(bricks[i][j].position.x, bricks[i][j].position.x+45,ball.position.x + ball.r) &&
                    (inRange(bricks[i][j].position.y, bricks[i][j].position.y+45,ball.position.y + ball.r)) &&
                    bricks[i][j].active)
                {
                    ball.speed.y *= -1;
                    bricks[i][j].active = false;


                }
            }
        }


        draw();
    }
    else if (ball.position.y >= screenHeight)
    {
        DrawText("GAME OVER", 378,360,28, BLACK);
    }
}


int main(int argc, char **argv)
{
    InitWindow(screenWidth, screenHeight, "Arkanoid");
    SetTargetFPS(60); // The screen should be redrawn 60 times in 1 second

    startGame();

    while (!WindowShouldClose())
    {
        ClearBackground(WHITE);

        BeginDrawing();
        // All our drawing will be done here
        draw();
        playGame();

        EndDrawing();

    }

    CloseWindow();

    return 0;
}
