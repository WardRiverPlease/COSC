#include "GameBoard.h"
#include <iostream>
#include <iomanip>
#include <ctime>
#include <cstdlib>

using namespace std;
#include "Snake.h"

GameBoard::GameBoard(int w, int h) : width(w), height(h), snake(w, h){
    board.resize(height, vector<char>(width, ' '));
    initializeBoundaries();
    placeBonus();
    placeFood();

}

int GameBoard::getWidth() const {
    return width;
}

int GameBoard::getHeight() const {
    return height;
}


void GameBoard::initializeBoundaries() {
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
          //  board[i][j] = 'x';
        }
    }
}

void GameBoard::draw_board() {
    // Print the top boundary
    for(int i = 0; i < (width - 7); i++){
        cout << "-";
    }
    for (int i = 0; i < width; ++i) {
        cout << "-" << board[0][i] << "-";
    }
    cout << endl;

    // Print the playable area and vertical boundaries
    for (int i = 1; i < height - 1; ++i) {
        cout << "|";
        for (int j = 1; j < width - 1; ++j) {
            // Check if the current position is occupied by the snake's head
            if (make_pair(i, j) == snake.getHead()) {
                cout << " S "; // Print the snake's head
            }
            // Check if the current position is occupied by the snake's body
            else {
                bool isBodyPart = false;
                for (auto& bodyPart : snake.getBody()) {
                    if (make_pair(i, j) == bodyPart) {
                        cout << " o "; // Print the snake's body
                        isBodyPart = true;
                        break;
                    }
                }
                if (!isBodyPart) {
                    cout << " " << board[i][j] << " "; // Print the game board content
                }
            }
            if (j != width - 2) {
                cout << "|";
            }
        }
        cout << "|" << endl;
    }

    // Print the bottom boundary
    for (int i = 0; i < width -7; ++i) {
        cout << "-";
    }
    for (int i = 0; i < width; ++i) {
        cout << "-"<< board[height - 1][i] << '-';
    }
}

void GameBoard::placeFood() {
    int x, y;
   
    x = 1 + rand() % (width - 2);  // Random x coordinate between 1 and width-2
    y = 1 + rand() % (height - 2); // Random y coordinate between 1 and height-2
    
    
    food_position = make_pair(y, x);
    board[y][x] = 'F';
}

void GameBoard::placeBonus() {
    int x, y;
    x = 1 + rand() % (width - 2);  // Random x coordinate between 1 and width-2
    y = 1 + rand() % (height - 2); // Random y coordinate between 1 and height-2

    bonus_position = make_pair(y, x);
    board[y][x] = 'B';
}

Snake& GameBoard::getSnake(){
    return snake;
}
