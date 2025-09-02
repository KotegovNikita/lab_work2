/* Nikita Kotegov st128906@student.spbu.ru Group B81 Lab_work2 */
#include "Elementalist.hpp"
#include "GameManager.hpp"
#include "Character.hpp"
#include <iostream>

/**
 * @brief Constructs an Elementalist card with specified attributes.
 * 
 * @param name The name of the Elementalist.
 * @param cost The cost required to play the card.
 * @param attack The attack value of the Elementalist.
 * @param health The health value of the Elementalist.
 */
Elementalist::Elementalist(const std::string& name, int cost, int attack, int health) 
    : Mage(name, cost, attack, health)
{}

/**
 * @brief Retrieves the name of the Elementalist card.
 * 
 * @return Name as a std::string.
 */
std::string Elementalist::getName() const {
    return m_name;
}

/**
 * @brief Retrieves the cost to play the Elementalist card.
 * 
 * @return Cost as an integer.
 */
int Elementalist::getCost() const {
    return m_cost;
}

/**
 * @brief Retrieves the attack value of the Elementalist.
 * 
 * @return Attack value as an integer.
 */
int Elementalist::getAttack() const {
    return m_attack;
}

/**
 * @brief Retrieves the health value of the Elementalist.
 * 
 * @return Health value as an integer.
 */
int Elementalist::getHealth() const {
    return m_health;
}

/**
 * @brief Uses the Elementalist card by summoning the character to the battlefield.
 * 
 * Creates a Character instance with the card's stats and adds it to the appropriate field
 * (player or AI), based on the current turn tracked by the GameManager.
 * 
 * @param gm Reference to the GameManager that handles game state and turns.
 */
void Elementalist::use(GameManager& gm) {
    std::cout << "[Elementalist::use()] Summoning " << m_name << "\n";
    
    Character newChar(m_name, m_attack, m_health, CharacterType::Elementalist);
    
    if (gm.isPlayerTurn())
        gm.addPlayerCharacter(newChar);
    else
        gm.addAICharacter(newChar);

    // Optional: if you want to implement ownership logic, 
    // you'll need a way to identify the card's owner.
}

