//
//  Snake.hpp
//  Snake Game
//
//  Created by Саша Татару on 04.10.2023.
//

#ifndef Snake_hpp
#define Snake_hpp

#include "GameData.hpp"
#include <stdio.h>
#include <iostream> 

class Snake {
public:
   
    GameData& gameData;

     Snake(GameData& gd) : gameData(gd) {}

     bool operator==(const Snake &other) const {
         return (gameData.GameOver == other.gameData.GameOver);
     }

    
    void Input(GameData &gameData) { 
        char input;
        std::cin >> input;

        switch (input) {
            case 'a':
                gameData.dir = GameData::Left;
                break;
            case 'd':
                gameData.dir = GameData::Right;
                break;
            case 'w':
                gameData.dir = GameData::Up;
                break;
            case 's':
                gameData.dir = GameData::Down;
                break;
            case 'x':
                gameData.GameOver = true;
                break;
        }
    }
};

#endif /* Snake_hpp */
