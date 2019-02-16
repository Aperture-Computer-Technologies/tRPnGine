/*
This will contain all the items used in the game
layout of item inheritance
Item
|-Consumable
|-Wearable
||--Helmet
||--Armour
||--Footwear
||--Amulet
||--Weapon
*/

// item base classes
// TODO: LOOK into how you can set the base classes like java, so they can't be initialized

class Item {
public:
    int max_hp{ 0 };
    int str{ 0 };
    int armr{ 0 };
    int hp{ 0 };

protected:
    bool dummy = true;
    Item(){};
};

class Consumable : public Item {
protected:
    bool dummy = true;
    Consumable();
};

class Wearable : virtual public Item {

protected:
    Wearable(){};
    bool dummy = true;
};

class Helmet : public Wearable {
protected:
    bool dummy = true;
    // Helmet();
};
class Armour : public Wearable {
protected:
    bool dummy = true;
    // Armour();
};
class Weapon : public Wearable {
protected:
    bool dummy = true;
    // Weapon();
};
class Footwear : public Wearable {
protected:
    bool dummy = true;
    // Footwear();
};

class Amulet : public Wearable {
protected:
    bool dummy = true;
    // Amulet();
};

//-------------------------real items ------------------
class ShitWeapon : Weapon {
    int str{ 2 };
    int max_hp{ 0 };
    int armr{ 0 };
};

class ShitSandal : Footwear {
    int max_hp{ 0 };
    int str{ 2 };
    int armr{ 0 };
};

class FineAmulet : Amulet {
    int max_hp{ 2 };
    int str{ 2 };
    int armr{ -1 };
};

class Health_potion : Consumable {
    int hp{ 100 };
};
