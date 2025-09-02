/* Nikita Kotegov st128906@student.spbu.ru Group B81 Lab_work2 */
#ifndef LIGHTNING_STRIKE_HPP
#define LIGHTNING_STRIKE_HPP

#include "AttackCard.hpp"
#include <string>
#include "GameManager.hpp"
#include <iostream>

/**
 * @file Lightning_strike.hpp
 * @brief Declaration of the Lightning_strike class, an attack card that deals damage to a single enemy.
 */

/**
 * @class Lightning_strike
 * @brief An attack card that targets and damages a single enemy character.
 * 
 * Inherits from AttackCard. When used, this card strikes the first available enemy on the battlefield
 * (typically used by AI), and may eliminate it instantly if its health drops to 0.
 */
class Lightning_strike : public AttackCard {
public:
    /**
     * @brief Constructs a Lightning_strike card.
     * 
     * @param name The name of the card.
     * @param cost The cost to play the card.
     * @param damage The amount of damage dealt to the target.
     */
    Lightning_strike(const std::string& name, int cost, int damage);

    /**
     * @brief Applies the Lightning_strike effect.
     * 
     * Deals damage to the first enemy character on the opponent's field.
     * If the target's HP reaches zero, it is removed from the game.
     * 
     * @param gm Reference to the GameManager controlling the match.
     */
    void use(GameManager& gm) override;
};

#endif // LIGHTNING_STRIKE_HPP

