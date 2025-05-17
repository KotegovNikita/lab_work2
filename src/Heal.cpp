/**
 * @file Heal.cpp
 * @brief Implementation of the Heal card class.
 *
 * The Heal card is a type of SupportCard that restores health to an allied character.
 */

#include "Heal.hpp"

/**
 * @brief Constructs a Heal support card.
 * 
 * @param name The name of the card.
 * @param cost The mana or energy cost to play the card.
 * @param healPower The amount of health restored by this card.
 */
Heal::Heal(const std::string& name, int cost, int healPower)
    : SupportCard(name, cost, healPower)
{
    // Additional initialization logic if needed
}

