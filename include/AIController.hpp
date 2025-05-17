#ifndef AI_CONTROLLER_HPP
#define AI_CONTROLLER_HPP

#include "GameManager.hpp"

/**
 * @file AIController.hpp
 * @brief Declaration of the AIController class responsible for controlling AI behavior.
 */

/**
 * @class AIController
 * @brief Handles AI decisions during its turn in the game.
 * 
 * This class encapsulates logic for choosing which cards to play and which characters to attack.
 * It uses the GameManager interface to interact with the game state.
 */
class AIController {
public:
    /**
     * @brief Default constructor.
     */
    AIController() = default;

    /**
     * @brief Default destructor.
     */
    ~AIController() = default;

    /**
     * @brief Executes the AI's turn logic.
     * 
     * This function uses the provided GameManager reference to simulate
     * an AI move: selecting a card, playing it, and possibly attacking.
     * 
     * @param game Reference to the GameManager that controls the game state.
     */
    void makeMove(GameManager& game);
};

#endif // AI_CONTROLLER_HPP

