//
// Created by MassiveAtoms on 2/5/2019.
//
#include <ctime>
#include <cstdlib>

#include "helper.h"


// constructor for helper
Helper::Helper() {
    std::srand(time(0));                // seed random generator with current time
}

int Helper::diceroll(int amount, int sided) {
    int total = 0;
    for (int i = 0; i < amount; i++) {
        int roll = std::rand() % sided + 1;
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