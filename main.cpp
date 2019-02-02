// C++ program to gather and respond to user information in the beginning of the game

#include <cstdlib>
#include <iostream>

using namespace std;

class displayInfo
{
public:
  char gender, name, race, playerClass;

  void displayAllInfo ()
  {
    cout << "You are " << name << ", the " << gender << " " << race <<  ", " << " and a " <<
      playerClass;
  }
};

class dice
{
public:
  int n; \\ value of dice
    
  dice(int x) \\ parametrized constructor input amount of faces the dice has
  {
    cout << "A " << x << "is rolling. . ." << endl;
    n = rand() % x; \\ the value of the dice
  }
};
