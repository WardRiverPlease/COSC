#include <iostream>
using namespace std;

#include "LevelManager.h"
//default constructor
LevelManager::LevelManager() 
: currentLevel(1), score(0) {}

void LevelManager::increaseScore(int amount)
{
    score += amount;
}

void LevelManager::increaseLevel()
{
    currentLevel++;
}

int LevelManager::getScore() const
{
    return score;
}

int LevelManager::getCurrentLevel() const 
{
    return currentLevel;
}

int LevelManager::resetScore() 
{
    score = 0;
    return score;
}





