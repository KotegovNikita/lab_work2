#ifndef MAGE_HPP
#define MAGE_HPP

#include "CharacterCard.hpp"
#include <string>

/**
 * @file Mage.hpp
 * @brief Declaration of the Mage class, a base character card for magical units.
 */

/**
 * @class Mage
 * @brief Abstract base class for magic-type characters (e.g., Warlock, Elementalist).
 * 
 * Inherits from CharacterCard. Mage can be used as a foundation for all characters
 * that are spellcasters and may later be extended with unique mechanics.
 */
class Mage : public CharacterCard {
public:
    /**
     * @brief Constructs a Mage card.
     * 
     * @param name Name of the card.
     * @param cost Cost to play the card.
     * @param attack Attack value of the mage.
     * @param health Health value of the mage.
     */
    Mage(const std::string& name, int cost, int attack, int health);

    /**
     * @brief Virtual destructor.
     */
    virtual ~Mage() = default;
};

#endif // MAGE_HPP

