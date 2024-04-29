#ifndef GAMEBOARD_H
#define GAMEBOARD_H

#include "Snake.h"
#include "LevelManager.h"

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
    bool bonusSpawned;
    Snake snake;


    
public:
    bool checkCollisionWithFood();
    bool checkCollisionWithBonus();
    void setBonusSpawned(bool value);
    int getWidth() const;
    int getHeight() const ;
    GameBoard(int w, int h);
    void placeFood();
    void placeBonus();
    void initializeBoundaries();
    void draw_board(int score, int level);
    Snake& getSnake();
    


 
};

#endif 
