// C++ program to gather and respond to user information in the beginning of the game, a n-dice roller and standard responses

#include <cstdlib>
#include <iostream>

using namespace std;

class displayInfo
{
public:
  char gGender, gName, gRace, gClass;

  void displayAllInfo ()
  {
    cout << "You are " << gName << ", the " << gGender << " " << gRace <<  ", " << " and a " <<
      gClass;
  }
};

class dice
{
public:
  int n; // value of dice
    
  dice(int x) // parametrized constructor input amount of faces the dice has
  {
    cout << "A " << x << " dice is rolling. . ." << endl;
    n = rand() % x; // the value of the dice
  }
};

class stdDialogue
{
  public:
    char welcomeCity, battleStart, battleEnd; // standard dialogue that can be reused
    
    welcomeCity = "Welcome, you've arrive at ";
    battleStart = "You entered in battle!";
    battleEnd = "The battle has ended.";
};
