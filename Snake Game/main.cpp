//
//  main.cpp
//  Snake Game
//
//  Created by Саша Татару on 18.09.2023.
//

#include <iostream>
#include <ncurses.h>
#include <time.h>
#include "GameData.hpp"
#include "Engine.hpp"
#include "Map.hpp"
#include "Snake.hpp"
#include <cstdlib>


using namespace std;

GameData gameData; // Создайте экземпляр структуры GameData или обьект как в С#
Map map;
Snake snake(gameData);
Engine engine(gameData);

void Setup() {
      gameData.GameOver = false;
      gameData.dir = gameData.Stop;
      gameData.x = gameData.width / 2 - 1;
      gameData.y = gameData.height / 2 - 1;
      gameData.fruitX = rand() % gameData.width;
      gameData.fruitY = rand() % gameData.height;
      gameData.score = 0;
      gameData.numtail = 0;
      gameData.tailX.resize(100, 0);
      gameData.tailY.resize(100, 0);
   }

int main() {
    Setup();
    while (!gameData.GameOver) {
        map.Draw(gameData);
        snake.Input(gameData);
        engine.Logic(gameData);
    }
    return 0;
}
