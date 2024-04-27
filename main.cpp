#include <iostream>
#include <conio.h>
#include "GameBoard.h"
#include "Snake.h"
using namespace std;

int main(){
    srand(time(NULL));
    GameBoard gameboard(15,15);
    gameboard.draw_board();





    return 0;
}