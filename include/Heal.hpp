/* Nikita Kotegov st128906@student.spbu.ru Group B81 Lab_work2 */
#ifndef HEAL_HPP
#define HEAL_HPP

#include "SupportCard.hpp"
#include <string>

/**
 * @file Heal.hpp
 * @brief Declaration of the Heal class, a support card that restores health to allied characters.
 */

/**
 * @class Heal
 * @brief A support card that heals damaged characters on the battlefield.
 * 
 * Inherits from SupportCard. When played, this card applies healing logic defined in the `.cpp` file.
 */
class Heal : public SupportCard {
public:
    /**
     * @brief Constructs a Heal support card.
     * 
     * @param name The name of the card.
     * @param cost The cost to play the card.
     * @param healPower The amount of health restored by the card.
     */
    Heal(const std::string& name, int cost, int healPower);
};

#endif // HEAL_HPP

