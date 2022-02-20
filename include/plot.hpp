#pragma once

#include "raylib.h"
#include "font.hpp"
#include "axis.hpp"
#include "expression.hpp"
#include <vector>

class Plot: private Expression
{
    private:
    axispoints points;
    Color color;
    std::string expression_string;
    std::vector<double> ypoints;
    double resolution;

    public:
    Plot(axispoints points, Color color, double resolution)
    {
        this->points = points;
        this->color = color;
        this->resolution = resolution;
    }

    void expression(std::string expression_string)
    {
        this->expression_string = expression_string;
    }

    void draw()
    {
       
        ypoints = expression_points(this->expression_string, this->points.x, resolution);
        
        // DRAW POINTS
        double posx = this->points.margin, posy;
        for(int i = 0; i < ypoints.size(); ++i)
        {
            posy = ( (this->points.xaxisypos - (ypoints[i] * this->points.pointperpixel_y)) > this->points.margin_top ) ? (this->points.xaxisypos - (ypoints[i] * this->points.pointperpixel_y)) : -1; // If too high place point above screen
            posy = (posy > this->points.sh - this->points.margin) ? -1 : posy; // If too low place point above screen
            DrawPixel(posx, posy, color);
            posx += (this->points.pointperpixel_x * 1/resolution);
        }
    }

    private:
};