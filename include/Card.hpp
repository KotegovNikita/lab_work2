/* Nikita Kotegov st128906@student.spbu.ru Group B81 Lab_work2 */
#ifndef CARD_HPP
#define CARD_HPP

#include <string>

class GameManager;

/**
 * @file Card.hpp
 * @brief Declaration of the abstract base class Card used in the game.
 */

/**
 * @class Card
 * @brief Abstract base class representing any playable card in the game.
 * 
 * All card types—characters, abilities, attacks, supports—inherit from this interface.
 * Each card must implement methods to provide its name, cost, and usage behavior.
 */
class Card {
public:
    /**
     * @brief Virtual destructor.
     * 
     * Allows safe polymorphic deletion of derived classes.
     */
    virtual ~Card() = default;

    /**
     * @brief Gets the name of the card.
     * @return A string representing the card's name.
     */
    virtual std::string getName() const = 0;

    /**
     * @brief Gets the cost to play this card.
     * @return An integer cost value.
     */
    virtual int getCost() const = 0;

    /**
     * @brief Activates the card's effect.
     * 
     * This pure virtual function must be implemented by derived classes
     * to define what happens when the card is played.
     * 
     * @param gm Reference to the GameManager controlling the current game state.
     */
    virtual void use(GameManager& gm) = 0;
};

#endif // CARD_HPP

