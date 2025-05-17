/**
 * @file Mage.cpp
 * @brief Implementation of the Mage character card class.
 */

#include "Mage.hpp"

/**
 * @brief Constructs a Mage character card.
 * 
 * @param name The name of the mage card.
 * @param cost The cost to play this card.
 * @param attack The attack strength of the mage.
 * @param health The health points of the mage.
 */
Mage::Mage(const std::string& name, int cost, int attack, int health) 
    : CharacterCard(name, cost, attack, health)
{}

