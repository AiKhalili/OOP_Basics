#include <cstdlib>
#include <raylib.h>
#include "sky.hpp"

using namespace std;

Meteor::Meteor(int startX, int startY, int Speed) : x(startX), y(startY), speed(Speed) {}

void Meteor::update()
{
    y += speed;
    if (y > 600)
    {
        y = 0;
        x = rand() % 800;
    }
}

void Meteor::draw() const
{
    DrawCircle(x, y, 9, RED);
}

void Meteor::display() const
{
    cout << "Meteor at (" << x << "," << y << ") with speed " << speed << "\n";
}

UFO::UFO(int startX, int startY, int SpeedX, int SpeedY) : x(startX), y(startY), speedX(SpeedX), speedY(SpeedY) {}

void UFO::update()
{
    x += speedX;
    y += speedY;
    if (x < 0 || x > 800)
    {
        speedX = -speedX;
    }
    if (y < 0 || y > 600)
    {
        speedY = -speedY;
    }
}

void UFO::draw() const
{
    DrawCircle(x, y, 17, GOLD);
}

void UFO::display() const
{
    cout << "UFO at (" << x << "," << y << ") with speed x = " << speedX << " and speed y = " << speedY << " \n";
}

Sky::Sky() {}

void Sky::addStar(int x, int y, float brightness, Color color)
{
    stars.emplace_back(x, y, brightness, color);
    cout << "Star added successfully.\n";
}

void Sky::addMeteor(int x, int y, int speed)
{
    if (x >= 0 && x <= 800 && y >= 0 && y <= 600)
    {
        meteors.emplace_back(x, y, speed);
        cout << "Meteor added successfully.\n";
    }
    else
    {
        throw invalid_argument("Error : Invalid meteor parameters!\n");
    }
}

void Sky::addUfo(int x, int y, int speedX, int speedY)
{
    if (x >= 0 && x <= 800 && y >= 0 && y <= 600)
    {
        ufos.emplace_back(x, y, speedX, speedY);
        cout << "UFO added successfully.\n";
    }
    else
    {
        throw invalid_argument("Error : Invalid UFO parameters!\n");
    }
}

void Sky::showInTerminal() const
{
    const int width = 80;
    const int height = 24;

    vector<vector<char>> monitor(height, vector<char>(width, ' '));

    for (const Star &star : stars)
    {
        int monitorX = (star.get_x() * width) / 800;
        int monitorY = (star.get_y() * height) / 600;

        if (monitorX >= 0 && monitorX < width && monitorY >= 0 && monitorY < height)
        {
            monitor[monitorY][monitorX] = '*';
        }
    }
    for (const auto &row : monitor)
    {
        for (char pixel : row)
        {
            cout << pixel;
        }
        cout << '\n';
    }
}

void Sky::displayAll() const
{
    for (const Star &star : stars)
    {
        star.display();
    }
    for (const Meteor &meteor : meteors)
    {
        meteor.display();
    }
    for (const UFO &ufo : ufos)
    {
        ufo.display();
    }
}

void Sky::render()
{
    InitWindow(800, 600, "Night Sky");
    SetTargetFPS(60);

    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(BLACK);

        for (Star &star : stars)
        {
            star.twinkle();
            star.draw();
        }
        for (Meteor &meteor : meteors)
        {
            meteor.update();
            meteor.draw();
        }
        for (UFO &ufo : ufos)
        {
            ufo.update();
            ufo.draw();
        }
        EndDrawing();
    }
    CloseWindow();
}