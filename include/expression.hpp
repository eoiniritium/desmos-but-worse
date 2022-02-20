#pragma once

#include <vector>
#include "axis.hpp"
#include "stdio.h"

class Expression 
{   protected:
    std::vector<double> e(std::string expression_string, axis x, double plotsperpoint)
    {
        std::vector<double> res;
        for(double i = x.lowest; i < x.highest; i+=plotsperpoint)
        {   
            double pb = cos(radToDegrees(i));
            res.push_back(pb);
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
};