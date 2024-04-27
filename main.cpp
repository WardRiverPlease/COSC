#include <iostream>
#include <conio.h>
#include "GameBoard.h"
#include "Snake.h"
using namespace std;

int main(){
   // srand(time(NULL));
    GameBoard gameboard(15,15);
    gameboard.draw_board();
 

    char direction;
    bool game_over = false;

    

    while(!game_over){
        
        direction = _getch();
        if (direction == 'W' || direction == 'w' || direction == 'S' || direction == 's' ||
            direction == 'D' || direction == 'd' || direction == 'A' || direction == 'a') {
            // Move the snake
            gameboard.getSnake().move(direction);
            
            // Redraw the game board with the updated snake position
            
            gameboard.draw_board();
        } else if (direction == 'Q' || direction == 'q') {
            // Quit the game if the user presses 'Q'
            game_over = true;
        }
        if(gameboard.checkCollisionWithFood()){
            gameboard.getSnake().grow();
         //   gameboard.placeFood();
        }

      //  gameboard.draw_board();
    }




    return 0;
}
