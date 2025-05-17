#ifndef WARLOCK_HPP
#define WARLOCK_HPP

#include "Mage.hpp"
#include <string>

/**
 * @file Warlock.hpp
 * @brief Declaration of the Warlock class, a magic-based character card with offensive potential.
 */

/**
 * @class Warlock
 * @brief A Mage-type character card with dark or aggressive traits.
 * 
 * Inherits from Mage. Warlock is typically a summonable character with moderate attack and health,
 * and may have special effects like health sacrifice or curses (extendable in `use()`).
 */
class Warlock : public Mage {
public:
    /**
     * @brief Constructs a Warlock character card.
     * 
     * @param name Name of the card.
     * @param cost Resource cost to play the card.
     * @param attack Attack value of the Warlock.
     * @param health Health value of the Warlock.
     */
    Warlock(const std::string& name, int cost, int attack, int health);

    /**
     * @brief Virtual destructor.
     */
    ~Warlock() override = default;

    /**
     * @brief Gets the name of the card.
     * @return String name.
     */
    std::string getName() const override;

    /**
     * @brief Gets the cost to play the card.
     * @return Integer cost value.
     */
    int getCost() const override;

    /**
     * @brief Gets the Warlock’s attack value.
     * @return Integer attack value.
     */
    int getAttack() const override;

    /**
     * @brief Gets the Warlock’s health value.
     * @return Integer health value.
     */
    int getHealth() const override;

    /**
     * @brief Applies the effect of the Warlock card by summoning it to the field.
     * 
     * Additional effects (e.g. sacrificing health for power) can be implemented in the `.cpp` file.
     * 
     * @param gm Reference to the GameManager controlling the game state.
     */
    void use(GameManager& gm) override;
};

#endif // WARLOCK_HPP

