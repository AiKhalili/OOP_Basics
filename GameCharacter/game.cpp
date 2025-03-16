#include <iostream>
#include <vector>
#include "character.hpp"
#include "game.hpp"

using namespace std;

void Game::addCharacter(const Character &character)
{
    characters.emplace_back(character);
    cout << "Charactar " << character.get_name() << " add successfully!\n";
}

void Game::showCharacters() const
{
    cout << "Characters Roster :\n";
    for (const auto &character : characters)
    {
        character.show();
        cout << "\n________________________________________________________\n";
    }
}

Character *Game::findCharacter(const string &name)
{
    for (auto &character : characters)
    {
        if (character.get_name() == name)
        {
            return &character;
        }
    }
    cout << "Character not found!\n";
    return nullptr;
}

void Game::listOfCharacters() const
{
    int count = 0;
    cout << "List of characters :\n";
    for (const auto &character : characters)
    {
        cout << ++count << "-\t";
        cout << character.get_name();
        cout << '\n';
    }
}