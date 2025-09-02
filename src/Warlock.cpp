/* Nikita Kotegov st128906@student.spbu.ru Group B81 Lab_work2 */
/**
 * @file Warlock.cpp
 * @brief Implementation of the Warlock class, a Mage-type character card with potential for advanced effects.
 */

#include "Warlock.hpp"
#include "GameManager.hpp"
#include "Character.hpp"
#include <iostream>

/**
 * @brief Constructs a Warlock character card.
 * 
 * @param name The name of the Warlock.
 * @param cost The resource cost to play this card.
 * @param attack The Warlock's attack value.
 * @param health The Warlock's health value.
 */
Warlock::Warlock(const std::string& name, int cost, int attack, int health)
    : Mage(name, cost, attack, health)
{}

/**
 * @brief Gets the name of the Warlock card.
 * @return The name as a string.
 */
std::string Warlock::getName() const { return m_name; }

/**
 * @brief Gets the cost of the Warlock card.
 * @return Integer cost.
 */
int Warlock::getCost() const { return m_cost; }

/**
 * @brief Gets the attack value of the Warlock.
 * @return Integer attack value.
 */
int Warlock::getAttack() const { return m_attack; }

/**
 * @brief Gets the health value of the Warlock.
 * @return Integer health value.
 */
int Warlock::getHealth() const { return m_health; }

/**
 * @brief Applies the Warlock card’s effect.
 * 
 * Summons a Warlock character onto the battlefield.
 * Additional mechanics like health sacrifice can be implemented later.
 * 
 * @param gm Reference to the GameManager managing the game state.
 */
void Warlock::use(GameManager& gm) {
    std::cout << "[Warlock::use()] Summoning " << m_name << "\n";
    
    Character newChar(m_name, m_attack, m_health, CharacterType::Warlock);
    
    if (gm.isPlayerTurn())
        gm.addPlayerCharacter(newChar);
    else
        gm.addAICharacter(newChar);
}

