#include <iostream>
#include <unordered_map>
#include <string>
#include "character.hpp"

using namespace std;

Character::Character(std::string NAME, int HEALTH, int POWER)
    : name(NAME), health(HEALTH), power(POWER), maxHealth(100), exprience(0), level(1) {}

void Character::show() const
{
    cout << "Name : " << name << "\nHealth : " << health << "\nPower : " << power
         << "\nLevel : " << level << "\nExprience : " << exprience << "\nSkills : ";
    for (const auto &skill : skills)
    {
        cout << "\n- " << skill.first << " : skill's level " << skill.second;
    }
}

void Character::addSkill(const string &skillName, int lvl)
{
    skills[skillName] = lvl;
    cout << "Skill added successfully !\n";
}

string Character::get_name() const { return name; }

void Character::takeDamage(int damage)
{
    health -= damage / 2;
    if (health < 0)
    {
        health = 0;
    }
}

void Character::gainExprience(int expr)
{
    exprience += expr;
    if (exprience >= 100)
    {
        level++;
        exprience -= 100;
        cout << name << " level up . Now at level " << level << "!\n";
    }
}

void Character::fight(Character &rival)
{
    cout << "^^^ " << name << " is fighting with " << rival.name << " ^^^" << endl;

    if (health <= 0)
    {
        cout << name << " has no health left and cannot fight!\n";
        return;
    }

    if (rival.health <= 0)
    {
        cout << rival.name << " has no health left and cannot fight!\n";
        return;
    }

    while (health > 0 && rival.health > 0)
    {
        int attackPower = power + (level * 5);
        if (skills.find("combat") != skills.end())
        {
            attackPower += (power * skills["combat"] * 5 / 100);
        }

        rival.takeDamage(attackPower);
        cout << rival.name << " took " << attackPower / 2 << " damage! Health: " << rival.health << endl;

        if (rival.health <= 0)
        {
            cout << rival.name << " lose to " << name << endl;
            gainExprience(50);
            return;
        }

        int rivalAttackPower = rival.power + (rival.level * 5);
        if (rival.skills.find("combat") != rival.skills.end())
        {
            rivalAttackPower += (rival.power * (rival.skills["combat"] * 5 / 100));
        }

        takeDamage(rivalAttackPower);
        cout << name << " took " << rival.power / 2 << " damage! Health: " << health << endl;

        if (health <= 0)
        {
            cout << name << " lose to " << rival.name << endl;
            rival.gainExprience(50);
            return;
        }
    }
}