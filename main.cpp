#include <iostream>
#include "helper.h"


using std::cout;

int main() {
    Helper testo;
    Attackable player("massiveAtoms", 10, 3, 2);
    Attackable monster("slime", 12, 1, 1);
    cout << player.strength;
    cout << "Simeple test of a battle between player and monster\n";
    Attackable winner = testo.battle(player, monster);
    cout << winner.a_name;
    return 0;
}
