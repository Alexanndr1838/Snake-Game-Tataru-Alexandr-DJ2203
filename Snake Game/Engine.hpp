//
//  Engine.hpp
//  Snake Game
//
//  Created by Саша Татару on 04.10.2023.
//

#ifndef Engine_hpp
#define Engine_hpp

#include "GameData.hpp"
#include <stdio.h>

class Engine {
public:
    void Logic(GameData &gameData) {
        switch (gameData.dir) {
            case GameData::Left:
                gameData.x--;
                break;
            case GameData::Right:
                gameData.x++;
                break;
            case GameData::Up:
                gameData.y--;
                break;
            case GameData::Down:
                gameData.y++;
                break;
            default:
                break;
        }

        if (gameData.x >= gameData.width || gameData.x < 0) {
            gameData.GameOver = true;
        }
        if (gameData.y >= gameData.height || gameData.y < 0) {
            gameData.GameOver = true;
        }

        if (gameData.x == gameData.fruitX && gameData.y == gameData.fruitY) {
            gameData.score += 100;
        }
    }
};

#endif /* Engine_hpp */
