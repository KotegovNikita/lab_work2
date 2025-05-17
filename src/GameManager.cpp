/**
 * @file GameManager.cpp
 * @brief Implementation of the GameManager class – the central coordinator of a console‑based
 *        turn‑based card RPG.  It is responsible for initialising decks, handling the
 *        main turn loop, controlling AI behaviour, checking win conditions and exposing
 *        helpers that other cards use to interact with the battlefield.
 *
 * The file also contains several small helper routines that are closely coupled to the
 * manager logic (e.g. @c canAddCardToHand).  All comments follow the Doxygen style so the
 * file can be fed directly to Doxygen without further changes.
 *
 * @copyright
 * Copyright (c) 2025 <Your‑Name‑Here>.  All rights reserved.
 */

#include "GameManager.hpp"
#include "AbilityCard.hpp"
#include <iostream>
#include <limits>
#include <ctime>
#include <cstdlib>
#include "Knight.hpp"
#include "Berserk.hpp"
#include "Lightning_strike.hpp"
#include "FlameWave.hpp"
#include "Heal.hpp"
#include "Assassin.hpp"
#include "Elementalist.hpp"
#include "Thief.hpp"
#include "Barrier.hpp"
#include "Warlock.hpp"

/**
 * @brief Default constructor
 *
 * At this stage the constructor does not need to perform any work because most heavy
 * initialisation is deferred to the @ref startGame method.
 */
GameManager::GameManager() = default;

/**
 * @brief Virtual destructor
 *
 * Currently does nothing, but it is defined explicitly so that virtual dispatch is
 * respected (in case further clean‑up is added later or the class becomes a base class).
 */
GameManager::~GameManager() = default;

/**
 * @brief Bootstraps a new match (decks → hands → first draw) and prints basic information.
 *
 * This method
 * 1. Builds a fresh deck for both the player and the AI.
 * 2. Deals the full deck into the player/AI hands while respecting deck rules via
 *    @ref dealCards and @ref ensureMinimumAbilityCards.
 * 3. Displays initial hand sizes so that the user sees immediate feedback.
 */
void GameManager::startGame()
{
    std::cout << "Game started!\n";

    // 1. Build full decks
    initializePlayerDeck();
    initializeAIDeck();

    // 2. Move every card from deck to hand, enforcing composition constraints
    dealCards(static_cast<int>(m_playerDeck.size()), m_playerHand, m_playerDeck);
    dealCards(static_cast<int>(m_aiDeck.size()), m_aiHand, m_aiDeck);

    // 3. Guarantee at least two ability cards in every opening hand
    ensureMinimumAbilityCards(m_playerHand, m_playerDeck);
    ensureMinimumAbilityCards(m_aiHand, m_aiDeck);

    std::cout << "Player's hand size: " << m_playerHand.size() << "\n";
    std::cout << "AI's hand size: "     << m_aiHand.size()     << "\n";
}

/**
 * @brief Check whether @p card can legally be inserted into @p hand.
 *
 * Game rules forbid adding more than four ability cards or more than one @c Thief card
 * to a single hand.  All other cards are accepted by default.
 *
 * @param card Reference to the *owning* pointer of the card to test.
 * @param hand The target hand (ownership is *not* modified).
 * @return @c true if the card may be added, @c false otherwise.
 */
bool canAddCardToHand(const std::unique_ptr<Card>& card,
                      const std::vector<std::unique_ptr<Card>>& hand)
{
    // Ability‑card quota check -------------------------------------------------
    if (dynamic_cast<AbilityCard*>(card.get())) {
        int abilityCount = 0;
        for (const auto& c : hand) {
            if (dynamic_cast<AbilityCard*>(c.get())) { ++abilityCount; }
        }
        return abilityCount < 4;
    }

    // Thief duplicates are disallowed ----------------------------------------
    if (dynamic_cast<Thief*>(card.get())) {
        int thiefCount = 0;
        for (const auto& c : hand) {
            if (dynamic_cast<Thief*>(c.get())) { ++thiefCount; }
        }
        return thiefCount < 1;
    }

    // All other cases are allowed --------------------------------------------
    return true;
}

/**
 * @brief Ensures that @p hand owns **at least** two ability cards.
 *
 * If the requirement is not met, the function scans @p deck for the first ability
 * cards it can find, moves them into the hand and stops once the quota is reached
 * or the deck becomes empty.
 *
 * @param hand Mutable reference to the target hand.
 * @param deck Mutable reference to the deck which *may lose* cards during the process.
 */
void GameManager::ensureMinimumAbilityCards(std::vector<std::unique_ptr<Card>>& hand,
                                            std::vector<std::unique_ptr<Card>>& deck)
{
    int abilityCount = 0;
    for (const auto& card : hand) {
        if (dynamic_cast<AbilityCard*>(card.get())) { ++abilityCount; }
    }

    while (abilityCount < 2 && !deck.empty()) {
        bool foundAbility = false;
        for (auto it = deck.begin(); it != deck.end(); ++it) {
            if (dynamic_cast<AbilityCard*>(it->get())) {
                hand.push_back(std::move(*it));
                deck.erase(it);
                ++abilityCount;
                foundAbility = true;
                break;
            }
        }
        if (!foundAbility) { break; }
    }
}

// ---------------------------------------------------------------------------
// Deck initialisation helpers
// ---------------------------------------------------------------------------

/**
 * @brief Populate the AI deck with 10 pseudo‑random cards.
 *
 * The distribution is uniform across ten distinct indices (0‑9) each mapped to a
 * particular card type.  The PRNG is seeded once per application lifetime so that
 * multiple calls (such as repeated games) continue with a new random sequence.
 */
void GameManager::initializeAIDeck()
{
    static bool seeded = false;
    if (!seeded) { std::srand(static_cast<unsigned>(std::time(nullptr))); seeded = true; }

    constexpr int deckSize = 10;
    for (int i = 0; i < deckSize; ++i) {
        switch (std::rand() % 10) {
            case 0: m_aiDeck.push_back(std::make_unique<Knight>        ("Knight",        3, 4, 6)); break;
            case 1: m_aiDeck.push_back(std::make_unique<Berserk>       ("Berserk",       2, 5, 4)); break;
            case 2: m_aiDeck.push_back(std::make_unique<Assassin>      ("Assassin",      2, 3, 3)); break;
            case 3: m_aiDeck.push_back(std::make_unique<Elementalist>  ("Elementalist",  3, 5, 3)); break;
            case 4: m_aiDeck.push_back(std::make_unique<Warlock>       ("Warlock",       2, 6, 2)); break;
            case 5: m_aiDeck.push_back(std::make_unique<Thief>         ("Thief",         2, 1, 1)); break;
            case 6: m_aiDeck.push_back(std::make_unique<Lightning_strike>("Lightning_strike", 3, 5)); break;
            case 7: m_aiDeck.push_back(std::make_unique<FlameWave>     ("FlameWave",     4, 3)); break;
            case 8: m_aiDeck.push_back(std::make_unique<Heal>          ("Heal",          2, 4)); break;
            case 9: m_aiDeck.push_back(std::make_unique<Barrier>       ("Barrier",       3, 2)); break;
        }
    }
}

/**
 * @brief Populate the *player* deck with 10 pseudo‑random cards.
 *
 * The logic is identical to @ref initializeAIDeck; duplicated intentionally so both
 * sides have symmetrical random builds without sharing storage.
 */
void GameManager::initializePlayerDeck()
{
    static bool seeded = false;
    if (!seeded) { std::srand(static_cast<unsigned>(std::time(nullptr))); seeded = true; }

    constexpr int deckSize = 10;
    for (int i = 0; i < deckSize; ++i) {
        switch (std::rand() % 10) {
            case 0: m_playerDeck.push_back(std::make_unique<Knight>        ("Knight",        3, 4, 6)); break;
            case 1: m_playerDeck.push_back(std::make_unique<Berserk>       ("Berserk",       2, 5, 4)); break;
            case 2: m_playerDeck.push_back(std::make_unique<Assassin>      ("Assassin",      2, 3, 3)); break;
            case 3: m_playerDeck.push_back(std::make_unique<Elementalist>  ("Elementalist",  3, 5, 3)); break;
            case 4: m_playerDeck.push_back(std::make_unique<Warlock>       ("Warlock",       2, 6, 2)); break;
            case 5: m_playerDeck.push_back(std::make_unique<Thief>         ("Thief",         2, 1, 1)); break;
            case 6: m_playerDeck.push_back(std::make_unique<Lightning_strike>("Lightning_strike", 3, 5)); break;
            case 7: m_playerDeck.push_back(std::make_unique<FlameWave>     ("FlameWave",     4, 3)); break;
            case 8: m_playerDeck.push_back(std::make_unique<Heal>          ("Heal",          2, 4)); break;
            case 9: m_playerDeck.push_back(std::make_unique<Barrier>       ("Barrier",       3, 2)); break;
        }
    }
}

/**
 * @brief Transfer up to @p count cards from @p deck → @p hand while respecting composition rules.
 *
 * Cards that violate @ref canAddCardToHand are temporarily postponed; if we cannot reach
 * the desired amount after traversing the deck once we back‑fill with those postponed
 * cards so that the sizes stay consistent (even if illegal duplicates may appear).
 *
 * @param count Desired number of cards to add.
 * @param hand  Destination hand.
 * @param deck  Source deck; cards are removed (popped) from the back.
 */
void GameManager::dealCards(int count,
                            std::vector<std::unique_ptr<Card>>& hand,
                            std::vector<std::unique_ptr<Card>>& deck)
{
    std::vector<std::unique_ptr<Card>> skippedCards;
    int added = 0;

    // First pass – respect composition rules
    while (added < count && !deck.empty()) {
        auto card = std::move(deck.back()); deck.pop_back();
        if (canAddCardToHand(card, hand)) {
            hand.push_back(std::move(card)); ++added;
        } else {
            skippedCards.push_back(std::move(card));
        }
    }

    // Second pass – try again, ignoring previous rejections
    while (added < count && !deck.empty()) {
        auto card = std::move(deck.back()); deck.pop_back();
        if (canAddCardToHand(card, hand)) { hand.push_back(std::move(card)); ++added; }
    }

    // Third pass – forcibly pad with skipped cards if still short
    while (added < count && !skippedCards.empty()) {
        hand.push_back(std::move(skippedCards.back())); skippedCards.pop_back(); ++added;
    }
}

// ---------------------------------------------------------------------------
// Simple one‑card draws
// ---------------------------------------------------------------------------

/** @brief Draw a single card for the *player* (if any remain in the deck). */
void GameManager::drawCardForPlayer()
{
    if (!m_playerDeck.empty()) {
        auto card = std::move(m_playerDeck.back()); m_playerDeck.pop_back();
        if (canAddCardToHand(card, m_playerHand)) { m_playerHand.push_back(std::move(card)); }
    }
}

/** @brief Draw a single card for the *AI* (if any remain in the deck). */
void GameManager::drawCardForAI()
{
    if (!m_aiDeck.empty()) {
        auto card = std::move(m_aiDeck.back()); m_aiDeck.pop_back();
        if (canAddCardToHand(card, m_aiHand)) { m_aiHand.push_back(std::move(card)); }
    }
}

// ---------------------------------------------------------------------------
// End‑game detection & resolution
// ---------------------------------------------------------------------------

/**
 * @brief Flag the match as finished when *all* hands and decks are empty.
 */
void GameManager::checkGameOver()
{
    if (m_playerHand.empty() && m_aiHand.empty() && m_playerDeck.empty() && m_aiDeck.empty()) {
        m_gameOver = true;
    }
}

/**
 * @brief Compute who won (string explanation) based on the current state.
 *
 * The logic mirrors the project requirements:
 *  - No characters on one side → that side loses immediately.
 *  - Otherwise, if both players are out of resources compare board sizes, then total HP.
 *  - Remaining unresolved cases are considered a draw.
 * @return Human‑readable English message (may contain Russian clarification).
 */
std::string GameManager::determineWinner()
{
    // 1. Immediate elimination conditions ------------------------------------
    if (m_playerField.empty() && !m_aiField.empty()) {
        return "Game over! AI wins! (У игрока не осталось персонажей на поле)";
    }
    if (m_aiField.empty() && !m_playerField.empty()) {
        return "Game over! Player wins! (У ИИ не осталось персонажей на поле)";
    }

    // 2. Both out of cards → tie‑break conditions -----------------------------
    if (m_playerDeck.empty() && m_aiDeck.empty() && m_playerHand.empty() && m_aiHand.empty()) {
        if (m_playerField.size() > m_aiField.size()) {
            return "Game over! Player wins! (Больше персонажей на поле)";
        }
        else if (m_aiField.size() > m_playerField.size()) {
            return "Game over! AI wins! (Больше персонажей на поле)";
        }
        else {
            int playerHealth = 0, aiHealth = 0;
            for (const auto& c : m_playerField) { playerHealth += c.getHealth(); }
            for (const auto& c : m_aiField)     { aiHealth     += c.getHealth(); }

            if      (playerHealth > aiHealth) return "Game over! Player wins! (Больше суммарное здоровье персонажей)";
            else if (aiHealth     > playerHealth) return "Game over! AI wins! (Больше суммарное здоровье персонажей)";
            else         return "Game over! It's a draw!";
        }
    }

    // 3. Default fallback ------------------------------------------------------
    return "Game over! It's a draw!";
}

// ---------------------------------------------------------------------------
// Field & hand accessors (thin wrappers)
// ---------------------------------------------------------------------------

/** @return Mutable reference to the player's hand. */
std::vector<std::unique_ptr<Card>>& GameManager::getPlayerHand() { return m_playerHand; }

/** @return Mutable reference to the AI hand. */
std::vector<std::unique_ptr<Card>>& GameManager::getAIHand() { return m_aiHand; }

/** @return @c true when it is currently the player's turn. */
bool GameManager::isPlayerTurn() const { return m_playerTurn; }

// ---------------------------------------------------------------------------
// Main turn driver (console interaction + AI move)
// ---------------------------------------------------------------------------

/**
 * @brief Execute one full round: player interaction → AI logic → draws → combat → end‑game check.
 *
 * The body is quite verbose because of console I/O, yet the high‑level flow is:
 *  1. Player selects and plays a card (or skips on invalid input).
 *  2. AI chooses a move via @ref aiMakeMove.
 *  3. Both sides draw one card.
 *  4. Optional single combat where the player initiates an attack.
 *  5. End‑game detection and winner announcement when appropriate.
 */
void GameManager::runTurn()
{
    std::cout << "\nRunning turn...\n";

    // --------------------------- Player section -----------------------------
    std::cout << "Player's turn.\n";
    if (!m_playerHand.empty()) {
        std::cout << "Your hand:\n";
        for (size_t i = 0; i < m_playerHand.size(); ++i) {
            std::cout << i << ": " << m_playerHand[i]->getName() << "\n";
        }
        std::cout << "Select a card index to use: ";
        int index; std::cin >> index;
        if (std::cin.fail() || index < 0 || index >= static_cast<int>(m_playerHand.size())) {
            std::cin.clear(); std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Invalid selection. Skipping player's turn.\n";
        } else {
            std::cout << "Player uses " << m_playerHand[index]->getName() << "\n";
            m_playerHand[index]->use(*this);
            m_playerHand.erase(m_playerHand.begin() + index);
        }
    } else {
        std::cout << "Player's hand is empty.\n";
    }

    // ----------------------------- AI section -------------------------------
    m_playerTurn = false;
    std::cout << "AI's turn.\n";
    aiMakeMove();

    // ------------------------------ Draw phase ------------------------------
    drawCardForPlayer();
    drawCardForAI();

    // ------------------------------ Combat ----------------------------------
    if (!m_playerField.empty() && !m_aiField.empty()) {
        std::cout << "Do you want to attack? (y/n): ";
        char answer; std::cin >> answer;
        if (answer == 'y' || answer == 'Y') {
            std::cout << "Your summoned characters:\n";
            for (size_t i = 0; i < m_playerField.size(); ++i) {
                std::cout << i << ": " << m_playerField[i].getName()
                          << " (ATK=" << m_playerField[i].getAttack()
                          << ", HP=" << m_playerField[i].getHealth() << ")\n";
            }
            std::cout << "Select your attacker index: ";
            int attackerIndex; std::cin >> attackerIndex;
            if (attackerIndex < 0 || attackerIndex >= static_cast<int>(m_playerField.size())) {
                std::cout << "Invalid index. Skipping attack.\n";
            } else {
                std::cout << "AI's summoned characters:\n";
                for (size_t i = 0; i < m_aiField.size(); ++i) {
                    std::cout << i << ": " << m_aiField[i].getName()
                              << " (ATK=" << m_aiField[i].getAttack()
                              << ", HP=" << m_aiField[i].getHealth() << ")\n";
                }
                std::cout << "Select target index: ";
                int targetIndex; std::cin >> targetIndex;
                if (targetIndex < 0 || targetIndex >= static_cast<int>(m_aiField.size())) {
                    std::cout << "Invalid index. Skipping attack.\n";
                } else {
                    std::cout << m_playerField[attackerIndex].getName() << " attacks "
                              << m_aiField[targetIndex].getName() << "\n";
                    m_playerField[attackerIndex].attackTarget(m_aiField[targetIndex]);
                    if (m_aiField[targetIndex].isDead()) {
                        std::cout << m_aiField[targetIndex].getName() << " has been defeated!\n";
                        m_aiField.erase(m_aiField.begin() + targetIndex);
                    }
                }
            }
        }
    }

    // ----------------------------- Wrap up ----------------------------------
    checkGameOver();
    if (isGameOver()) { std::cout << determineWinner() << std::endl; }

    m_playerTurn = true; // Next round → player starts again
}

// ---------------------------------------------------------------------------
// Thin utility wrappers
// ---------------------------------------------------------------------------

/** @return @c true if the match has ended (see @ref checkGameOver). */
bool GameManager::isGameOver() const { return m_gameOver; }

/** Adds @p character to the player's side of the battlefield. */
void GameManager::addPlayerCharacter(const Character& character)
{
    m_playerField.push_back(character);
    std::cout << "[GameManager] Added character " << character.getName() << " to player's field.\n";
}

/** Adds @p character to the AI side of the battlefield. */
void GameManager::addAICharacter(const Character& character)
{
    m_aiField.push_back(character);
    std::cout << "[GameManager] Added character " << character.getName() << " to AI's field.\n";
}

// ---------------------------------------------------------------------------
// AI helper routines (private)
// ---------------------------------------------------------------------------

/**
 * @brief Decide and execute the AI move for the current turn.
 *
 * The algorithm follows a simple priority scheme:
 *  1. Early game (first three AI turns) – summon any available character.
 *  2. If no characters on the AI field – summon a character.
 *  3. If the player controls a strong unit – attempt a direct attack card.
 *  4. If any AI unit is hurt – apply a support/heal card.
 *  5. Otherwise play a random card.
 */
void GameManager::aiMakeMove()
{
    bool savedTurn = m_playerTurn; // Preserve original flag for nested calls
    m_playerTurn = false;
    ++m_aiTurnCount;

    // Priority 1: early game hero deployment
    if (m_aiTurnCount <= 3) {
        int heroIndex = findCharacterCardAIHand();
        if (heroIndex != -1) {
            std::cout << "AI uses " << m_aiHand[heroIndex]->getName() << " (hero early game summon)\n";
            m_aiHand[heroIndex]->use(*this);
            m_aiHand.erase(m_aiHand.begin() + heroIndex);
            m_playerTurn = savedTurn; return;
        }
    }

    // Priority 2: empty field → must summon
    if (m_aiField.empty()) {
        int heroIndex = findCharacterCardAIHand();
        if (heroIndex != -1) {
            std::cout << "AI uses " << m_aiHand[heroIndex]->getName() << " (hero)\n";
            m_aiHand[heroIndex]->use(*this);
            m_aiHand.erase(m_aiHand.begin() + heroIndex);
            return;
        }
    }

    // Priority 3: respond to strong enemy
    if (!m_playerField.empty()) {
        int strongEnemyIndex = findStrongEnemy();
        if (strongEnemyIndex != -1) {
            int attackIndex = findAttackCardInAIHand();
            if (attackIndex != -1) {
                std::cout << "AI uses " << m_aiHand[attackIndex]->getName() << " (attack)\n";
                m_aiHand[attackIndex]->use(*this);
                m_aiHand.erase(m_aiHand.begin() + attackIndex);
            }
        }
    }

    // Priority 4: heal/support damaged allies
    if (!m_aiField.empty()) {
        bool hasDamagedAlly = checkAIAnyDamagedAlly();
        if (hasDamagedAlly) {
            int supportIndex = findSupportCardAIHand();
            if (supportIndex != -1) {
                std::cout << "AI uses " << m_aiHand[supportIndex]->getName() << " (support)\n";
                m_aiHand[supportIndex]->use(*this);
                m_aiHand.erase(m_aiHand.begin() + supportIndex);
                m_playerTurn = savedTurn; return;
            }
        }
    }

    // Priority 5: fallback random play
    if (m_aiHand.empty()) {
        std::cout << "AI has no cards.\n"; return;
    }
    int rIndex = std::rand() % m_aiHand.size();
    std::cout << "AI uses " << m_aiHand[rIndex]->getName() << " (random)\n";
    m_aiHand[rIndex]->use(*this);
    m_aiHand.erase(m_aiHand.begin() + rIndex);
    m_playerTurn = savedTurn;
}

// ---------------------------------------------------------------------------
// AI search utilities --------------------------------------------------------
// ---------------------------------------------------------------------------

/** @return Index of the first character card in the AI hand, or −1 if none. */
int GameManager::findCharacterCardAIHand()
{
    for (size_t i = 0; i < m_aiHand.size(); ++i) {
        if (dynamic_cast<CharacterCard*>(m_aiHand[i].get())) { return static_cast<int>(i); }
    }
    return -1;
}

/** @return Index of the first attack card in the AI hand, or −1 if none. */
int GameManager::findAttackCardInAIHand()
{
    for (size_t i = 0; i < m_aiHand.size(); ++i) {
        if (dynamic_cast<AttackCard*>(m_aiHand[i].get())) { return static_cast<int>(i); }
    }
    return -1;
}

/** @return Index of the first support card in the AI hand, or −1 if none. */
int GameManager::findSupportCardAIHand()
{
    for (size_t i = 0; i < m_aiHand.size(); ++i) {
        if (dynamic_cast<SupportCard*>(m_aiHand[i].get())) { return static_cast<int>(i); }
    }
    return -1;
}

/**
 * @brief Check whether *any* AI character is below its initial HP (simplistic heuristic).
 */
bool GameManager::checkAIAnyDamagedAlly()
{
    for (auto& ally : m_aiField) {
        if (ally.getHealth() < ally.getAttack()) { return true; }
    }
    return false;
}

/**
 * @brief Locate a strong enemy (ATK ≥ 4) to prioritise it as a target.
 * @return Index in the player field or −1 if no such enemy exists.
 */
int GameManager::findStrongEnemy()
{
    for (size_t i = 0; i < m_playerField.size(); ++i) {
        if (m_playerField[i].getAttack() >= 4) { return static_cast<int>(i); }
    }
    return -1;
}

// ---------------------------------------------------------------------------
// Accessors to the battlefield (mutable) -------------------------------------
// ---------------------------------------------------------------------------

/** @return Mutable reference to all AI characters on the field. */
std::vector<Character>& GameManager::getAIField() { return m_aiField; }

/** @return Mutable reference to all *player* characters on the field. */
std::vector<Character>& GameManager::getPlayerField() { return m_playerField; }


/**
 * @brief Returns a mutable reference to the player's deck.
 */
std::vector<std::unique_ptr<Card>>& GameManager::getPlayerDeck() {
    return m_playerDeck;
}

/**
 * @brief Returns a mutable reference to the AI's deck.
 */
std::vector<std::unique_ptr<Card>>& GameManager::getAIDeck() {
    return m_aiDeck;
}
