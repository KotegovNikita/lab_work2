#ifndef ATTACK_CARD_HPP
#define ATTACK_CARD_HPP

#include "Card.hpp"
#include <string>

/**
 * @file AttackCard.hpp
 * @brief Declaration of the AttackCard class, a base class for all offensive spell cards.
 */

/**
 * @class AttackCard
 * @brief Represents a card that deals direct damage to enemy characters.
 * 
 * This abstract class is intended to be inherited by specific attack card types
 * (e.g., LightningStrike, FlameWave). It defines the basic interface and data
 * for damaging effects.
 * 
 * Inherits from the base Card class.
 */
class AttackCard : public Card {
protected:
    std::string m_name; ///< Name of the attack card
    int m_cost;         ///< Cost to play the card
    int m_damage;       ///< Amount of damage dealt

public:
    /**
     * @brief Constructs an AttackCard with specified parameters.
     * 
     * @param name The name of the card.
     * @param cost The energy or mana cost to play the card.
     * @param damage The amount of damage this card deals.
     */
    AttackCard(const std::string& name, int cost, int damage);

    /**
     * @brief Virtual destructor.
     */
    virtual ~AttackCard() = default;

    /**
     * @brief Retrieves the card name.
     * @return The card name as a string.
     */
    std::string getName() const override;

    /**
     * @brief Retrieves the cost to play this card.
     * @return Integer cost value.
     */
    int getCost() const override;

    /**
     * @brief Applies the effect of the attack card.
     * 
     * Must be overridden by derived classes to define how damage is applied in the game.
     * 
     * @param gm Reference to the GameManager instance managing the current game state.
     */
    void use(GameManager& gm) override;
};

#endif // ATTACK_CARD_HPP

