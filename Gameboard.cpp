#include "GameBoard.h"
#include <iostream>
#include <iomanip>
#include <ctime>
#include <cstdlib>

using namespace std;
#include "Snake.h"
#include "LevelManager.h"

GameBoard::GameBoard(int w, int h) : width(w), height(h), bonusSpawned(false), snake(w, h)


{
    board.resize(height, vector<char>(width, ' '));
    initializeBoundaries();
   // srand(time(NULL));
    placeBonus();
    placeFood();

}

int GameBoard::getWidth() const 
{
    return width;
}

int GameBoard::getHeight() const 
{
    return height;
}

void GameBoard::setBonusSpawned(bool value){
    bonusSpawned = value;
}


void GameBoard::initializeBoundaries() 
{
    // Fill horizontal boundaries
    for (int i = 0; i < width; ++i) {
        
        board[0][i] = '-';
        board[height - 1][i] = '-';
    }

    // Fill vertical boundaries
    for (int i = 0; i < height - 2; ++i) {
    
        board[i + 1][0] = '|';
       // board[i][width - 1] = '|';
    }

    // Fill the playable area with 'x'
    for (int i = 1; i < height - 1; ++i) {
        for (int j = 1; j < width - 1; ++j) {
          //  board[i][j] = '_';
        }
    }
}

void GameBoard::draw_board(int score, int level) 
{
    system("cls");
    // Print the top boundary
    cout << "***********************************************************************************************";
    cout << endl;
    for(int i = 0; i < (width - 7); i++)
    {
        cout << "-";
    }
    for (int i = 0; i < width  ; ++i) 
    {
        cout << "-" << board[0][i] << "-";
    }
    cout << endl;
    // Print the playable area and vertical boundaries
    for (int i = 1; i < height - 1; ++i) 
    {
        cout  << "|";
        for (int j = 1; j < width - 1; ++j) 
        {
            // Check if the current position is occupied by the snake's head
            if (make_pair(i, j) == snake.getHead()) 
            {
                cout << " S "; // Print the snake's head
            }
            // Check if the current position is occupied by the snake's body
            else{
                bool isBodyPart = false;
                for (auto& bodyPart : snake.getBody()) 
                {
                    if (make_pair(i, j) == bodyPart) 
                    {
                        cout << " o "; // Print the snake's body
                        isBodyPart = true;
                        break;
                    }
                }
                if (!isBodyPart) 
                {
                    cout << " " << board[i][j] << " "; // Print the game board content
                }
            }
            if (j != width - 2) 
            {
                cout << "|";
            }
        }
        cout << "|" << endl;
    }
   
    // Print the bottom boundary
    for (int i = 0; i < width -7; ++i) 
    {
        cout << "-";
    }
    for (int i = 0; i < width; ++i) 
    {
        cout << "-"<< board[height - 1][i] << '-';
    }
    cout << endl;
    cout << "***********************************************************************************************" << endl;
    cout << "                                       Quit? Q/q" << endl;
    cout << "                                       Score: " << score  << endl;
    cout << "                                       Level: " << level << endl;
    cout << endl;
}

void GameBoard::placeFood() 
{
    int old_x = food_position.second;
    int old_y = food_position.first;
    board[old_y][old_x] = ' ';
    int x, y;
   
  // srand(time(NULL));
  do{
    x = 1 + rand() % (width - 2);  // Random x coordinate between 1 and width-2
    y = 1 + rand() % (height - 2); // Random y coordinate between 1 and height-2
  }while(board[y][x] == 'B');

    food_position = make_pair(y, x);
    board[y][x] = 'F';
}
// GameBoard.cpp

void GameBoard::placeBonus() {
    int old_x = bonus_position.second;
    int old_y = bonus_position.first;
    board[old_y][old_x] = ' '; // Clear the cell where the bonus item was placed
    if(!bonusSpawned){
        int x, y;
        do {
            x = 1 + rand() % (width - 2);  // Random x coordinate between 1 and width-2
            y = 1 + rand() % (height - 2); // Random y coordinate between 1 and height-2
        } while (board[y][x] == 'F');

        bonus_position = make_pair(y, x);
        board[y][x] = 'B';
        bonusSpawned = true;
        
    }
}



Snake& GameBoard::getSnake()
{
    return snake;
}

bool GameBoard::checkCollisionWithFood()
{
    pair<int, int> head = snake.getHead();
    if(head == food_position)
    {
        placeFood();
        snake.grow();
        return true;
    }
    return false;

}
bool GameBoard::checkCollisionWithBonus() {
    pair<int, int> head = snake.getHead();

    if (head == bonus_position) {
        setBonusSpawned(false); // Reset bonusSpawned
        board[bonus_position.first][bonus_position.second] = ' '; // Clear the cell with the bonus item *****
     
        return true;
    }
    for (auto& bodyPart : snake.getBody()) {
        if (bodyPart == bonus_position) {
            setBonusSpawned(false); // Reset bonusSpawned
            board[bonus_position.first][bonus_position.second] = ' '; // Clear the cell with the bonus item *****
           
            return true;
        }
    }
    return false;
}



