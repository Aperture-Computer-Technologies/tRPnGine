#include <iostream>
#include "engine.h"


using std::cout;

int main() {
    Helper testo;
    Attackable player(10, 3, 2);

    for (int n = 0; n < 12; n++) {
        cout << n << ":";
        for (int i = 0; i < 10; i++) {
            cout << testo.diceroll(1, n) << ",";
        }

        cout << "\n";


    }

    for (int i = 0; i < 5; i++) testo.display_stuff(player);


    return 0;
}
