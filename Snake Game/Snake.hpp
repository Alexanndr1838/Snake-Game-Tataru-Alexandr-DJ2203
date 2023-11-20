/**
 * @file Snake.hpp
 * @brief Заголовочный файл для класса Snake
 * 
 *@project Snake Game
 * @author Александр Татару
 * @year 04.10.2023.
 */
#ifndef Snake_hpp
#define Snake_hpp

#include "GameData.hpp"
#include <stdio.h>
#include <iostream> 

/**
 * @class Snake
 * @brief Класс, представляющий собой змейку в игре.
 */

class Snake {
public:
   
    GameData& gameData;
    
 /**
  * @brief Конструктор класса Snake.
  *
  * @param gd Ссылка на объект GameData.
  */
    
     Snake(GameData& gd) : gameData(gd) {}

  /**
   * @brief Оператор сравнения для класса Snake.
   *
   * @param other Другой объект класса Snake.
   * @return true, если змейки совпадают, иначе false.
   */
    
     bool operator==(const Snake &other) const {
         return (gameData.GameOver == other.gameData.GameOver);
     }

  /**
   * @brief Обрабатывает пользовательский ввод и устанавливает соответствующее направление движения змейки.
   *
   * @param gameData Ссылка на объект GameData.
  */
    
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
