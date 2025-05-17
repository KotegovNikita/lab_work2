#include "Berserk.hpp"
#include "Character.hpp"
#include <iostream>

/**
 * @brief Constructs a Berserk card with the given parameters.
 * 
 * @param name The name of the Berserk character.
 * @param cost The cost to play the card.
 * @param attack The attack value of the Berserk.
 * @param health The health value of the Berserk.
 */
Berserk::Berserk(const std::string& name, int cost, int attack, int health) 
	: Warrior(name, cost, attack, health)
{}

/**
 * @brief Gets the name of the Berserk card.
 * 
 * @return Name as a std::string.
 */
std::string Berserk::getName() const {
	return m_name;
}

/**
 * @brief Gets the resource cost to play the Berserk card.
 * 
 * @return Cost as an integer.
 */
int Berserk::getCost() const {
	return m_cost;
}

/**
 * @brief Gets the attack value of the Berserk.
 * 
 * @return Attack value as an integer.
 */
int Berserk::getAttack() const {
	return m_attack;
}

/**
 * @brief Gets the health value of the Berserk.
 * 
 * @return Health value as an integer.
 */
int Berserk::getHealth() const {
	return m_health;
}

/**
 * @brief Executes the Berserk card's effect.
 * 
 * This method creates a new Character instance with the Berserk's stats 
 * and places it on the appropriate field (player or AI), depending on 
 * whose turn it is.
 * 
 * @param gm Reference to the GameManager managing the game state.
 */
void Berserk::use(GameManager& gm) {
	std::cout << "[Berserk::use()] Summoning " << m_name << "\n";

	Character newChar(m_name, m_attack, m_health, CharacterType::Berserk);
	if (gm.isPlayerTurn())
        gm.addPlayerCharacter(newChar);
    else
        gm.addAICharacter(newChar);
}

