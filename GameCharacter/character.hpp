#ifndef CHARACTER_H
#define CHARACTER_H

#include <iostream>
#include <string>
#include <unordered_map>

class Character
{
private:
    std::string name;
    int health;
    int power;
    int maxHealth;
    int exprience;
    int level;
    std::unordered_map<std::string, int> skills;

public:
    Character(std::string NAME, int HEALTH, int POWER);
    void show() const;
    void addSkill(const std::string &skillName, int lvl);
    std::string get_name() const;
    void takeDamage(int damage);
    void gainExprience(int expr);
    void fight(Character &rival);
};

#endif