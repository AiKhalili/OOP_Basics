#include <iostream>
#include <iomanip>
#include <stdexcept>
#include "sky.hpp"
#include "star.hpp"

using namespace std;

void menue()
{
    cout << '\n';
    cout << "**************************************************\n";
    cout << "*           NIGHT SKY MANAGEMENT MENU            *\n";
    cout << "**************************************************\n";
    cout << "* 0. Exist                                       *\n";
    cout << "* 1. Add a new star                              *\n";
    cout << "* 2. Add a new UFO                               *\n";
    cout << "* 3. Add a new meteor                            *\n";
    cout << "* 4. Show sky in terminal                        *\n";
    cout << "* 5. Show sky in consol                          *\n";
    cout << "* 6. Display all                                 *\n";
    cout << "**************************************************\n";
    cout << "Select an option to continue: ";
}

void boundary()
{
    cout << setw(50) << "_________________________________________________\n"
         << endl;
}

int getValidInt(string prompt, bool range)
{
    int number;
    string num_str;
    while (true)
    {
        cout << prompt;
        cin >> num_str;
        cin.ignore(1000, '\n');
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
            if (range)
            {
                if (number < 0 || number > 255)
                {
                    throw out_of_range("Number out of valid range!\n");
                }
            }
            return number;
        }
        catch (const invalid_argument &e)
        {
            cout << "Invalid input! " << e.what() << "Try again.\n";
        }
    }
}

float getValidFloat(string prompt)
{
    float number;
    string num_str;
    while (true)
    {
        cout << prompt;
        cin >> num_str;
        cin.ignore(1000, '\n');
        try
        {
            bool hasDot = false;
            for (char c : num_str)
            {
                if (!isdigit(c))
                {
                    if (c == '.' && !hasDot)
                    {
                        hasDot = true;
                    }
                    else
                    {
                        throw invalid_argument("Input must be a floating-pointing number!\n");
                    }
                }
            }
            number = stof(num_str);
            return number;
        }
        catch (const invalid_argument &e)
        {
            cout << "Invalid input! " << e.what() << "Try again.\n";
        }
    }
}

Color getColor()
{
    int r = getValidInt("Enter red(0-255) :\n", true);
    int g = getValidInt("Enter green(0-255) :\n", true);
    int b = getValidInt("Enter blue(0-255) :\n", true);

    return {static_cast<unsigned char>(r), static_cast<unsigned char>(g), static_cast<unsigned char>(b), 255};
}

bool check(string &selection, Sky &sky)
{
    if (selection == "0")
    {
        cout << "Have a great day!\n";
        return false;
    }
    else if (selection == "1")
    {
        int numStars = getValidInt("Enter number of stars :\n", false);

        for (int i = 0; i < numStars; i++)
        {
            int x = getValidInt("Enter x coordinate of star :\n", false);
            int y = getValidInt("Enter y coordinate of star :\n", false);
            float brightness = getValidFloat("Enetr brightness of star(0.1 to 1.0) :\n");
            Color color = getColor();

            try
            {
                sky.addStar(x, y, brightness, color);
            }
            catch (const invalid_argument &e)
            {
                cerr << e.what() << "Try again.\n";
                i--;
            }
        }
        return true;
    }
    else if (selection == "2")
    {
        int numUFO = getValidInt("Enter number of UFOs :\n", false);

        for (int i = 0; i < numUFO; i++)
        {
            int x = getValidInt("Enter x coordinate of UFO :\n", false);
            int y = getValidInt("Enter y coordinate of UFO :\n", false);
            int speedX = getValidInt("Enter speedX of UFO :\n", false);
            int speedY = getValidInt("Enter speedY of UFO :\n", false);
            try
            {
                sky.addUfo(x, y, speedX, speedY);
            }
            catch (const invalid_argument &e)
            {
                cerr << e.what() << "Try again.\n";
                i--;
            }
        }
        return true;
    }
    else if (selection == "3")
    {
        int numMeteors = getValidInt("Enter number of UFOs :\n", false);

        for (int i = 0; i < numMeteors; i++)
        {
            int x = getValidInt("Enter x coordinate of meteor :\n", false);
            int y = getValidInt("Enter y coordinate of meteor :\n", false);
            int speed = getValidInt("Enter speed of meteor :\n", false);
            try
            {
                sky.addMeteor(x, y, speed);
            }
            catch (const invalid_argument &e)
            {
                cerr << e.what() << "Try again.\n";
                i--;
            }
        }
        return true;
    }
    else if (selection == "4")
    {
        sky.showInTerminal();
        return true;
    }
    else if (selection == "5")
    {
        sky.render();
        return true;
    }
    else if (selection == "6")
    {
        sky.displayAll();
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
    Sky sky;
    string input;

    while (true)
    {
        menue();
        getline(cin, input);
        if (!check(input, sky))
        {
            return 0;
        }
    }

    return 0;
}