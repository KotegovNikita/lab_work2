#ifndef ASSASSIN_HPP
#define ASSASSIN_HPP

#include "Rogue.hpp"
#include <string>

/**
 * @file Assassin.hpp
 * @brief Declaration of the Assassin class, a specialized Rogue card with potentially unique abilities.
 */

/**
 * @class Assassin
 * @brief Represents a Rogue-type character card with distinct properties or effects.
 * 
 * Inherits from the Rogue class. Can be extended with special behaviors in the overridden `use()` method.
 */
class Assassin : public Rogue {
public:
    /**
     * @brief Constructs an Assassin card.
     * 
     * @param name Name of the assassin.
     * @param cost Resource cost to play the card.
     * @param attack Attack value of the assassin.
     * @param health Health value of the assassin.
     */
    Assassin(const std::string& name, int cost, int attack, int health);

    /**
     * @brief Virtual destructor.
     */
    ~Assassin() override = default;

    /**
     * @brief Returns the name of the card.
     * @return Card name.
     */
    std::string getName() const override;

    /**
     * @brief Returns the cost to play this card.
     * @return Integer cost value.
     */
    int getCost() const override;

    /**
     * @brief Returns the attack value.
     * @return Integer attack value.
     */
    int getAttack() const override;

    /**
     * @brief Returns the health value.
     * @return Integer health value.
     */
    int getHealth() const override;

    /**
     * @brief Applies the effect of the Assassin card.
     * 
     * Typically summons a character to the field. Override may include special effects like instant damage or stealth.
     * 
     * @param gm Reference to the GameManager controlling the match.
     */
    void use(GameManager& gm) override;
};

#endif // ASSASSIN_HPP

