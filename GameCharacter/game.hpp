#ifndef GAME_H
#define GAME_H

#include <iostream>
#include <vector>

class Game
{
private:
    std::vector<Character> characters;

public:
    void addCharacter(const Character &character);
    void showCharacters() const;
    Character *findCharacter(const std::string &name);
    void listOfCharacters() const;
};

#endif