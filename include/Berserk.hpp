#ifndef BERSERK_HPP
#define BERSERK_HPP

#include "Warrior.hpp"
#include "GameManager.hpp"
#include <string>

/**
 * @file Berserk.hpp
 * @brief Declaration of the Berserk class, a powerful Warrior-type character card.
 */

/**
 * @class Berserk
 * @brief A Warrior character card known for aggressive attack behavior.
 * 
 * Inherits from Warrior. May have enhanced effects when summoned or while attacking,
 * depending on the game logic implemented in the `use()` method.
 */
class Berserk : public Warrior {
public:
    /**
     * @brief Constructs a Berserk character card.
     * 
     * @param name The name of the card.
     * @param cost The resource cost to play this card.
     * @param attack The attack power of the Berserk.
     * @param health The health value of the Berserk.
     */
    Berserk(const std::string& name, int cost, int attack, int health);

    /**
     * @brief Virtual destructor.
     */
    ~Berserk() override = default;

    /**
     * @brief Gets the name of the card.
     * @return Name as a string.
     */
    std::string getName() const override;

    /**
     * @brief Gets the cost of the card.
     * @return Integer cost value.
     */
    int getCost() const override;

    /**
     * @brief Gets the attack value.
     * @return Integer attack value.
     */
    int getAttack() const override;

    /**
     * @brief Gets the health value.
     * @return Integer health value.
     */
    int getHealth() const override;

    /**
     * @brief Activates the card’s effect (summons the Berserk to the field).
     * 
     * The Berserk may later receive special bonuses such as rage or retaliation,
     * depending on game mechanics.
     * 
     * @param gm Reference to the GameManager managing the game.
     */
    void use(GameManager& gm) override;
};

#endif // BERSERK_HPP

