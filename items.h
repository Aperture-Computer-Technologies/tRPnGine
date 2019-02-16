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
    int max_hp;
    int str;
    int armr;
    int hp;

protected:
    bool dummy = true;
    Item(){};
};

class Consumable : public Item {
public:
    virtual void does_nothing(){};
protected:
    bool dummy = true;
};


////////////////////////////////////////
class Wearable : public Item {
public:
    int type = 0;
    virtual void does_nothing(){}; // only to make wearable virtual so it can't be initialized
protected:
    bool dummy = true;
};

class Helmet : public Wearable {
public:
    int type = 1;
    void does_nothing(){};

protected:
};
class Armour : public Wearable {
public:
    int type = 2;
    void does_nothing(){};

protected:
};
class Weapon : public Wearable {
public:
    int type = 3;
    void does_nothing(){};

protected:
};

class Amulet : public Wearable {
public:
    int type = 4;
    void does_nothing(){};

protected:
};

class Footwear : public Wearable {
public:
    int type = 5;
    void does_nothing(){};

protected:
};

//-------------------------real items ------------------
class ShitWeapon : public Weapon {
    int str{ 2 };
    int max_hp{ 0 };
    int armr{ 0 };
};

class ShitSandal : public  Footwear {
    int max_hp{ 0 };
    int str{ 2 };
    int armr{ 0 };
};
#include <iostream>
class FineAmulet : public Amulet {
public:
    int max_hp{ 2 };
    int str{ 2 };
    int armr =-1;
    FineAmulet(){
        std::cout << "Fineamulet:" << armr << "\n";
    }
};

class Health_potion : public Consumable {
    int hp{ 100 };
    
};
