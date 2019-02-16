//
// Created by MassiveAtoms on 2/13/2019.
//

#ifndef TRPNGINE_ENGINE_H
#define TRPNGINE_ENGINE_H

#endif // TRPNGINE_ENGINE_H

#include "items.h"
#include <array>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <random>
#include <string>
#include <windows.h>

//
#include <typeinfo>

using std::cout;
using std::string;

class Attackable {
public:
    int max_hp;
    int health;
    int strength;
    int armour;

    Attackable(int max_hp, int str, int arm);
    void equip(Helmet& item);
    void equip(Amulet& item);
    void equip(Armour& item);
    void equip(Weapon& item);
    void equip(Footwear& item);
    void consume(Consumable& Item);

private:
    Helmet helmet;
    Amulet amulet;
    Armour armor;
    Weapon weapon;
    Footwear footwear;
    // t_x is used to identify what type a wearable is for when you equip or unequip.
    // the other option was to implement equip and unequip in the various wearable base classes
    // but I have no idea how to forward declare the class from here in items, without getting
    // redefinition errors or cyclic include. Both that and the current implementation sound like bad ideas
    int t_helmet = 1;
    int t_armour = 2;
    int t_weapon = 3;
    int t_amulet = 4;
    int t_footwear = 5;
    void unequip(Helmet& item);
    void unequip(Amulet& item);
    void unequip(Armour& item);
    void unequip(Weapon& item);
    void unequip(Footwear& item);
};

class Helper {
public:
    std::mt19937 mt;

    // constructor
    Helper();

    int diceroll(int amount, int sided);

    void display_stuff(const Attackable& player);

    Attackable& battle(Attackable& attacker, Attackable& target);

private:
};
/*These will be the definitions of helper member functions.
 *
 */
// constructor for helper
// seed random generator with current time
Helper::Helper() { std::mt19937 mt(time(0)); }

// rand() is harmful, https://www.youtube.com/watch?v=LDPMpc-ENqY
int Helper::diceroll(int amount, int sided)
{
    int total = 0;
    for (int i = 0; i < amount; i++) {
        std::uniform_int_distribution<int> dist(1, sided);
        int roll = dist(mt);
        total += roll;
    }
    return total;
}

// totally proof of concept, this is not how damage will be generated
Attackable& Helper::battle(Attackable& attacker, Attackable& target)
{
    while (attacker.health > 0 && target.health > 0) {
        attacker.health -= diceroll(1, target.strength);
        target.health -= diceroll(1, attacker.strength);
    }
    if (attacker.health > 0)
        return attacker;
    return target;
}

std::array<int, 2> console_dimentions();
void Helper::display_stuff(const Attackable& player)
{
    std::system("CLS");
    std::array<int, 2> dims = console_dimentions();
    std::string hor_line = string(dims[0], '-');
    cout << hor_line;
    string hp = "| HP:" + std::to_string(player.health) + "   |";
    string str = "| STR: " + std::to_string(player.strength) + "  |";
    string armr = "| ARM: " + std::to_string(player.armour) + "  |";
    cout << hp << "\n"
         << str << "\n"
         << armr << '\n';
    cout << hor_line;
    // obviously not done, need to look into string formatting.
    /*
   * I thought of doing something right beside the hp/str/armr status screen to
   * do something like a 3 x 3 grid to have a star if you have a helmet, body
   * arm, stuff equiped (weapon, shield) on or of to do that, we need to have
   * good string formatting.
   */
}

// ------------------------------ Attackable member function definitions----------------------------

// constructor
Attackable::Attackable(int mmax_hp, int str, int arm)
    : max_hp{ mmax_hp }
    , health{ mmax_hp }
    , strength{ str }
    , armour{ arm }
{
    if (mmax_hp <= 0 || str <= 0 || arm <= 0) {
        throw std::runtime_error("One of the values used to initialize an "
                                 "Attackable is 0 or less. Don't do that.");
    }
}

void Attackable::consume(Consumable& item)
{
    health = (health + item.hp > max_hp) ? max_hp : health + item.hp;
}

void Attackable::equip(Helmet& item)
{
    unequip(item);
    helmet = item;
    max_hp += item.max_hp;
    strength += item.str;
    armour += item.armr;
}
void Attackable::equip(Armour& item)
{
    unequip(item);
    armor = item;
    max_hp += item.max_hp;
    strength += item.str;
    armour += item.armr;
}
void Attackable::equip(Amulet& item)
{
    unequip(item);
    amulet = item;
    max_hp += item.max_hp;
    strength += item.str;
    armour += item.armr;
}

void Attackable::equip(Weapon& item)
{
    unequip(item);
    weapon = item;
    max_hp += item.max_hp;
    strength += item.str;
    armour += item.armr;
}
void Attackable::equip(Footwear& item)
{
    unequip(item);
    footwear = item;
    max_hp += item.max_hp;
    strength += item.str;
    armour += item.armr;
}

void Attackable::unequip(Helmet& item)
{
    max_hp -= helmet.max_hp;
    strength -= helmet.str;
    armour -= helmet.armr;
    helmet = Helmet{};
    health = (health > max_hp) ? max_hp : health;
}
void Attackable::unequip(Amulet& item)
{
    max_hp -= amulet.max_hp;
    strength -= amulet.str;
    armour -= amulet.armr;
    amulet = Amulet{};
    health = (health > max_hp) ? max_hp : health;
}
void Attackable::unequip(Armour& item)
{
    max_hp -= armor.max_hp;
    strength -= armor.str;
    armour -= armor.armr;
    armor = Armour{};
    health = (health > max_hp) ? max_hp : health;
}

void Attackable::unequip(Weapon& item)
{
    max_hp -= weapon.max_hp;
    strength -= weapon.str;
    armour -= weapon.armr;
    weapon = Weapon{};
    health = (health > max_hp) ? max_hp : health;
}

void Attackable::unequip(Footwear& item)
{
    max_hp -= footwear.max_hp;
    strength -= footwear.str;
    armour -= footwear.armr;
    footwear = Footwear{};
    health = (health > max_hp) ? max_hp : health;
}

//---------------------------------------- random_functions-------------------------------

std::array<int, 2> console_dimentions()
{
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    int columns, rows;

    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
    std::array<int, 2> dimensions{};
    // columns
    dimensions[0] = csbi.srWindow.Right - csbi.srWindow.Left + 1;
    // rows
    dimensions[1] = csbi.srWindow.Bottom - csbi.srWindow.Top + 1;
    return dimensions;
}
