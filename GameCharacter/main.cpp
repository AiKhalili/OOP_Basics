#include <iostream>
#include "character.hpp"
#include <iomanip>
#include <stdexcept>
#include "game.hpp"

using namespace std;

void menue()
{
    cout << '\n';
    cout << "**************************************************\n";
    cout << "*              GAME MANAGEMENT MENU              *\n";
    cout << "**************************************************\n";
    cout << "* 0. Exist                                       *\n";
    cout << "* 1. Add a new game character                    *\n";
    cout << "* 2. Add a new skill to a character              *\n";
    cout << "* 3. Show character details                      *\n";
    cout << "* 4. Show details of all characters              *\n";
    cout << "* 5. Start the fight                             *\n";
    cout << "**************************************************\n";
    cout << "Select an option to continue: ";
}

void boundary()
{
    cout << setw(50) << "_________________________________________________\n"
         << endl;
}

int getValidNumber(string &num_str)
{
    int number;
    while (true)
    {
        try
        {
            for (char c : num_str)
            {
                if (!isdigit(c))
                {
                    throw invalid_argument("Input must be a number!\n");
                }
            }
            number = stoi(num_str);
            return number;
        }
        catch (const invalid_argument &e)
        {
            cout << "Invalid input! " << e.what() << "Try again.\n";
            cout << "Enter again :\n";
            cin >> num_str;
        }
    }
}

bool check(string &selection , Game& game)
{
    string name, health_str, power_str, level_str;
    if (selection == "0")
    {
        cout << "Hope you had fun.\n";
        return false;
    }
    else if (selection == "1")
    {
        cout << "Enter the name of character :\n";
        cin >> name;
        cin.ignore(1000,'\n');
        cout << "Enter the health :\n";
        cin >> health_str;
        cin.ignore(1000,'\n');
        int health = getValidNumber(health_str);
        cout << "Enter the power :\n";
        cin >> power_str;
        cin.ignore(1000,'\n');
        int power = getValidNumber(power_str);
        Character character(name, health, power);
        game.addCharacter(character);
        return true;
    }
    else if (selection == "2")
    {
        cout << "Enter the name of character :\n";
        cin >> name;
        cin.ignore(1000,'\n');
        Character *find = game.findCharacter(name);
        if (find != nullptr)
        {
            cout << "Enter the skill's name :\n";
            cin >> name;
            cin.ignore(1000,'\n');
            cout << "Enter the skill's level :\n";
            cin >> level_str;
            cin.ignore(1000,'\n');
            int level = getValidNumber(level_str);
            find->addSkill(name, level);
        }
        return true;
    }
    else if (selection == "3")
    {
        cout << "Enter the name of character :\n";
        cin >> name;
        cin.ignore(1000,'\n');
        Character *find = game.findCharacter(name);
        if (find != nullptr)
        {
            find->show();
        }
        return true;
    }
    else if (selection == "4")
    {
        boundary();
        game.showCharacters();
        return true;
    }
    else if (selection == "5")
    {
        string player, opponent;
        boundary();
        game.listOfCharacters();
        boundary();
        cout << "Select your player (Enter its name): ";
        cin >> player;
        cin.ignore(1000,'\n');
        cout << "Select your opponent (Enter its name): ";
        cin >> opponent;
        cin.ignore(1000,'\n');
        Character *findPlayer = game.findCharacter(player);
        Character *findOpponent = game.findCharacter(opponent);
        if (findPlayer != nullptr && findOpponent != nullptr)
        {
            findPlayer->fight(*findOpponent);
        }
        return true;
    }
    else
    {
        cout << "Incorrect input.\n";
        return true;
    }
}

int main()
{
    Game game;
    string input;

    while (true)
    {
        menue();
        getline(cin, input);
        if (!check(input , game))
        {
            return 0;
        }
    }

    return 0;
}