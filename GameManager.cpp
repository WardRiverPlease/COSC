#include "DoubleScore.h"
#include "GameManager.h" // Include GameManager.h after DoubleScore.h
#include <iostream>
#include <conio.h>
#include <cstdlib>
#include <iomanip>

using namespace std;

GameManager::GameManager(int width, int height)
    : gameBoard(width, height), game_over(false), LevelManager(), activePowerUp(nullptr)
{
    turnsLeft = LevelManager.getCurrentLevel() + 1;
    srand(time(NULL));
}

void GameManager::startGame()
{
    gameBoard.draw_board(LevelManager.getScore(), LevelManager.getCurrentLevel());
    char direction;
    while (!game_over)
    {
        direction = _getch();
        handleInput(direction);
        if (turnsLeft == 0)
        {
            updateGame();
            turnsLeft = LevelManager.getCurrentLevel() + 1;
            gameBoard.draw_board(LevelManager.getScore(), LevelManager.getCurrentLevel());
        }
    }
}

void GameManager::handleInput(char direction)
{
    if (direction == 'Q' || direction == 'q')
    {
        game_over = true;
        cout << "OPTIONS";
    }
    else
    {

        gameBoard.getSnake().move(direction);
        turnsLeft--;

        if (isGameOver())
        {
            game_over = true;
        }
        //check collision with food
           if (gameBoard.checkCollisionWithFood())
    {
        int score = 100;
        
        if (activePowerUp != nullptr && activePowerUp->isActive())
        {
           activePowerUp->applyPower(score);
        }

        LevelManager.increaseScore(score);
    }
        //check collision with bonus
        if (gameBoard.checkCollisionWithBonus())
        {
            gameBoard.setBonusSpawned(false); //reset bonus char
            if (activePowerUp != nullptr)
            {
                delete activePowerUp;
            }
            activePowerUp = new DoubleScore(); // Allocate memory for DoubleScore
        }
    //    if (activePowerUp != nullptr && activePowerUp->isActive())
    //    {
    //        LevelManager.increaseScore(100);
    //    }
        if (LevelManager.getScore() >= 1000)
        {
            LevelManager.increaseLevel();
            LevelManager.resetScore();
            gameBoard.placeBonus(); // Place the bonus item when a new level is reached
            gameBoard.setBonusSpawned(true);
        }
    }
}

bool GameManager::isGameOver()
{
    if (gameBoard.getSnake().checkCollisionWithItself() || gameBoard.getSnake().checkCollisionWithBoundaries(gameBoard.getWidth(), gameBoard.getHeight()))
    {
        game_over = true;
    }
    return game_over;
}

void GameManager::updateGame()
{
    if (gameBoard.getSnake().checkCollisionWithItself())
    {
        game_over = true;
    }
     if (gameBoard.checkCollisionWithFood())
    {
        int score = 100;
        
        if (activePowerUp != nullptr && activePowerUp->isActive())
        {
           activePowerUp->applyPower(score);
        }

        LevelManager.increaseScore(score);
    }
    if (gameBoard.checkCollisionWithBonus())
    {
        gameBoard.setBonusSpawned(false);
    }

    if (LevelManager.getScore() >= 1000)
    {
        LevelManager.increaseLevel();
        LevelManager.resetScore();
        gameBoard.placeBonus(); // Place the bonus item when a new level is reached
        gameBoard.setBonusSpawned(true);
    }

    gameBoard.draw_board(LevelManager.getScore(), LevelManager.getCurrentLevel());
}

void GameManager::TitleScreen()
{
    cout << "Welcome to...." << endl;
    cout << " ____              _           ____                      " << endl;
    cout << "/ ___| _ __   __ _| | _____   / ___| __ _ _ __ ___   ___ " << endl;
    cout << " \\___ \\| '_ \\ / _` | |/ / _ \\ | |  _ / _` | '_ ` _ \\ / _ \\ " << endl;
    cout << " ___) | | | | (_| |   <  __/ | |_| | (_| | | | | | |  __/" << endl;
    cout << "|____/|_| |_|\\__,_|_|\\_\\___|  \\____|\\__,_|_| |_| |_|\\___|" << endl;
    cout << endl;
}

void GameManager::StartScreen()
{
    system("cls");
    TitleScreen();
    cout << "**************************************************************" << endl;
    cout << "- 1: Start new game" << endl;
    cout << "- 2: Load saved game" << endl;
    cout << "**************************************************************" << endl;

    int NewGameOption;
    cin >> NewGameOption;
    char GameMenuOption;
    bool Exit;
    if (NewGameOption == 1)
    {
        cout << "**************************************************************" << endl;
        cout << "Would you look a tutorial? Y/N" << endl;
        cout << "**************************************************************" << endl;
        cin >> GameMenuOption;
        if (GameMenuOption == 'Y' || GameMenuOption == 'y')
        {
            Exit = true;
        }
    }
    while (Exit)
    {
        if (GameMenuOption == 'Y' || GameMenuOption == 'y')
        {
            cout << "***************************************************************" << endl;
            cout << "[How to play] :" << endl;
            cout << "     - Basics : " << endl;
            cout << "    This game is a spin on the 90's original game: Snake. In this version  " << endl;
            cout << "    you have turns to move the snake according to which level you are in " << endl;
            cout << "    level 1 - One Turn Level 2 - Two turns...so on and so forth" << endl;
            cout << "     - Movment :" << endl;
            cout << "    To move you will use W A S D (W - UP; A - LEFT; S - DOWN; D - RIGHT)" << endl;
            cout << "     - Winning the Game : " << endl;
            cout << "    Each Food item will give you 100 points. To move up levels you will  " << endl;
            cout << "    need to reach the score of 2000. Finishing level 10, WINS you the game " << endl;
            cout << "     - Losing the Game: " << endl;
            cout << "    The player loses the game when the snake collides with itself, or the " << endl;
            cout << "    snake collides with the game boarder" << endl;
            cout << "     - Bonus Items: " << endl;
            cout << "    Bonus Items will be randomizes around the board, giving you advantages" << endl;
            cout << "    help you complete the game! The power will be randomized everytime" << endl;
            cout << "**********************************************************" << endl;
            cout << "Would you like to start the game? Y" << endl;
            cout << "**********************************************************" << endl;
            cin >> GameMenuOption;
            if (GameMenuOption == 'Y' || GameMenuOption == 'y')
            {
                Exit = false;
            }
        }
        else if (GameMenuOption == 'N' || GameMenuOption == 'n')
        {
            cout << "**********************************************************" << endl;
            cout << "Starting Game..." << endl;
            cout << "**********************************************************" << endl;
            Exit = false;
        }
        else
        {
            cout << "**********************************************************" << endl;
            cout << "Please choose an option" << endl;
            cout << "Would you like to start the game Y? " << endl;
            cout << "**********************************************************" << endl;
            cin >> GameMenuOption;
        }
    }
    startGame();
}

void GameManager::GameOverMessage()
{
    if (gameBoard.getSnake().checkCollisionWithBoundaries(gameBoard.getWidth(), gameBoard.getHeight()))
    {
        cout << "**********************************************************" << endl;
        cout << "GAME OVER! You lost" << endl;
        cout << "Reason: Collision with Boundary" << endl;
        cout << "Death on Level: " << LevelManager.getCurrentLevel() << endl;
        cout << "**********************************************************" << endl;
    }
    if (gameBoard.getSnake().checkCollisionWithItself())
    {
        cout << "**********************************************************" << endl;
        cout << "GAME OVER! You lost" << endl;
        cout << "Reason: Collision with yourself" << endl;
        cout << "Death on Level: " << LevelManager.getCurrentLevel() << endl;
        cout << "**********************************************************" << endl;
    }
}
