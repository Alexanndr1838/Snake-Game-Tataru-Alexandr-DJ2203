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
#include <cstdlib>
#include <time.h>

class Engine {
public:
    
    GameData& gameData;

    Engine(GameData& gd) : gameData(gd) {}

    Engine(int initialX, int initialY, GameData& gd) : gameData(gd) {
        gameData.x = initialX;
        gameData.y = initialY;
    }
    
    void Logic(GameData &gameData) {
        int prevX = gameData.tailX.empty() ? 0 : gameData.tailX[0];
        int prevY = gameData.tailY.empty() ? 0 : gameData.tailY[0];
        
        int prev2X;
        int prev2Y;
        
        if (!gameData.tailX.empty()) {
            gameData.tailX[0] = gameData.x;
            gameData.tailY[0] = gameData.y;
        }
        
        for (int i = 1; i < gameData.numtail; i++) {
            if (i < gameData.tailX.size() && i < gameData.tailY.size()) {
                prev2X = gameData.tailX[i];
                prev2Y = gameData.tailY[i];
                
                gameData.tailX[i] = prevX;
                gameData.tailY[i] = prevY;
                
                prevX = prev2X;
                prevY = prev2Y;
            }
        }
        
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
        
        auto collision = std::find(gameData.tailX.begin(), gameData.tailX.begin() + gameData.numtail, gameData.x);
            if (collision != gameData.tailX.begin() + gameData.numtail && gameData.tailY[collision - gameData.tailX.begin()] == gameData.y) {
                gameData.GameOver = true;
            }
        
        if (gameData.x >= gameData.width || gameData.x < 0) {
            gameData.GameOver = true;
        }
        if (gameData.y >= gameData.height || gameData.y < 0) {
            gameData.GameOver = true;
        }
        
        for (int i = 0; i < gameData.numtail; i++) {
            if (i < gameData.tailX.size() && i < gameData.tailY.size()) {
                if (gameData.tailX[i] == gameData.x && gameData.tailY[i] == gameData.y) {
                    gameData.GameOver = true;
                }
            }
        }
        
        
        if (gameData.x == gameData.fruitX && gameData.y == gameData.fruitY) {
            gameData.score += 100;
            gameData.fruitX = rand() % gameData.width;
            gameData.fruitY = rand() % gameData.height;
            
        if (gameData.numtail < gameData.tailX.size()) {
            gameData.tailX[gameData.numtail] = 0;
            gameData.tailY[gameData.numtail] = 0;
            gameData.numtail++;
            }
        }
    }
};

#endif /* Engine_hpp */


