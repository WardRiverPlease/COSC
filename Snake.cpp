#include "Snake.h"
#include "Gameboard.h"
#include <iostream>
#include <vector>
#include <utility>


Snake::Snake(int width, int height) {
    int center_x = (width - 2) / 2 + 1;
    int center_y = (height - 2) / 2 + 1;

    // Initialize the snake with three body segments
    body.push_back({ center_x, center_y });
    body.push_back({ center_x + 1, center_y });
    body.push_back({ center_x + 2, center_y });
}


void Snake::move(char direction) {
    pair<int, int> head = body.front();
    int dx = head.first;
    int dy = head.second;
   

    // Determine the direction of movement
    switch (direction) {
        case 'W':
        case 'w':
            dx--; //dx--
            break;
        case 'D':
        case 'd':
            dy++;  //dy++
            break;
        case 'A':
        case 'a':
            dy--; //dy--
            break;
        case 'S':
        case 's':
            dx++; //dx++
            break;
        default:
            cout << "please enter a direction (U, D, L, R)";
            return;
    }

    // Create a new head position based on the direction
    body.insert(body.begin(), make_pair(dx, dy));
    // Move the snake's body segment

    // Update the snake's head position
    body.pop_back();
}

vector<pair<int, int>> Snake::getBody() {
    return body;
}

pair<int, int> Snake::getHead() {
    return body[0];
}

void Snake::grow(){
    pair<int, int> tail = body.back();
    body.push_back(tail);
}
