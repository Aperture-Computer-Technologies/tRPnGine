//
// Created by MassiveAtoms on 2/5/2019.
//

#ifndef TRPNGINE_HELPER_H
#define TRPNGINE_HELPER_H

#endif //TRPNGINE_HELPER_H

#include "attackables.h"


class Helper {
public:
    // constructor
    Helper();

    int diceroll(int amount, int sided);

    Attackable &battle(Attackable &attacker, Attackable &attackee);

private:

};