// C++ program to gather and respond to user information in the beginning of the game

#include <cstdlib>
#include <iostream>

using namespace std;

class displayInfo
{
public:
  string class, gender, name, race;

  void displayAllInfo ()
  {
    cout << "You are " << name << ", " << gender << ", " << " and a " <<
      class;
  }
};

//create class for dice rolling with n dice
