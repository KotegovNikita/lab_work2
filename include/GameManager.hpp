/* Nikita Kotegov st128906@student.spbu.ru Group B81 Lab_work2 */
#ifndef GAME_MANAGER_HPP
#define GAME_MANAGER_HPP

#include <vector>
#include <memory>
#include <string>
#include "Card.hpp"
#include "Character.hpp"
#include "CharacterCard.hpp"
#include "AbilityCard.hpp"

/**
 * @file GameManager.hpp
 * @brief Declaration of the GameManager class, which controls the game loop, turn progression, AI behavior, and victory conditions.
 */

/**
 * @class GameManager
 * @brief Core controller of the game.
 *
 * Responsible for managing the game state, including decks, hands, fields, turn flow, and win conditions.
 * Provides public interfaces for cards to interact with the board and handles logic for both player and AI turns.
 */
class GameManager {
private:
    int m_aiTurnCount = 0;                  ///< Number of turns the AI has taken
    bool m_gameOver = false;                ///< Flag indicating whether the game has ended
    bool m_playerTurn = true;               ///< Flag for tracking whose turn it is

    std::vector<std::unique_ptr<Card>> m_playerDeck; ///< Player's draw deck
    std::vector<std::unique_ptr<Card>> m_aiDeck;     ///< AI's draw deck

    std::vector<std::unique_ptr<Card>> m_playerHand; ///< Cards in player's hand
    std::vector<std::unique_ptr<Card>> m_aiHand;     ///< Cards in AI's hand

    std::vector<Character> m_playerField;  ///< Player's characters on the battlefield
    std::vector<Character> m_aiField;      ///< AI's characters on the battlefield

public:
    /**
     * @brief Constructs a new GameManager instance.
     */
    GameManager();

    /**
     * @brief Destroys the GameManager.
     */
    ~GameManager();

    /**
     * @brief Starts a new game: initializes decks and hands.
     */
    void startGame();

    /**
     * @brief Initializes the player's deck.
     */
    void initializePlayerDeck();

    /**
     * @brief Initializes the AI's deck.
     */
    void initializeAIDeck();

    /**
     * @brief Deals up to @p count cards from @p deck into @p hand, respecting hand composition rules.
     */
    void dealCards(int count, std::vector<std::unique_ptr<Card>>& hand, std::vector<std::unique_ptr<Card>>& deck);

    /**
     * @brief Ensures that a hand contains at least two ability cards.
     */
    void ensureMinimumAbilityCards(std::vector<std::unique_ptr<Card>>& hand, std::vector<std::unique_ptr<Card>>& deck);

    /**
     * @brief Executes a full turn: player move, AI move, optional combat.
     */
    void runTurn();

    /**
     * @brief Returns true if the game has ended.
     */
    bool isGameOver() const;

    /**
     * @brief Checks win/loss/draw conditions and updates internal state.
     */
    void checkGameOver();

    /**
     * @brief Determines the winner and returns a result string.
     */
    std::string determineWinner();

    /**
     * @brief Draws one card for the player, if possible.
     */
    void drawCardForPlayer();

    /**
     * @brief Draws one card for the AI, if possible.
     */
    void drawCardForAI();

    /**
     * @brief Returns true if it is currently the player's turn.
     */
    bool isPlayerTurn() const;

    /**
     * @brief Adds a summoned character to the player's field.
     * @param character Character to add.
     */
    void addPlayerCharacter(const Character& character);

    /**
     * @brief Adds a summoned character to the AI's field.
     * @param character Character to add.
     */
    void addAICharacter(const Character& character);

    /**
     * @brief Runs the AI's decision-making logic for its turn.
     */
    void aiMakeMove();

    /**
     * @brief Searches for a character card in the AI's hand.
     * @return Index or -1 if none found.
     */
    int findCharacterCardAIHand();

    /**
     * @brief Searches for an attack card in the AI's hand.
     * @return Index or -1 if none found.
     */
    int findAttackCardInAIHand();

    /**
     * @brief Searches for a support card in the AI's hand.
     * @return Index or -1 if none found.
     */
    int findSupportCardAIHand();

    /**
     * @brief Checks if any AI-controlled character is damaged.
     * @return True if at least one unit has lost HP.
     */
    bool checkAIAnyDamagedAlly();

    /**
     * @brief Locates a strong enemy unit (ATK ≥ 4).
     * @return Index or -1 if none found.
     */
    int findStrongEnemy();

    /**
     * @brief Gets a reference to the player's deck.
     */
    std::vector<std::unique_ptr<Card>>& getPlayerDeck();

    /**
     * @brief Gets a reference to the AI's deck.
     */
    std::vector<std::unique_ptr<Card>>& getAIDeck();

    /**
     * @brief Gets a reference to the player's hand.
     */
    std::vector<std::unique_ptr<Card>>& getPlayerHand();

    /**
     * @brief Gets a reference to the AI's hand.
     */
    std::vector<std::unique_ptr<Card>>& getAIHand();

    /**
     * @brief Gets a reference to the player's characters on the battlefield.
     */
    std::vector<Character>& getPlayerField();

    /**
     * @brief Gets a reference to the AI's characters on the battlefield.
     */
    std::vector<Character>& getAIField();
};

#endif // GAME_MANAGER_HPP

