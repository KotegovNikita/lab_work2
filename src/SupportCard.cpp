/**
 * @file SupportCard.cpp
 * @brief Implementation of the SupportCard class, a base class for support-type cards.
 */

#include "SupportCard.hpp"
#include <iostream>

/**
 * @brief Constructs a support card with the given name, cost, and power.
 * 
 * @param name The name of the support card.
 * @param cost The resource cost to play the card.
 * @param power The effect power (e.g. healing amount, shield strength, etc.).
 */
SupportCard::SupportCard(const std::string& name, int cost, int power) {
    m_name = name;
    m_cost = cost;
    m_power = power;
}

/**
 * @brief Gets the name of the support card.
 * @return The name as a string.
 */
std::string SupportCard::getName() const {
    return m_name;
}

/**
 * @brief Gets the cost to play this card.
 * @return Integer cost.
 */
int SupportCard::getCost() const {
    return m_cost;
}

/**
 * @brief Base implementation of the use effect for support cards.
 * 
 * This version only prints a message. Derived classes should override this method
 * to implement actual in-game effects like healing or buffs.
 * 
 * @param gm Reference to the GameManager handling the game state.
 */
void SupportCard::use(GameManager& gm) {
    std::cout << "[SupportCard::use()] " << m_name << " applies effect with power " << m_power << ".\n";
}

