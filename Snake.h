#ifndef SNAKE_H
#define SNAKE_H

#include <vector>
#include <utility> // for std::pair

using namespace std;

class Snake {
private:
    vector<pair<int, int>> body; // stores positions of snake's body segments

public:
    Snake(int width, int height); // constructor to initialize the snake
    void move(char direction); // move the snake in a direction (U, D, L, R)
    vector<pair<int, int>> getBody(); // get the current body positions
    pair<int, int> getHead(); // get the position of the snake's head
    bool checkCollision(pair<int, int> newPosition, int width, int height); // Add width and height parameters
    void grow(); // grow the snake by adding a body segment
};

#endif // SNAKE_H
