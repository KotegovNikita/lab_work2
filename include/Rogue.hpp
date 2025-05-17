#ifndef ROGUE_HPP
#define ROGUE_HPP

#include "CharacterCard.hpp"
#include "GameManager.hpp"
#include <string>

/**
 * @file Rogue.hpp
 * @brief Declaration of the Rogue class, a character card representing agile stealth units.
 */

/**
 * @class Rogue
 * @brief A character card with moderate stats, often extended by subclasses like Thief or Assassin.
 * 
 * Inherits from CharacterCard. Rogues are typically fast, tactical units that may be used
 * as a base for more complex subclasses with unique abilities (e.g., stealing, critical hits).
 */
class Rogue : public CharacterCard {
public:
    /**
     * @brief Constructs a Rogue card.
     * 
     * @param name Name of the rogue.
     * @param cost Resource cost to play the card.
     * @param attack Attack value of the rogue.
     * @param health Health value of the rogue.
     */
    Rogue(const std::string& name, int cost, int attack, int health);

    /**
     * @brief Virtual destructor.
     */
    ~Rogue() override = default;

    /**
     * @brief Gets the name of the card.
     * @return Card name as a string.
     */
    std::string getName() const override;

    /**
     * @brief Gets the cost of the card.
     * @return Integer cost value.
     */
    int getCost() const override;

    /**
     * @brief Gets the attack value of the rogue.
     * @return Integer attack.
     */
    int getAttack() const override;

    /**
     * @brief Gets the health value of the rogue.
     * @return Integer health.
     */
    int getHealth() const override;

    /**
     * @brief Activates the Rogue’s effect by summoning it to the battlefield.
     * 
     * @param gm Reference to the GameManager handling the game state.
     */
    void use(GameManager& gm) override;
};

#endif // ROGUE_HPP

