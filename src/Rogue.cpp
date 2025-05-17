/**
 * @file Rogue.cpp
 * @brief Implementation of the Rogue class, a type of character card.
 */

#include "Rogue.hpp"
#include "Character.hpp"
#include <iostream>

/**
 * @brief Constructs a Rogue character card.
 * 
 * @param name The name of the rogue.
 * @param cost The energy/mana cost to play this card.
 * @param attack The attack value of the rogue.
 * @param health The health value of the rogue.
 */
Rogue::Rogue(const std::string& name, int cost, int attack, int health)
    : CharacterCard(name, cost, attack, health)
{}

/**
 * @brief Retrieves the name of the Rogue card.
 * @return Name as a string.
 */
std::string Rogue::getName() const {
    return m_name;
}

/**
 * @brief Retrieves the cost to play the Rogue card.
 * @return Integer cost.
 */
int Rogue::getCost() const {
    return m_cost;
}

/**
 * @brief Retrieves the attack value of the Rogue card.
 * @return Integer attack value.
 */
int Rogue::getAttack() const {
    return m_attack;
}

/**
 * @brief Retrieves the health value of the Rogue card.
 * @return Integer health value.
 */
int Rogue::getHealth() const {
    return m_health;
}

/**
 * @brief Applies the effect of the Rogue card.
 * 
 * Summons a character to the player's battlefield when played.
 * 
 * @param gm Reference to the GameManager instance.
 */
void Rogue::use(GameManager& gm) {
    std::cout << "[Rogue::use()] Summoning " << m_name << "\n";
    Character character(m_name, m_attack, m_health);
    gm.addPlayerCharacter(character);
}

