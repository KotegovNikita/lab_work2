/**
 * @file Warrior.cpp
 * @brief Implementation of the Warrior class, a specific subclass of CharacterCard.
 */

#include "Warrior.hpp"

/**
 * @brief Constructs a Warrior character card.
 * 
 * @param name The name of the warrior card.
 * @param cost The cost to play this card.
 * @param attack The attack power of the warrior.
 * @param health The health points of the warrior.
 */
Warrior::Warrior(const std::string& name, int cost, int attack, int health)
    : CharacterCard(name, cost, attack, health)
{
    // Additional warrior-specific logic can be added here
}

