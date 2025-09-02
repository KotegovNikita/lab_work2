/* Nikita Kotegov st128906@student.spbu.ru Group B81 Lab_work2 */
/**
 * @file FlameWave.cpp
 * @brief Implementation of the FlameWave attack card that damages all enemy characters.
 */

#include "FlameWave.hpp"
#include <iostream>

/**
 * @brief Constructs a FlameWave attack card.
 * 
 * @param name The name of the card.
 * @param cost The cost to play the card.
 * @param damage The amount of damage dealt to each enemy character.
 */
FlameWave::FlameWave(const std::string& name, int cost, int damage)
    : AttackCard(name, cost, damage)
{
    // No additional initialization needed
}

/**
 * @brief Applies the FlameWave effect.
 * 
 * Deals area-of-effect (AOE) damage to all enemy characters on the opponent's battlefield.
 * If any enemy's health drops to 0 or below, it is removed from the field.
 * 
 * @param gm Reference to the GameManager managing the match.
 */
void FlameWave::use(GameManager& gm) {
    std::cout << "[FlameWave::use()] " << m_name << " deals " << m_damage << " AOE damage!\n";

    // Выбор цели: если AI играет — бьёт по игроку, иначе по AI
    auto& enemies = gm.isPlayerTurn() ? gm.getAIField() : gm.getPlayerField();

    if (enemies.empty()) {
        std::cout << "No enemies to burn.\n";
        return;
    }

    // Проходим по всем врагам
    for (int i = static_cast<int>(enemies.size()) - 1; i >= 0; --i) {
        auto& enemy = enemies[i];
        enemy.onAttacked(m_damage);

        if (enemy.isDead()) {
            std::cout << enemy.getName() << " was burned to ashes by FlameWave!\n";
            enemies.erase(enemies.begin() + i);
        }
    }
}

