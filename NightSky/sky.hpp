#ifndef SKY_H
#define SKY_H

#include <iostream>
#include <vector>
#include "star.hpp"

class Meteor
{
private:
    int x, y;
    int speed;

public:
    Meteor(int startX, int startY, int Speed);
    void update();
    void draw() const;
    void display() const;
};

class UFO
{
private:
    int x, y;
    int speedX, speedY;

public:
    UFO(int startX, int startY, int SpeedX, int SpeedY);
    void update();
    void draw() const;
    void display() const;
};

class Sky
{
private:
    std::vector<Star> stars;
    std::vector<UFO> ufos;
    std::vector<Meteor> meteors;

public:
    Sky();
    void addStar(int x, int y, float brightness, Color color);
    void addMeteor(int x, int y, int speed);
    void addUfo(int x, int y, int speedX, int speedY);
    void showInTerminal() const;
    void displayAll() const;
    void render();
};

#endif