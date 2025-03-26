#ifndef STAR_H
#define STAR_H

#include <iostream>
#include <raylib.h>

class Star
{
private:
    int x, y;
    float brightness;
    Color color;

public:
    Star(int X, int Y, float BRIGHTNESS, Color COLOR);
    void display() const;
    void draw() const;
    void twinkle();
    int get_x() const;
    int get_y() const;
    float get_britness() const;
    Color get_color() const;
};

#endif