//
//  main.cpp
//  Snake Game
//
//  Created by Саша Татару on 18.09.2023.
//

#include <iostream>
#include "GameData.hpp"
#include <cstdlib>

using namespace std;

GameData gameData; // Создайте экземпляр структуры GameData или обьект как в С#

void Setup() {
    gameData.GameOver = false;
    gameData.dir = gameData.Stop;
    gameData.x = gameData.width / 2;
    gameData.y = gameData.height / 2;
    gameData.fruitX = rand() % gameData.width;
    gameData.fruitY = rand() % gameData.height;
    gameData.score = 0;
}

void Draw() {
    system("clear");
    for (int i = 0; i < gameData.width + 2; i++)
        cout << "$";
    cout << endl;

    for (int i = 0; i < gameData.height; i++) {

        for (int j = 0; j < gameData.width; j++) {
            if (j == 0)
                cout << "$";

            cout << " ";

            if (j == gameData.width - 1)
                cout << "$";
        }
        cout << endl;
    }

    for (int i = 0; i < gameData.width + 2; i++)
        cout << "$";
    cout << endl;
}

void Input() {
   
}

void Logic() {
   
}

int main() {
    Setup();
    while (!gameData.GameOver) {
        Draw();
        Input();
        Logic();
    }
    return 0;
}
