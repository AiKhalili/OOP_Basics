#ifndef STAR_H
#define STAR_H

#include <iostream>

class Star
{
private:
    int x, y;
    double brightness;
    std::string color;

public:
    Star(int X, int Y, double BRIGHTNESS, std::string COLOR);
    int get_x() const;
    int get_y() const;
    void showStarInformation() const;
};

#endif