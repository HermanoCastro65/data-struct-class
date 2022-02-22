#include <iostream>
using namespace std;

#define MAX_CHIPS 10
#define MAX_TURN 3

int main()
{
  bool player1Turn = true;
  bool gameOver = false;

  int chipsInPile = 0;
  int chipsTaken = 0;

  string playerName[2];

  // seed the random number generator
  srand(time(0));

  // ask the playersfor their names, than store in an array
  cout << "Player 1, please enter your name: ";
  cin >> playerName[0];
  cout << "\nThanks and good luck!" << endl
       << "Player 2, please enter your name: ";
  cin >> playerName[1];
  cout << "\nThanks and good luck! \n";

  // start the game with a random number of chips in the pile
  chipsInPile = (rand() % MAX_CHIPS) * 1;
  cout << "This round will strat with " << chipsInPile << " chips in the pile \n";

  if (player1Turn)
  {
    cout << playerName[0] << " how many chips you like? \n";
  }
  else
  {
    cout << playerName[1] << " how many chips you like? \n";
  }
  cout << "You can take up to " << static_cast<int>(MAX_TURN * chipsInPile) << endl;
  cin >> chipsTaken;

  return 0;
}