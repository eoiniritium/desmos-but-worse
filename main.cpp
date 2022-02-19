#include <iostream>
#include "raylib.h"
#include "axis.hpp"

int main()
{
    int sw = 1280;
    int sh = 720;    
    int fps;


    printf("Target FPS: ");
    scanf("%d", &fps);
    printf("\nScreen dimensions: ");
    scanf("%dx%d", &sw, &sh);

    InitWindow(sw, sh, "Graphing");
    SetTargetFPS(fps);

    axis x, y;
    x.highest = 360;
    x.lowest = -90;
    y.highest = 2;
    y.lowest = -6;
    screen s;
    s.sh = sh;
    s.sw = sw;

    Font numbers = LoadFont("src/roboto/Roboto-Bold.ttf");


    Axis axis(s, x, y, 14, 2, numbers);

    Vector2 pos;
    pos.x = 100;
    pos.y = 100;

    while(!WindowShouldClose())
    {
        { // UPDATE VARS

        }
        BeginDrawing();
            ClearBackground(BLACK);
            { // DRAW HERE
                axis.draw();
            }
            //DrawFPS(10, 10);
        EndDrawing();
    }


    UnloadFont(numbers); // Get font out of VRAM
    return 0;
}