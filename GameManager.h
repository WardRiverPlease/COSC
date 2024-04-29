#ifndef GAMEMANAGER_H
#define GAMEMANAGER_H

#include "GameBoard.h"
#include "Snake.h"
#include "LevelManager.h"
#include "PowerUp.h"
#include "DoubleScore.h"


class GameManager {
private:
    GameBoard gameBoard;
    bool game_over;  
    LevelManager LevelManager; 
    int turnsLeft;

    PowerUp* activePowerUp;


public:
    void StartScreen();
    GameManager(int width, int height);
    void startGame();
    void handleInput(char direction);
    bool isGameOver();
    void updateGame();
    void TitleScreen();
    void GameOverMessage();
    
    
};

#endif
