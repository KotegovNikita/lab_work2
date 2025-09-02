/* Nikita Kotegov st128906@student.spbu.ru Group B81 Lab_work2 */
#include "Assassin.hpp"
#include "GameManager.hpp"
#include "Character.hpp"
#include <iostream>

/**
 * @brief Constructs an Assassin card with specified attributes.
 * 
 * @param name The name of the Assassin.
 * @param cost The resource cost to play the card.
 * @param attack The attack value of the Assassin.
 * @param health The health value of the Assassin.
 */
Assassin::Assassin(const std::string& name, int cost, int attack, int health)
    : Rogue(name, cost, attack, health)
{}

/**
 * @brief Returns the name of the Assassin card.
 * 
 * @return Name as a std::string.
 */
std::string Assassin::getName() const { return m_name; }

/**
 * @brief Returns the cost to play the Assassin card.
 * 
 * @return Cost as an integer.
 */
int Assassin::getCost() const { return m_cost; }

/**
 * @brief Returns the attack value of the Assassin.
 * 
 * @return Attack as an integer.
 */
int Assassin::getAttack() const { return m_attack; }

/**
 * @brief Returns the health value of the Assassin.
 * 
 * @return Health as an integer.
 */
int Assassin::getHealth() const { return m_health; }

/**
 * @brief Executes the Assassin's effect when played.
 * 
 * This function handles the summoning of the Assassin to the field.
 * A new Character instance is created and added to the appropriate side 
 * based on whose turn it is. Unique mechanics such as critical strike 
 * can be added here.
 * 
 * @param gm Reference to the GameManager controlling the game state.
 */
void Assassin::use(GameManager& gm) {
    std::cout << "[Assassin::use()] Summoning " << m_name << "\n";

    Character newChar(m_name, m_attack, m_health, CharacterType::Assassin);
    if (gm.isPlayerTurn())
        gm.addPlayerCharacter(newChar);
    else
        gm.addAICharacter(newChar);
}

