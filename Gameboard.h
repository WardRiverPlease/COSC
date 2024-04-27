#ifndef GAMEBOARD_H
#define GAMEBOARD_H

#include "Snake.h"
#include <vector>
#include <utility>

using namespace std;

class GameBoard {
private:
    int width;
    int height;
    pair<int, int> food_position;
    pair<int, int> bonus_position;
    vector<vector<char>> board;
    
  //  Snake snake;
    
public:
    GameBoard(int w, int h);
    void placeFood();
    void placeBonus();
    void initializeBoundaries();
    void draw_board();
    // Additional methods to update snake position, food position, etc.
    //Snake Classes
 //   void moveSnake(char direction);
 //   void updateGame();
};

#endif // GAMEBOARD_H