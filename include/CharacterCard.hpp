/* Nikita Kotegov st128906@student.spbu.ru Group B81 Lab_work2 */
#ifndef CHARACTER_CARD_HPP
#define CHARACTER_CARD_HPP

#include "Card.hpp"
#include <string>

/**
 * @file CharacterCard.hpp
 * @brief Declaration of the CharacterCard abstract class, which serves as the base for all character-type cards.
 */

/**
 * @class CharacterCard
 * @brief Abstract base class for all summonable character cards (e.g., Knight, Mage, Rogue).
 * 
 * This class extends the Card interface by adding attributes such as attack and health,
 * and mandates implementation of methods that define a character’s combat stats and summoning logic.
 */
class CharacterCard : public Card {
protected:
    std::string m_name;   ///< Name of the card
    int m_cost;           ///< Cost to play the card
    int m_attack;         ///< Attack power of the character
    int m_health;         ///< Health points of the character

public:
    /**
     * @brief Constructs a character card with the given properties.
     * 
     * @param name Name of the character.
     * @param cost Resource cost to play this card.
     * @param attack Attack value of the summoned character.
     * @param health Health value of the summoned character.
     */
    CharacterCard(const std::string& name, int cost, int attack, int health);

    /**
     * @brief Virtual destructor.
     */
    ~CharacterCard() override = default;

    /**
     * @brief Returns the attack value of the character.
     * @return Integer attack value.
     */
    virtual int getAttack() const = 0;

    /**
     * @brief Returns the health value of the character.
     * @return Integer health value.
     */
    virtual int getHealth() const = 0;

    /**
     * @brief Defines the effect of using the card (typically summoning a character to the field).
     * 
     * Must be implemented by derived classes.
     * 
     * @param gm Reference to the GameManager controlling the game.
     */
    virtual void use(GameManager& gm) = 0;

    /**
     * @brief Returns the name of the card.
     * @return String name.
     */
    std::string getName() const override;

    /**
     * @brief Returns the cost to play this card.
     * @return Integer cost.
     */
    int getCost() const override;
};

#endif // CHARACTER_CARD_HPP

