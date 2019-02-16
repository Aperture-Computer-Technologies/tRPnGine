#include <iostream>
#include "engine.h"


using std::cout;

int main() {
    Helper testo;
    Attackable player(100, 100, 100);
    player.health -= 50;
    ShitWeapon loot1;
    ShitSandal loot2;
    FineAmulet loot3;
    Health_potion loot4;
    testo.display_stuff(player);
    system("PAUSE");
    player.equip(loot3);
    testo.display_stuff(player);
    system("PAUSE");
    player.consume(loot4);
    testo.display_stuff(player);
    system("PAUSE");
    player.equip(loot2);
    testo.display_stuff(player);
    system("PAUSE");
    player.equip(loot1);
    testo.display_stuff(player);
    system("PAUSE");
    player.equip(loot1);
    testo.display_stuff(player);



    return 0;
}
