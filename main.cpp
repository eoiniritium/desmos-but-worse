#include <iostream>
#include "raylib.h"
#include "axis.hpp"
#include "font.hpp"
#include "plot.hpp"

int main()
{
    int sw = 500;
    int sh = 500;    
    int fps;
    int showfps = 0;


    printf("Target FPS: ");
    scanf("%d", &fps);

    // All of this to allocate and deallocate single byte!
    printf("Show FPS? (Y/N) ");
    char *temp = (char*)malloc(sizeof(char));
    scanf("\n%c", temp);
    showfps = (*temp == 'Y' || *temp == 'y') ? 1 : 0;
    free(temp); // Remove var

    printf("Screen dimensions: ");
    scanf("%dx%d", &sw, &sh);

    InitWindow(sw, sh, "Graphing");
    SetTargetFPS(fps);

    axis x, y;
    x.highest = 360;
    x.lowest = -180;

    y.highest = 1;
    y.lowest = -1;
    screen s;
    s.sh = sh;
    s.sw = sw;

    Font_s font("src/roboto/Roboto-Bold.ttf");

    Axis axis(s, x, y, 14, 2, font.getfont(), 10, 10, 5);
    axispoints points = axis.getaxispoints();

    Plot plot(points, BLUE, 100);
    plot.expression("sin(x)");
    plot.draw();

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
                plot.draw();
            }
            if(showfps) DrawFPS(10, 10);
        EndDrawing();
    }

    return 0;
}