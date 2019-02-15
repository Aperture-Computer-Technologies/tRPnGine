//
// Created by MassiveAtoms on 2/13/2019.
//

#ifndef TRPNGINE_ENGINE_H
#define TRPNGINE_ENGINE_H

#endif //TRPNGINE_ENGINE_H

#include <ctime>
#include <cstdlib>
#include <random>


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
//    void display_stuff(Attackable player);


    Attackable &battle(Attackable &attacker, Attackable &target);

private:

};

// constructor for helper
Helper::Helper() {
    std::mt19937 mt(time(0));                // seed random generator with current time
}

int Helper::diceroll(int amount, int sided) {
    int total = 0;
    for (int i = 0; i < amount; i++) {
        std::uniform_int_distribution<int> dist(1, sided); // rand() is harmful, https://www.youtube.com/watch?v=LDPMpc-ENqY
        int roll = dist(mt);
        total += roll;
    }
    return total;
}

// totally proof of concept, this is not how damage will be generated
Attackable &Helper::battle(Attackable &attacker, Attackable &target) {
    while (attacker.health > 0 && target.health > 0) {
        attacker.health -= diceroll(1, target.strength);
        target.health -= diceroll(1, attacker.strength);
    }
    if (attacker.health > 0) return attacker;
    return target;
}

//
//void Helper::display_stuff(Attackable player) {
//    std::
//}









// constructor
Attackable::Attackable(int hp, int str, int arm) {
    if (hp <= 0 || str <= 0 || arm <= 0) {
        throw std::runtime_error("One of the values used to initialize an Attackable is 0 or less. Don't do that.");
    }
    strength = str;
    health = hp;
    armour = arm;
}


