#include "raylib.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>

using namespace std;



int main(void)
{

    const int screenWidth = 700;
    const int screenHeight = 720;
    InitWindow(screenWidth, screenHeight, "raylib [core] example - basic window");
    SetTargetFPS(60);               // Set our game to run at 60 frames-per-second

    Color colors[] = {DARKGRAY, GRAY, DARKGRAY, GRAY, DARKGRAY, GRAY};
    vector<Color> blockColors;
    srand(time(0));

    for (int i=0;i<28;i++)
    {
        blockColors.push_back(colors[rand() %(5-0+1)]);
    }
    Rectangle rec;
    rec.x = 310;
    rec.y = 680;
    rec.height = 30;
    rec.width = 100;

    // Main game loop
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
        ClearBackground(WHITE);
        BeginDrawing();

        int topLeftX = 0;
        int topLeftY = 0;

        DrawLine(360,10, 360,710, BLACK); // y-axis
        DrawLine(10,360, 710, 360, BLUE); // x-axis

        // for (int row=0;row<2;row++)
        // {
        //     for (int col=0;col<14;col++)
        //     {
        //         DrawRectangle(topLeftX,topLeftY,50,50,colors[rand() %(5-0+1)]);
        //         topLeftX += 50; // move the next rectangle 50px right
        //     }
        //     topLeftY +=50; // move to the next row
        //     topLeftX = 0; // start at the left
        // }


        for (int row=0;row<2;row++)
        {
            for (int col=0;col<14;col++)
            {
                DrawRectangle(topLeftX,topLeftY,50,50,blockColors[row*14+col] );
                topLeftX += 50; // move the next rectangle 50px right
            }
            topLeftY +=50;
            topLeftX = 0;
        }


        DrawRectangleRounded(rec, 0.5, 0, RED);

        if (IsKeyDown(KEY_UP))
        {
            cout << "Move up \n";

            // Move the rectangle one up;
            rec.y -= 5;
            cout << "("<< rec.x << ", " << rec.y << ") \n";

            if (rec.y <= 100)
            {
                rec.y = 680;
                rec.x = 310;
            }
        }
        else if (IsKeyDown(KEY_DOWN))
        {
            rec.y += 5;
            cout << "("<< rec.x << ", " << rec.y << ") \n";
        }
        else if (IsKeyDown(KEY_LEFT))
        {
            rec.x -= 5;
            cout << "("<< rec.x << ", " << rec.y << ") \n";
        }
        else if (IsKeyDown(KEY_RIGHT))
        {
            rec.x += 5;
            cout << "("<< rec.x << ", " << rec.y << ") \n";
        }
        EndDrawing();
    }

    CloseWindow();        // Close window and OpenGL context


    return 0;
}
