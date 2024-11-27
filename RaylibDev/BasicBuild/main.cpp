#include "raylib.h"
#include <iostream>
#include <cstdlib>
#include <ctime>



using namespace std;

const int screenWidth = 900;
const int screenHeight = 720;

struct Paddle
{
    Vector2 position;
    Vector2 size;
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
    bool active;

    Brick()
    {
        position.x = 0;
        position.y = 0;

        size.x = 0;
        size.y = 0;

    };

    Brick(float x, float y, float length,float width, bool act=true)
    {
        position.x = x;
        position.y = y;

        size.x = length;
        size.y = width;

        active = act;
    }
};

struct Score
{
    string scoreString;
    int currentScore;

};

const int rows = 2;
const int cols = 20;

Brick bricks[rows][cols]; // bricks array[rows][cols]:
Paddle paddle;
Ball ball;

Score scoreboard;


// init the bricks,paddle and ball before the first draw
void startGame()
{

    float startingX = 0;
    float startingY = 40;

    float l = 45;
    float w = 45;

    for (int i=0;i<2;i++)
    {
        for (int j=0;j<20;j++)
        {
            Brick brick(startingX, startingY, l, w);
            bricks[i][j] = brick;
            startingX += 45;
        }
        startingX = 0;
        startingY += 45;
    }


    // now the paddle
    paddle.position = {400,650};
    paddle.size = {100,25};
    paddle.color = BLACK;

    // Finally init the ball

    ball.position.x = 450;
    ball.position.y = 620;
    ball.speed = {0,-5}; // init move up
    ball.r = 10;
    ball.c = GREEN;

    scoreboard.scoreString = "";
    scoreboard.currentScore = 0;
    scoreboard.scoreString = "Score: " + to_string(scoreboard.currentScore);

}


// Draw the objects onto the canvas: For now just the bricks
void draw()
{
    // Create xy axis
    DrawLine(450,0,450,720,GREEN); // y-axis
    DrawLine(0,360,900,360,BLACK); // x-axis


    // draw bricks


    for (int i=0;i<rows;i++)
    {
        cout << "drawing bricks" << endl;
         for (int j=0;j<cols;j++)
        {
            Brick brick = bricks[i][j];
            cout << brick.position.x << ", " << brick.position.y << endl;
            if (((i+j) % 2 == 0 ) && brick.active)
            {
                DrawRectangle(brick.position.x, brick.position.y, brick.size.x,
                              brick.size.y, GREEN);
            }
            else if (((i+j) % 2 != 0 ) && brick.active)
            {
                DrawRectangle(bricks[i][j].position.x, bricks[i][j].position.y,
                              bricks[i][j].size.x,bricks[i][j].size.y, BLACK);
            }
        }

    }

    // draw paddle
    DrawRectangle(paddle.position.x, paddle.position.y, paddle.size.x,paddle.size.y, paddle.color);

    // draw ball
    DrawCircle(ball.position.x, ball.position.y, ball.r, ball.c);

    // draw Scoreboard

    const char* c_string = scoreboard.scoreString.c_str();
    DrawText(c_string,10,690,21,BLACK);


}

bool inRange(unsigned low, unsigned high, unsigned x)
{
    // low = 100,high = 145, x = 101
    return (low <= x && x<=high);
}

bool moveUp = true;
// I need a function that handles the dynamic content of the game and calls the draw function
void playGame()
{
    if (!(ball.position.y >= screenHeight))
    {
        if (IsKeyDown(KEY_LEFT) && paddle.position.x > 10)
        {
            paddle.position.x -=5;
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
            ball.c = BLACK;
        }

        // check collision of ball and paddle
        if (CheckCollisionCircleRec(ball.position,ball.r,
                                    Rectangle{paddle.position.x,paddle.position.y,paddle.size.x,paddle.size.y}))
        {
            ball.speed.y *= -1;
            int distancePlayer_Ball = ball.position.x - paddle.position.x;
            ball.speed.x = distancePlayer_Ball/(paddle.size.x/2)*5;
        }


        // check ball collision and screenWidth
        if (ball.position.x <= 0 ) // hit left wall
        {
            ball.speed.x *= -1;
        }
        else if (ball.position.x >= 900)
        {
            ball.speed.x *= -1;
        }

        // check collision of ball and any brick
        for (int i=0;i<rows;i++)
        {
            for (int j=0;j<cols;j++)
            {
                //   (100,145,paddle.x) && (100,145,paddle.y)
                if (inRange(bricks[i][j].position.x, bricks[i][j].position.x + 45, ball.position.x + ball.r) &&
                    (inRange(bricks[i][j].position.y, bricks[i][j].position.y + 45, ball.position.y + ball.r)) && bricks[i][j].active)
                {
                    ball.speed.y *= -1;

                    string x = to_string(bricks[i][j].position.x);
                    string xTra = to_string(bricks[i][j].position.x + 45);
                    string pos = x + " , " + xTra;
                    const char* posPointer = pos.c_str();

                    DrawText(posPointer,200,200,14, BLACK);

                    bricks[i][j].active = false;

                    scoreboard.currentScore += 1;
                    scoreboard.scoreString = "Score: " + to_string(scoreboard.currentScore);
                    const char* c_string = scoreboard.scoreString.c_str();
                    DrawText(c_string,10,690,21,BLACK);
                }


            }
        }



        draw();
    }
    else if (ball.position.y >= screenHeight)
    {
        ClearBackground(WHITE);
        DrawText("Game Over", 378,360, 28, BLACK);
    }

}



int main(int argc, char **args)
{
    InitWindow(screenWidth, screenHeight,"Arkanoid");
    SetTargetFPS(60);

    startGame();

    while (!WindowShouldClose())
    {
        ClearBackground(WHITE);
        BeginDrawing();

        draw();
        playGame();
        EndDrawing();
    }

    CloseWindow();

    return 0;
}
