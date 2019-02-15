//
// Created by MassiveAtoms on 2/13/2019.
//

#ifndef TRPNGINE_ENGINE_H
#define TRPNGINE_ENGINE_H

#endif //TRPNGINE_ENGINE_H

#include <ctime>
#include <cstdlib>
#include <random>
#include <array>
#include<string>
#include <windows.h>

using std::string;
using std::cout;

class Attackable {
public:
    int health;
    int strength;
    int armour;

    Attackable(int hp, int str, int arm);

private:
};

class Helper {
public:
    std::mt19937 mt;

    // constructor
    Helper();

    int diceroll(int amount, int sided);

    void display_stuff(Attackable player);

    Attackable &battle(Attackable &attacker, Attackable &target);

private:

};
/*These will be the definitions of helper member functions.
 *
 */
// constructor for helper
// seed random generator with current time
Helper::Helper()
{
    std::mt19937 mt(time(0));
}

// rand() is harmful, https://www.youtube.com/watch?v=LDPMpc-ENqY
int Helper::diceroll(int amount, int sided)
{
    int total = 0;
    for (int i = 0; i < amount; i++) {
        std::uniform_int_distribution<int> dist(1,
                                                sided);
        int roll = dist(mt);
        total += roll;
    }
    return total;
}

// totally proof of concept, this is not how damage will be generated
Attackable &Helper::battle(Attackable &attacker, Attackable &target)
{
    while (attacker.health > 0 && target.health > 0) {
        attacker.health -= diceroll(1, target.strength);
        target.health -= diceroll(1, attacker.strength);
    }
    if (attacker.health > 0) return attacker;
    return target;
}

std::array<int, 2> console_dimentions();
void Helper::display_stuff(Attackable player)
{
    std::system("CLS");
    std::array<int, 2> dims = console_dimentions();
    std::string hor_line = string(dims[0], '-');
    cout << hor_line;
    string hp = "| HP:" + std::to_string(player.health) + "   |";
    string str = "| STR: " + std::to_string(player.strength) + "  |";
    string armr = "| ARM: " + std::to_string(player.armour) + "  |";
    cout << hp << "\n" << str << "\n" << armr << '\n';
    cout << hor_line;
// obviously not done, need to look into string formatting.
/*
 * I thought of doing something right beside the hp/str/armr status screen to do something like
 * a 3 x 3 grid to have a star if you have a helmet, body arm, stuff equiped (weapon, shield) on or of
 * to do that, we need to have good string formatting. ORRRRR, we could just use a real non-console gui so we can have
 * sections to display stuff without esxcessive string formatting. thoughts?
*/
}

// ------------------------------ Attackable member function definitions ----------------------------------------->
// constructor
Attackable::Attackable(int hp, int str, int arm)
{
    if (hp <= 0 || str <= 0 || arm <= 0) {
        throw std::runtime_error("One of the values used to initialize an Attackable is 0 or less. Don't do that.");
    }
    strength = str;
    health = hp;
    armour = arm;
}


//---------------------------------------- random functions-------------------------------



std::array<int, 2> console_dimentions()
{
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    int columns, rows;

    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
    std::array<int, 2> dimensions {};
    // columns
    dimensions[0] = csbi.srWindow.Right - csbi.srWindow.Left + 1;
    // rows
    dimensions[1] = csbi.srWindow.Bottom - csbi.srWindow.Top + 1;
    return dimensions;
}