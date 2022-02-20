#pragma once

#include <vector>
#include "axis.hpp"

class Expression
{
    protected:
    std::vector<double> expression_points(std::string expression_string, axis ax, double plotsperpoint)
    {





        
        std::vector<double> res;
        for(double x = ax.lowest; x < ax.highest; x+=1/plotsperpoint)
        {
            double y = d_sin(x);
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
    double d_cos(double theta)
    {
        return cos(degreesToRad(theta));
    }
    double d_tan(double theta)
    {
        return tan(degreesToRad(theta));
    }
};