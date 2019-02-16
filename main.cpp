#include "engine.h"
#include <iostream>

using std::cout;

int main()
{
    Helper testo;
    Attackable player(100, 100, 100);
    FineAmulet loot3;

    for (int i = 0; i < 5; i++) {
        player.equip(loot3);
        system("PAUSE");
        testo.display_stuff(player);
    }

    return 0;
}
