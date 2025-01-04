#include "raylib.h"

#define HEIGHT 700
#define WIDTH 800




int main(int argc, char** argv)
{

    InitWindow(WIDTH,HEIGHT, "Powerful Camera");


    Rectangle rec = {0};
    rec.height = 100;
    rec.width = 100;
    rec.x = (WIDTH / 2) - (rec.width/2) ;
    rec.y = (HEIGHT / 2) - (rec.height/2);

    Camera2D cam;
    cam.target = (Vector2){rec.x + 20.0f, rec.y + 20.0f};
    cam.offset = (Vector2){WIDTH/2, HEIGHT/2};
    cam.rotation = 0.f;
    cam.zoom = 1.0f;


    SetTargetFPS(60);

    while (!WindowShouldClose())
    {

        if (IsKeyDown(KEY_W))
        {
            rec.y -= 5;
        }
        else if (IsKeyDown(KEY_S))
        {
            rec.y += 5;
        }

        cam.target = {rec.x + 20, rec.y + 20};

        if (IsKeyDown(KEY_A))
        {
            rec.x -= 5;
        }
        else if (IsKeyDown(KEY_D))
        {
            rec.x += 5;
        }



        BeginDrawing();
        ClearBackground(WHITE);
        BeginMode2D(cam);

        DrawRectangleRec(rec, Color{27,4,225,255});


        for (int i=100;i<WIDTH;i+=100)
        {
            DrawLine(i,0, i,HEIGHT, BLACK );
        }

        for (int j=100;j<HEIGHT;j+=100)
        {
            DrawLine(0,j,WIDTH,j, RED);
        }

        EndMode2D();
        EndDrawing();


    }

    CloseWindow();
    return 0;

}
