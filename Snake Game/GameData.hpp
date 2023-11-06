//
//  GameData.hpp
//  Snake Game
//
//  Created by Саша Татару on 18.09.2023.
//

#ifndef GameData_hpp
#define GameData_hpp

#include <stdio.h>
#include <vector>
#include <algorithm>

struct GameData {
    bool GameOver;
    const int width = 18;
    const int height = 15;
    std::vector<int> tailX;
    std::vector<int> tailY;
    int numtail;
    int x, y, fruitX, fruitY, score;
    enum eDirection { Stop = 0, Left, Right, Up, Down };
    eDirection dir;
    
    GameData() : GameOver(false), width(18), height(15), x(0), y(0), fruitX(0), fruitY(0), score(0), dir(Stop) {}
    
    GameData(const GameData &other)
        : GameOver(other.GameOver), width(other.width), height(other.height), x(other.x), y(other.y),
          fruitX(other.fruitX), fruitY(other.fruitY), score(other.score), dir(other.dir) {}

    GameData& operator=(const GameData &other) {
        if (this != &other) {
            GameOver = other.GameOver;
            x = other.x;
            y = other.y;
            fruitX = other.fruitX;
            fruitY = other.fruitY;
            score = other.score;
            dir = other.dir;
        }
        return *this;
    }
};

#endif /* GameData_hpp */

