/* Nikita Kotegov st128906@student.spbu.ru Group B81 Lab_work2 */
#ifndef ELEMENTALIST_HPP
#define ELEMENTALIST_HPP

#include "Mage.hpp"
#include <string>

/**
 * @file Elementalist.hpp
 * @brief Declaration of the Elementalist class, a mage-type character card with elemental power.
 */

/**
 * @class Elementalist
 * @brief A Mage subclass that represents a character with elemental abilities.
 * 
 * Inherits from Mage. The Elementalist is a character card that can be summoned
 * to the battlefield and may include special elemental effects (implemented in the `.cpp` file).
 */
class Elementalist : public Mage {
public:
    /**
     * @brief Constructs an Elementalist card.
     * 
     * @param name Name of the card.
     * @param cost Cost to play the card.
     * @param attack Attack value of the Elementalist.
     * @param health Health value of the Elementalist.
     */
    Elementalist(const std::string& name, int cost, int attack, int health);

    /**
     * @brief Virtual destructor.
     */
    ~Elementalist() override = default;

    /**
     * @brief Gets the card name.
     * @return String name.
     */
    std::string getName() const override;

    /**
     * @brief Gets the card cost.
     * @return Integer cost.
     */
    int getCost() const override;

    /**
     * @brief Gets the attack value.
     * @return Integer attack.
     */
    int getAttack() const override;

    /**
     * @brief Gets the health value.
     * @return Integer health.
     */
    int getHealth() const override;

    /**
     * @brief Applies the Elementalist card effect.
     * 
     * Typically summons the Elementalist to the field. Additional logic may be added in `.cpp` to implement elemental effects.
     * 
     * @param gm Reference to the GameManager.
     */
    void use(GameManager& gm) override;
};

#endif // ELEMENTALIST_HPP

