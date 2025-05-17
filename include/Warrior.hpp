#ifndef WARRIOR_HPP
#define WARRIOR_HPP

#include "CharacterCard.hpp"
#include <string>

/**
 * @file Warrior.hpp
 * @brief Declaration of the Warrior class, a base class for melee-focused character cards.
 */

/**
 * @class Warrior
 * @brief Represents a strong melee-based character card.
 * 
 * Inherits from CharacterCard. The Warrior class serves as a base for physical fighters like Knight or Berserk,
 * and can be extended with special traits such as rage, defense, or armor.
 */
class Warrior : public CharacterCard {
public:
    /**
     * @brief Constructs a Warrior character card.
     * 
     * @param name Name of the warrior.
     * @param cost Cost to play the card.
     * @param attack Attack value of the warrior.
     * @param health Health value of the warrior.
     */
    Warrior(const std::string& name, int cost, int attack, int health);

    /**
     * @brief Virtual destructor.
     */
    virtual ~Warrior() = default;
};

#endif // WARRIOR_HPP

