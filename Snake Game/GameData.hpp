//
//  GameData.hpp
//  Snake Game
//
//  Created by Саша Татару on 18.09.2023.
//

#ifndef GameData_hpp
#define GameData_hpp

#include <stdio.h>

struct GameData {
    bool GameOver;
    const int width = 20;
    const int height = 20;
    int x, y, fruitX, fruitY, score;
    enum eDirection { Stop = 0, Left, Right, Up, Down };
    eDirection dir;
};

#endif /* GameData_hpp */
