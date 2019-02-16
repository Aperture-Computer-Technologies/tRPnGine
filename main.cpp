#include <iostream>
#include "engine.h"


using std::cout;

int main() {
    Helper testo;
    Attackable player(10, 3, 2);

    FineAmulet loot3;
    Health_potion loot4;
    cout << "Loot3 armr:" << loot3.armr << "\n";
    cout << "Player armr be4 amulet equip:" << player.armour << "\n";
    player.equip(loot3);
cout << "Player armr be4 amulet equip:" << player.armour << "\n";




    return 0;
}
