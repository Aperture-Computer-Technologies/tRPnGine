//
// Created by MassiveAtoms on 2/5/2019.
//

#include "attackables.h"


// constructor
Attackable::Attackable(std::string name, int hp, int str, int arm) {
    if (hp <= 0 || str <= 0 || arm <= 0) {
        throw std::runtime_error("One of the values used to initialize an Attackable is 0 or less. Don't do that.");
    }
    a_name = name;
    strength = str;
    health = hp;
    armour = arm;
}
