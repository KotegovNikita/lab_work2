/**
 * @file Lightning_strike.cpp
 * @brief Implementation of the Lightning_strike class – an offensive spell card.
 */

#include "Lightning_strike.hpp"

/**
 * @brief Constructs a Lightning_strike attack card.
 * 
 * @param name The name of the card.
 * @param cost The energy/mana cost to play the card.
 * @param damage The amount of damage the card deals when used.
 */
Lightning_strike::Lightning_strike(const std::string& name, int cost, int damage)
    : AttackCard(name, cost, damage)
{
    // No additional initialization needed
}

/**
 * @brief Applies the effect of the Lightning_strike card.
 * 
 * Deals direct damage to the first enemy character on the opponent’s battlefield (usually the player).
 * If the target's health drops to zero or below, it is removed from the field.
 * 
 * @param gm Reference to the GameManager instance managing the match state.
 */
void Lightning_strike::use(GameManager& gm) {
    std::cout << "[Lightning_strike::use()] " << m_name << " deals " << m_damage << " damage.\n";

    // If played by the AI, target the player's characters
    auto& enemies = gm.getPlayerField(); 
    
    if (enemies.empty()) {
        std::cout << "No enemies to strike.\n";
        return;
    }

    std::string targetName = enemies[0].getName();

    // Strike the first character (could be changed to random)
    enemies[0].onAttacked(m_damage);
    if (enemies[0].isDead()) {
        std::cout << targetName << " was killed by lightning!\n";
        enemies.erase(enemies.begin());
    }
}

