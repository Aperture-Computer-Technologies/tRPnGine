//
// Created by MassiveAtoms on 2/5/2019.
//

#ifndef TRPNGINE_ATTACKACKABLES_H
#define TRPNGINE_ATTACKACKABLES_H

#endif //TRPNGINE_ATTACKACKABLES_H

#include <string>
#include <stdexcept>


class Attackable {
public:
    std::string a_name;
    int health;
    int strength;
    int armour;

    Attackable(std::string name, int hp, int str, int arm);

private:
};