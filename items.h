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
//

class Item {
public:
    int max_hp = 0;
    int str = 0;
    int armr = 0;
    int hp = 0;

protected:
    Item(){};
};

class Consumable : public Item {
public:
protected:
};

////////////////////////////////////////
class Wearable : public Item {
public:
    int type = 0;
    virtual ~Wearable(){};

protected:
};

class Helmet : public Wearable {
public:
    int type = 1;

protected:
};
class Armour : public Wearable {
public:
    int type = 2;

protected:
};
class Weapon : public Wearable {
public:
    int type = 3;

protected:
};

class Amulet : public Wearable {
public:
    int type = 4;

protected:
};

class Footwear : public Wearable {
public:
    int type = 5;

protected:
};

//-------------------------real items ------------------
class ShitWeapon : public Weapon {
public:
    ShitWeapon()
    {
        str = 2;
        max_hp = 0;
        armr = 0;
    }
};

class ShitSandal : public Footwear {
public:
    ShitSandal()
    {
        max_hp = 0;
        str = 2;
        armr = 0;
    }
};
class FineAmulet : public Amulet {
public:
    FineAmulet()
    {
        max_hp = 32;
        str = 2;
        armr = -1;
    }
};

class Health_potion : public Consumable {
public:
    Health_potion() { hp = 100; };
};
