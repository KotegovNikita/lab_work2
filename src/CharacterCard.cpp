/* Nikita Kotegov st128906@student.spbu.ru Group B81 Lab_work2 */
#include "CharacterCard.hpp"
#include <iostream>

/**
 * @brief Constructs a CharacterCard with the given stats.
 * 
 * @param name The name of the character card.
 * @param cost The cost to play the card.
 * @param attack The attack value of the character.
 * @param health The health value of the character.
 */
CharacterCard::CharacterCard(const std::string& name, int cost, int attack, int health) {
	m_name = name;
	m_cost = cost;
	m_attack = attack;
	m_health = health;
}

/**
 * @brief Retrieves the name of the character card.
 * 
 * @return Name as a std::string.
 */
std::string CharacterCard::getName() const {
	return m_name;
}

/**
 * @brief Retrieves the cost to play the character card.
 * 
 * @return Cost as an integer.
 */
int CharacterCard::getCost() const {
	return m_cost;
}

/**
 * @brief Uses the character card to perform an action in the game.
 * 
 * This method is a placeholder. In the final version, it should summon
 * a character onto the battlefield via the GameManager.
 * 
 * @param gm Reference to the GameManager handling the game state.
 */
void CharacterCard::use(GameManager& gm) {
	std::cout << "Using CharacterCard" << std::endl;

	// TODO: Implement character summoning logic through GameManager.
}

