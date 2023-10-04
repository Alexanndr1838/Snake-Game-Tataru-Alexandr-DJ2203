//
//  main.cpp
//  Snake Game
//
//  Created by Саша Татару on 18.09.2023.
//

#include <iostream>
#include <ncurses.h>
#include "GameData.hpp"
#include <cstdlib>
#include <vector>

using namespace std;

GameData gameData; // Создайте экземпляр структуры GameData или обьект как в С#

void Setup() {
    gameData.GameOver = false;
    gameData.dir = gameData.Stop;
    gameData.x = gameData.width / 2 - 1;
    gameData.y = gameData.height / 2 - 1;
    gameData.fruitX = rand() % gameData.width;
    gameData.fruitY = rand() % gameData.height;
    gameData.score = 0;
}
//поле
void Draw() {
    system("clear");
    for (int i = 0; i < gameData.width + 2; i++)
        cout << "$";
    cout << endl;

    for (int i = 0; i < gameData.height ; i++) {
        for (int j = 0; j < gameData.width ; j++) {
            if (j == 0  || j == gameData.width + 1)
                cout << "$";
            if (i == gameData.y && j == gameData.x)
                           cout << "O";
                       else if (i == gameData.fruitY && j == gameData.fruitX)
                           cout << "&";
            cout << " ";

            if (j == gameData.width - 1)
                cout << "$";
        }
        cout << endl;
    }

    for (int i = 0; i < gameData.width + 2; i++)
        cout << "$";
    cout << endl;
    cout << "Score:" << gameData.score << endl;
}

void Input() {
    char input;
       cin >> input; // Ожидаем ввод пользователя
       switch (input) {
            case 'a':
                gameData.dir = gameData.Left;
                break;
            case 'd':
                gameData.dir = gameData.Right;
                break;
            case 'w':
                gameData.dir = gameData.Up;
                break;
            case 's':
                gameData.dir = gameData.Down;
                break;
            case 'x':
                gameData.GameOver = true;
                break;
        }
    }

void Logic() {
    switch (gameData.dir) {
            case gameData.Left:
            gameData.x--;
                break;
            case gameData.Right:
            gameData.x++;
                break;
            case gameData.Up:
            gameData.y--;
                break;
            case gameData.Down:
            gameData.y++;
                break;
            default:
                break;
            }

    if (gameData.x >= gameData.width || gameData.x < 0){
        gameData.GameOver = true;
    }
    if (gameData.y >= gameData.height || gameData.y < 0){
            gameData.GameOver = true;
            }
    
    if (gameData.x == gameData.fruitX && gameData.y == gameData.fruitY) {
        gameData.score += 100;
    }
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
