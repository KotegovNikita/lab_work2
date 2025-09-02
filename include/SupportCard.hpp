/* Nikita Kotegov st128906@student.spbu.ru Group B81 Lab_work2 */
#ifndef SUPPORT_CARD_HPP
#define SUPPORT_CARD_HPP

#include "Card.hpp"
#include <string>

/**
 * @file SupportCard.hpp
 * @brief Declaration of the SupportCard class, a base class for healing and buffing cards.
 */

/**
 * @class SupportCard
 * @brief Abstract base class for cards that apply beneficial effects (healing, buffs) to allies.
 * 
 * Inherits from Card. Provides shared fields and methods for all support-type cards.
 * Specific effects must be implemented in derived classes like Heal or Barrier.
 */
class SupportCard : public Card {
protected:
    std::string m_name;  ///< Name of the card
    int m_cost;          ///< Cost to play the card
    int m_power;         ///< Effect strength (e.g., healing amount or shield value)

public:
    /**
     * @brief Constructs a support card.
     * 
     * @param name Name of the card.
     * @param cost Resource cost to play the card.
     * @param power The magnitude of the effect.
     */
    SupportCard(const std::string& name, int cost, int power);

    /**
     * @brief Virtual destructor.
     */
    virtual ~SupportCard() = default;

    /**
     * @brief Returns the name of the support card.
     * @return String name.
     */
    std::string getName() const override;

    /**
     * @brief Returns the cost to play the card.
     * @return Integer cost value.
     */
    int getCost() const override;

    /**
     * @brief Executes the card’s effect (to be overridden in derived classes).
     * 
     * @param gm Reference to the GameManager instance.
     */
    void use(GameManager& gm) override;
};

#endif // SUPPORT_CARD_HPP

