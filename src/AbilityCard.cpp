#include <string>
#include "AbilityCard.hpp"
#include <iostream>

/**
 * @brief Constructs an AbilityCard with a given name, cost, and effect power.
 * 
 * @param name The name of the ability.
 * @param cost The mana or energy cost to use the ability.
 * @param effectPower The numerical effect of the ability (e.g., damage, buff amount).
 */
AbilityCard::AbilityCard(const std::string& name, int cost, int effectPower) {
	m_name = name;
	m_cost = cost;
	m_effectPower = effectPower;
}

/**
 * @brief Gets the name of the ability.
 * 
 * @return The name as a std::string.
 */
std::string AbilityCard::getName() const {
	return m_name;
}

/**
 * @brief Gets the cost required to use the ability.
 * 
 * @return The cost as an integer.
 */
int AbilityCard::getCost() const {
	return m_cost;
}

/**
 * @brief Applies the effect of the ability.
 * 
 * This function simulates using the ability (e.g., damage, buffs). 
 * Actual logic should be implemented later.
 */
void AbilityCard::use() {
	std::cout << "Using AbilityCard " << m_name 
	          << ", effectPower = " << m_effectPower << std::endl;
}

