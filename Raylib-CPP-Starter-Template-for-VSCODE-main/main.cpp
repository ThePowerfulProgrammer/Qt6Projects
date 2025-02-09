#include <iostream>
#include <raylib.h>
#include "ball.h"

using namespace std;

int main () {

    Ball ball;

    const int screenWidth = 800;
    const int screenHeight = 600;
    int ball_x = 100;
    int ball_y = 100;
    int ball_speed_x = 5;
    int ball_speed_y = 5;
    int ball_radius = 15;

    cout << "Hello World" << endl;

    InitWindow(screenWidth, screenHeight, "My first RAYLIB program!");
    SetTargetFPS(120);

    while (WindowShouldClose() == false){
        BeginDrawing();
        ClearBackground(BLACK);
        ball_x += ball_speed_x;
        ball_y += ball_speed_y;

        if(ball_x + ball_radius >= screenWidth  || ball_x - ball_radius <= 0)
        {
            ball_speed_x *= -1;
        }

        if(ball_y + ball_radius >= screenHeight  || ball_y - ball_radius <= 0)
        {
            ball_speed_y *= -1;
        }

        DrawCircle(ball_x,ball_y+50,ball_radius, WHITE);
        DrawRectangle(150,150,100,50, RED);
        EndDrawing();
        if (IsKeyPressed(KEY_ENTER)) 
        {
            CloseWindow();
        }
    }

    CloseWindow();
    return 0;
}