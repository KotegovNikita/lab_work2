/* Nikita Kotegov st128906@student.spbu.ru Group B81 Lab_work2 */
#include "AttackCard.hpp"
#include <iostream>

/**
 * @brief Constructs an AttackCard with a name, cost, and damage value.
 * 
 * @param name The name of the attack card.
 * @param cost The resource cost required to play the card.
 * @param damage The amount of damage the card deals when used.
 */
AttackCard::AttackCard(const std::string& name, int cost, int damage) {
	m_name = name;
	m_cost = cost;
	m_damage = damage;
}

/**
 * @brief Retrieves the name of the attack card.
 * 
 * @return The name as a std::string.
 */
std::string AttackCard::getName() const {
	return m_name;
}

/**
 * @brief Retrieves the cost to play the card.
 * 
 * @return The cost as an integer.
 */
int AttackCard::getCost() const {
	return m_cost;
}

/**
 * @brief Applies the attack card effect.
 * 
 * This function logs the attack action and shows the amount of damage dealt.
 * Actual game mechanics for applying damage should be implemented here.
 * 
 * @param gm Reference to the GameManager for accessing the game state.
 */
void AttackCard::use(GameManager& gm) {
	std::cout << "[AttackCard::use()] " << m_name << " deals " 
	          << m_damage << " damage.\n";
}

