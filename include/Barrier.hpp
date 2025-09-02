/* Nikita Kotegov st128906@student.spbu.ru Group B81 Lab_work2 */
#ifndef BARRIER_HPP
#define BARRIER_HPP

#include "SupportCard.hpp"
#include <string>

/**
 * @file Barrier.hpp
 * @brief Declaration of the Barrier class, a support card that applies a shield effect.
 */

/**
 * @class Barrier
 * @brief A support-type card that grants a shield (defensive buff) to an allied character.
 * 
 * Inherits from SupportCard. When played, this card typically adds protection
 * to a unit, though the specific logic is implemented in the overridden use() method.
 */
class Barrier : public SupportCard {
public:
    /**
     * @brief Constructs a Barrier card.
     * 
     * @param name The name of the card.
     * @param cost The cost to play the card.
     * @param shieldPower The strength of the shield applied.
     */
    Barrier(const std::string& name, int cost, int shieldPower);

    /**
     * @brief Virtual destructor.
     */
    ~Barrier() override = default;

    /**
     * @brief Applies the shield effect to an allied character.
     * 
     * Specific implementation is defined in Barrier.cpp. It may involve
     * selecting an ally and increasing their defense or reducing incoming damage.
     * 
     * @param gm Reference to the GameManager managing the current game state.
     */
    void use(GameManager& gm) override;
};

#endif // BARRIER_HPP

