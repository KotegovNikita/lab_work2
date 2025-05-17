/**
 * @file Knight.cpp
 * @brief Implementation of the Knight class, a specific type of Warrior character card.
 */

#include "Knight.hpp"
#include "Character.hpp"
#include <iostream>
#include "GameManager.hpp"

/**
 * @brief Constructs a Knight card with specific attributes.
 * 
 * @param name The name of the card.
 * @param cost The cost to play the card.
 * @param attack The attack value of the character.
 * @param health The health value of the character.
 */
Knight::Knight(const std::string& name, int cost, int attack, int health) 
    : Warrior(name, cost, attack, health)
{}

/**
 * @brief Retrieves the name of the card.
 * @return The card's name.
 */
std::string Knight::getName() const {
    return m_name;
}

/**
 * @brief Retrieves the cost of the card.
 * @return The card's cost.
 */
int Knight::getCost() const {
    return m_cost;
}

/**
 * @brief Retrieves the attack value of the card.
 * @return The card's attack power.
 */
int Knight::getAttack() const {
    return m_attack;
}

/**
 * @brief Retrieves the health value of the card.
 * @return The card's health points.
 */
int Knight::getHealth() const {
    return m_health;
}

/**
 * @brief Applies the effect of the Knight card by summoning a character to the battlefield.
 * 
 * A new Character instance is created and added to the appropriate field depending on whose turn it is.
 * 
 * @param gm Reference to the current GameManager instance.
 */
void Knight::use(GameManager& gm) {
    std::cout << "[Knight::use()] Summoning " << m_name << "\n";
    Character newChar(m_name, m_attack, m_health, CharacterType::Knight);
    if (gm.isPlayerTurn())
        gm.addPlayerCharacter(newChar);
    else
        gm.addAICharacter(newChar);
}

