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

class dice // roll one dice
{
public:
  int oneDice; // value of dice
    
  dice(int x) // parametrized constructor input amount of faces the dice has
  {
    cout << "A " << x << " dice is rolling. . ." << endl;
    oneDice = rand() % x; // the value of the dice
  }
};

class multiDice // roll multiple dice
{
  int multiDiceSum; // sum of dice values
  
  multiDice(int x, int y)
  {
    int i, j = 0, k;
    cout << x << y << "-side dices are rolling. . ." << endl;
    for(k = 0; k < x; k++)
    {
        i = rand() % y;
        cout << i << "\t";
        j = j + i;
    }
    multiDiceSum = j;
  }
};

class stdDialogue
{
  public:
    char welcomeCity, battleStart, battleEnd, levelUp, newSkill, newItem; // standard dialogue that can be reused
    
    welcomeCity = "Welcome, you've arrived at ";
    battleStart = "You entered in battle!";
    battleEnd = "The battle has ended.";
    levelUp = "Congratulations, you are now lv.";
    newSkill = "You've achieved ";
    newItem = "You've found ";
};
