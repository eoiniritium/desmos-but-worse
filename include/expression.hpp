#pragma once

#include <vector>
#include "axis.hpp"
#include "stdio.h"

class Expression 
{   protected:
    std::vector<double> e(std::string expression_string, axis ax, double plotsperpoint)
    {
        std::vector<double> res;
        double y;
        for(double x = ax.lowest; x < ax.highest; x+=1/plotsperpoint)
        {   
            // EACH EXPRESSION GOES HERE. CODE WILL STEP THROUGH AND CALCULATE EACH ANSWER WITH A DIFFERENT x
            //double pb = cos(radToDegrees(i));

            y = d_sin(x);
            res.push_back(y);
        }
        return res;
    }

    double range(axis x)
    {
        return fabs(x.highest - x.lowest);
    }

    double degreesToRad(double deg)
    {
        return deg * (3.14159 / 180);
    }

    double radToDegrees(double rad)
    {
        return rad * (180 / 3.14159);
    }

    double d_sin(double theta)
    {
        return sin(degreesToRad(theta));
    }
};