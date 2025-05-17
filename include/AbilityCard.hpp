#ifndef ABILITY_CARD_HPP
#define ABILITY_CARD_HPP

#include <string>
#include "Card.hpp"

/**
 * @file AbilityCard.hpp
 * @brief Declaration of the AbilityCard class, a base class for spell-like cards that apply effects.
 */

/**
 * @class AbilityCard
 * @brief Represents a card that applies an effect (e.g., damage, healing, buff).
 * 
 * This is an abstract representation of any non-character card that directly influences the battlefield
 * through a one-time effect.
 * 
 * Inherits from Card.
 */
class AbilityCard : public Card {
private:
    std::string m_name;        ///< Name of the card
    int m_cost;                ///< Cost to play the card
    int m_effectPower;         ///< Magnitude of the effect (e.g., damage dealt, HP restored)

public:
    /**
     * @brief Constructs an AbilityCard with given parameters.
     * @param name The name of the ability card.
     * @param cost The resource cost to use this card.
     * @param effectPower The effect magnitude (e.g., damage or healing amount).
     */
    AbilityCard(const std::string& name, int cost, int effectPower);

    /**
     * @brief Virtual destructor.
     */
    ~AbilityCard() override = default;

    /**
     * @brief Returns the name of the card.
     * @return A string representing the card name.
     */
    std::string getName() const override;

    /**
     * @brief Returns the resource cost of the card.
     * @return Integer cost value.
     */
    int getCost() const override;

    /**
     * @brief Applies the card's effect (to be overridden by derived classes).
     * 
     * This base version should normally not be called directly.
     */
    void use(); // May be overridden by specific ability types
};

#endif // ABILITY_CARD_HPP

