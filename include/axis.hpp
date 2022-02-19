#pragma once

#include <string>

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

/*typedef struct 
{
    /* data
};*/


class Axis
{   private:
    screen dimensions;
    axis x;
    axis y;
    int margin_top, number_label_points_x, number_label_points_y;
    int margin = 10;
    double pointperpixel_x;
    double pointperpixel_y;
    float fontsize, fontspacing;
    Font font;
    double xaxisypos;
    double yaxisxpos;

    public:
    Axis(screen dimensions, axis x, axis y, float fontsize, float fontspacing, Font font, int margin_top = 50, int number_label_points_x = 10, int number_label_points_y = 8)
    {
        this->dimensions = dimensions;
        this->x = x;
        this->y = y;
        this->margin_top = margin_top;
        this->pointperpixel_x = (dimensions.sw - (margin * 2)) / range(this->x);
        this->pointperpixel_y = (dimensions.sh - margin - margin_top) / range(this->y);
        this->fontsize = fontsize;
        this->fontspacing = fontspacing;
        this->number_label_points_x = number_label_points_x;
        this->number_label_points_y = number_label_points_y;
        this->font = font;


        if(y.lowest >=0)
        {
            xaxisypos = dimensions.sh - margin;
        }
        else
        {
           xaxisypos = ((this->y.highest) * pointperpixel_y) + margin_top;
        }
        
        if(this->x.lowest >= 0)
        {
            yaxisxpos = margin;
        }
        else
        {
            yaxisxpos = ((-this->x.lowest) * pointperpixel_x) + margin;
        }
    }

    void draw()
    {   
        // BOUNDING BOX
        Rectangle rec;
        rec.x = margin-1;
        rec.y = margin_top-1;
        rec.width = this->dimensions.sw - margin - margin+2;
        rec.height = this->dimensions.sh - margin_top - margin+2;

        DrawRectangleLinesEx(rec, 2, GRAY);


        // X axis
        DrawLine(margin, xaxisypos, dimensions.sw - margin, xaxisypos, WHITE);
        
        //Y axis
        DrawLine(yaxisxpos, margin_top, yaxisxpos, dimensions.sh - margin, WHITE);

        //Drawing Numbers
        Vector2 loc;
        // X axis
        double spacing = (dimensions.sw - (margin * 2));
        spacing = spacing / number_label_points_x;
        double number_spacing = range(x) / number_label_points_x;

        loc.y = xaxisypos+1; // +1 for spacing
        loc.x = margin;
        double number_for_label = x.lowest;
        for(int i = 0; i < number_label_points_x; ++i)
        {
            DrawTextEx(this->font, &(double_to_string(number_for_label))[0], loc, fontsize, fontspacing, WHITE);
            loc.x += spacing;
            number_for_label += number_spacing;
        }

        spacing = dimensions.sh - margin - margin_top;
        spacing = spacing/number_label_points_y;

        number_spacing = range(y) / number_label_points_y;

        loc.x = yaxisxpos;
        loc.y = margin_top;
        number_for_label = y.highest;
        for(int i = 0; i < number_label_points_y; ++i)
        {
            DrawTextEx(this->font, &(double_to_string(number_for_label))[0], loc, fontsize, fontspacing, WHITE);
            loc.y += spacing;
            number_for_label -= number_spacing;
        }
    }

    private:
    double range(axis x)
    {
        return fabs(x.highest - x.lowest);
    }

    std::string double_to_string(double x)
    {
        std::string res = std::to_string(x);
        res.erase ( res.find_last_not_of('0') + 2, std::string::npos ); // Remove all trailing 0s but the last 0
        return res;
    }
};