#include "DoubleScore.h"

DoubleScore::DoubleScore() : active(false) {}

void DoubleScore::applyPower(int score) {
    // Apply the power-up effect to the score (double the score per food item)
    if(isActive()){
        score *= 2;
    }
}

bool DoubleScore::isActive() const {
    return active;
}

void DoubleScore::reset() {
    active = false;
}
