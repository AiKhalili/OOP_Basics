#include <stdexcept>
#include <cstdlib>
#include "star.hpp"

using namespace std;

Star::Star(int X, int Y, float BRIGHTNESS, Color COLOR)
{
    if (X < 0 || X > 800 || Y < 0 || Y > 600)
    {
        throw invalid_argument("Error : Invalid star coordinates! must be within(0,0) to (800,600).\n");
    }
    if (BRIGHTNESS < 0.1f || BRIGHTNESS > 1.0f)
    {
        throw invalid_argument("Error : Invalid brightness! must be between 0.1 to 1.0 .\n");
    }
    x = X;
    y = Y;
    brightness = BRIGHTNESS;
    color = COLOR;
}

void Star::display() const
{
    cout << "Star at (" << x << "," << y << ") with brightness " << brightness
         << " and color [" << (int)color.r << "," << (int)color.g << "," << (int)color.b << "]\n";
}

void Star::draw() const
{
    float radius = brightness * 7.0f;
    DrawCircle(x, y, radius, color);
}

void Star::twinkle()
{
    float change = (rand() % 20 - 10) / 100.0f;
    brightness += change;
    if (brightness < 0.1f)
    {
        brightness = 0.1f;
    }
    if (brightness > 1.0f)
    {
        brightness = 1.0f;
    }
}

int Star::get_x() const { return x; }
int Star::get_y() const { return y; }
float Star::get_britness() const { return brightness; }
Color Star::get_color() const { return color; }