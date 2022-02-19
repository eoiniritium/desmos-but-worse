#pragma once

#include "raylib.h"
#include "math.h"

typedef struct screen
{
    int sw, sh;
} screen;

typedef struct axis
{
    double lowest, highest;
} axis;

class Axis
{   private:
    screen dimensions;
    axis x;
    axis y;
    int margin_top;
    int margin = 10;
    double pointperpixel_x;
    double pointperpixel_y;

    public:
    Axis(screen dimensions, axis x, axis y, int margin_top = 50)
    {
        this->dimensions = dimensions;
        this->x = x;
        this->y = y;
        this->margin_top = margin_top;
        this->pointperpixel_x = (dimensions.sw - (margin * 2)) / range(this->x);
        this->pointperpixel_y = (dimensions.sh - margin - margin_top) / range(this->y);
    }

    double range(axis x)
    {
        return fabs(x.highest - x.lowest);
    }

    void draw()
    {   
        // BOUNDING BOX
        Rectangle rec;
        rec.x = margin-1;
        rec.y = margin_top-1;
        rec.width = this->dimensions.sw - margin - margin+1;
        rec.height = this->dimensions.sh - margin_top - margin+1;

        DrawRectangleLinesEx(rec, 2, GRAY);


        double xaxisypos;
        if(y.lowest >=0)
        {
            xaxisypos = dimensions.sh - margin;
        }
        else
        {
           xaxisypos = ((-this->y.lowest) * pointperpixel_y) + margin_top;
        }
        double yaxisxpos;
        if(this->x.lowest >= 0)
        {
            yaxisxpos = margin;
        }
        else
        {
            yaxisxpos = ((-this->x.lowest) * pointperpixel_x) + margin;
        }

        // X axis
        DrawLine(margin, xaxisypos, dimensions.sw - margin, xaxisypos, WHITE);
        
        //Y axis
        DrawLine(yaxisxpos, margin_top, yaxisxpos, dimensions.sh - margin, WHITE);
    }
};