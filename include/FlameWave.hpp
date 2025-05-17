#ifndef FLAMEWAVE_HPP
#define FLAMEWAVE_HPP

#include <iostream>
#include "AttackCard.hpp"
#include "GameManager.hpp"

/**
 * @file FlameWave.hpp
 * @brief Declaration of the FlameWave class, an attack card that deals area damage.
 */

/**
 * @class FlameWave
 * @brief An offensive card that applies area-of-effect damage to enemy units.
 * 
 * Inherits from AttackCard. When used, this card typically deals damage to all
 * characters on the opponent’s field.
 */
class FlameWave : public AttackCard {
public:
    /**
     * @brief Constructs a FlameWave attack card.
     * 
     * @param name The name of the card.
     * @param cost The cost to play the card.
     * @param damage The amount of damage it deals to each enemy.
     */
    FlameWave(const std::string& name, int cost, int damage);

    /**
     * @brief Applies the FlameWave effect.
     * 
     * Damages all enemy characters on the field. The exact implementation is defined in the `.cpp` file.
     * 
     * @param gm Reference to the GameManager managing the game state.
     */
    void use(GameManager& gm) override;
};

#endif // FLAMEWAVE_HPP

