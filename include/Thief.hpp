/* Nikita Kotegov st128906@student.spbu.ru Group B81 Lab_work2 */
#ifndef THIEF_HPP
#define THIEF_HPP

#include "Rogue.hpp"
#include <string>

/**
 * @file Thief.hpp
 * @brief Declaration of the Thief class, a rogue-type character card with the ability to steal cards from the opponent.
 */

/**
 * @class Thief
 * @brief A character card that represents a rogue who can steal cards from the opponent's hand.
 * 
 * Inherits from Rogue. When summoned, the Thief attempts to randomly steal a non-Thief card
 * from the opponent's hand and add it to the player's hand.
 */
class Thief : public Rogue {
public:
    /**
     * @brief Constructs a Thief character card.
     * 
     * @param name The name of the card.
     * @param cost The cost to play this card.
     * @param attack The attack value of the Thief.
     * @param health The health value of the Thief.
     */
    Thief(const std::string& name, int cost, int attack, int health);

    /**
     * @brief Virtual destructor.
     */
    ~Thief() override = default;

    /**
     * @brief Gets the card name.
     * @return Name as a string.
     */
    std::string getName() const override;

    /**
     * @brief Gets the cost of the card.
     * @return Integer cost.
     */
    int getCost() const override;

    /**
     * @brief Gets the attack value of the Thief.
     * @return Integer attack.
     */
    int getAttack() const override;

    /**
     * @brief Gets the health value of the Thief.
     * @return Integer health.
     */
    int getHealth() const override;

    /**
     * @brief Summons the Thief to the battlefield and attempts to steal a card.
     * 
     * If the opponent has any non-Thief cards in hand, one is randomly selected and transferred to the Thief’s controller.
     * 
     * @param gm Reference to the GameManager handling game state.
     */
    void use(GameManager& gm) override;
};

#endif // THIEF_HPP

