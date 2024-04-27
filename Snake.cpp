#include "Snake.h"
#include "Gameboard.h"
#include <iostream>
#include <vector>
#include <utility>


Snake::Snake(int width, int height){
    int center_x = (width - 2) / 2 + 1;
    int center_y = (height - 2) / 2 + 1;

    body.push_back({center_x, center_y});
    body.push_back({center_x + 1, center_y });
    body.push_back({center_x + 2, center_y });

}
void Snake::move(char direction) {
    int dx = 0, dy = 0;
    
    // Determine the direction of movement
    switch (direction) {
        case 'U':
            dy = -1;
            break;
        case 'D':
            dy = 1;
            break;
        case 'L':
            dx = -1;
            break;
        case 'R':
            dx = 1;
            break;
    }
    
    // Move the snake
    for (int i = body.size() - 1; i > 0; --i) {
        body[i] = body[i - 1];
    }
    body[0].first += dx;
    body[0].second += dy;
}

vector<pair<int, int>> Snake::getBody() {
    return body;
}

pair<int, int> Snake::getHead() {
    return body[0];
}
