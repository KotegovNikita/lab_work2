/* Nikita Kotegov st128906@student.spbu.ru Group B81 Lab_work2 */
/**
 * @file main.cpp
 * @brief Entry point for the turn-based card game.
 *
 * This file launches the game loop, manages turn execution,
 * and terminates the game after a fixed number of turns or
 * when one of the game-ending conditions is met.
 */

#include <iostream>
#include "GameManager.hpp"

/**
 * @brief Main function that runs the card game.
 *
 * Initializes the GameManager, starts the game,
 * then runs up to 20 turns or until the game ends naturally.
 *
 * @return Exit status code (0 for success).
 */
int main() {
    GameManager game;
    game.startGame();

    int turnCount = 0;

    // Game loop: runs until game over or 20 turns max
    while (!game.isGameOver() && turnCount < 20) {
        game.runTurn();
        turnCount++;
    }

    std::cout << "Game over!\n";
    return 0;
}

