#include <iostream>
#include <conio.h>
#include "GameManager.h"
#include "GameBoard.h"
using namespace std;

int main(){ 
  srand(time(NULL)); 
  GameManager gameManager(25,25);
  gameManager.StartScreen();

  if(gameManager.isGameOver())
  {
    gameManager.GameOverMessage();
    cout << "**********************************************************" << endl;
    cout << "Would you like to play Again? Y/N" << endl;
    cout << "**********************************************************" << endl;
    char PlayAgain;
    cin >> PlayAgain;
    if(PlayAgain == 'Y' || PlayAgain == 'y')
    {
      GameManager gameManager(25,25);
      gameManager.StartScreen();
    }else
    {
      cout << "**********************************************************" << endl;
      cout << "Thank you for playing!" << endl;
      cout << "**********************************************************" << endl;
    }
  }



    return 0;
} 
