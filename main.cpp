#include <iostream>
#include "helper.h"


using std::cout;

int main() {
    Helper testo;
    Attackable player(10, 3, 2);
    Attackable monster(12, 1, 1);
    Attackable winner = testo.battle(player, monster);
    return 0;
}
