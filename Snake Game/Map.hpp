//
//  Map.hpp
//  Snake Game
//
//  Created by Саша Татару on 04.10.2023.
//

#ifndef Map_hpp
#define Map_hpp

#include "GameData.hpp"
#include <stdio.h>
#include <iostream>

class Map {
public:
    void Logic(GameData &gameData) {
        system("clear");

        for (int i = 0; i < gameData.width + 2; i++)
            std::cout << "$";
        std::cout << std::endl;

        for (int i = 0; i < gameData.height; i++) {
            for (int j = 0; j < gameData.width; j++) {
                if (j == 0 || j == gameData.width - 1)
                    std::cout << "$";
                if (i == gameData.y && j == gameData.x)
                    std::cout << "O";
                else if (i == gameData.fruitY && j == gameData.fruitX)
                    std::cout << "&";
                else
                    std::cout << " "; 

                if (j == gameData.width - 1)
                    std::cout << "$";
            }
            std::cout << std::endl;
        }

        for (int i = 0; i < gameData.width + 2; i++)
            std::cout << "$";
        std::cout << std::endl;

        std::cout << "Score: " << gameData.score << std::endl;
    }
};

#endif /* Map_hpp */
