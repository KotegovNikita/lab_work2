/* Nikita Kotegov st128906@student.spbu.ru Group B81 Lab_work2 */
#ifndef KNIGHT_HPP
#define KNIGHT_HPP

#include "Warrior.hpp"
#include <string>
#include "GameManager.hpp"

/**
 * @file Knight.hpp
 * @brief Declaration of the Knight class, a Warrior-type character card.
 */

/**
 * @class Knight
 * @brief A Warrior card that represents a durable frontline unit.
 * 
 * Inherits from Warrior. The Knight is typically a basic melee character with balanced stats.
 */
class Knight : public Warrior {
public:
    /**
     * @brief Constructs a Knight card.
     * 
     * @param name The name of the card.
     * @param cost The resource cost to play the card.
     * @param attack The attack value of the Knight.
     * @param health The health value of the Knight.
     */
    Knight(const std::string& name, int cost, int attack, int health);

    /**
     * @brief Virtual destructor.
     */
    ~Knight() override = default;

    /**
     * @brief Gets the name of the card.
     * @return Card name as a string.
     */
    std::string getName() const override;

    /**
     * @brief Gets the cost to play this card.
     * @return Integer cost value.
     */
    int getCost() const override;

    /**
     * @brief Gets the attack value of the Knight.
     * @return Integer attack value.
     */
    int getAttack() const override;

    /**
     * @brief Gets the health value of the Knight.
     * @return Integer health value.
     */
    int getHealth() const override;

    /**
     * @brief Applies the effect of the Knight card (summoning a character to the battlefield).
     * 
     * @param gm Reference to the GameManager controlling the game state.
     */
    void use(GameManager& gm) override;
};

#endif // KNIGHT_HPP

