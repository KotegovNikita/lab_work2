/**
 * @file Thief.cpp
 * @brief Implementation of the Thief class, a Rogue-type character card that can steal a card from the opponent.
 */

#include "Thief.hpp"
#include "GameManager.hpp"
#include "Character.hpp"
#include <iostream>

/**
 * @brief Constructs a Thief character card.
 * 
 * @param name Name of the card.
 * @param cost Resource cost to play this card.
 * @param attack Attack value (usually unused for Thief itself).
 * @param health Health value (usually unused for Thief itself).
 */
Thief::Thief(const std::string& name, int cost, int attack, int health)
    : Rogue(name, cost, attack, health)
{}

/**
 * @brief Gets the name of the Thief card.
 * @return Name string.
 */
std::string Thief::getName() const {
    return m_name;
}

/**
 * @brief Gets the cost to play this card.
 * @return Integer cost.
 */
int Thief::getCost() const {
    return m_cost;
}

/**
 * @brief Gets the attack value of the Thief.
 * @return Attack as integer.
 */
int Thief::getAttack() const {
    return m_attack;
}

/**
 * @brief Gets the health value of the Thief.
 * @return Health as integer.
 */
int Thief::getHealth() const {
    return m_health;
}

/**
 * @brief Activates the Thief card.
 * 
 * When used, the Thief is summoned to the battlefield with stats (1 ATK, 1 HP), 
 * and attempts to steal a random non-Thief card from the opponent’s hand.
 * If only Thieves are in the hand, or the opponent has no cards, the ability fails silently.
 * 
 * @param gm Reference to the current GameManager controlling the game state.
 */
void Thief::use(GameManager& gm) {
    std::cout << "[Thief::use()] Summoning " << m_name << " (ATK=1, HP=1)\n";
    Character newChar(m_name, 1, 1, CharacterType::Thief);

    // Determine who is playing the card
    if (gm.isPlayerTurn()) {
        gm.addPlayerCharacter(newChar);
        auto& opponentHand = gm.getAIHand();
        auto& currentHand = gm.getPlayerHand();

        if (!opponentHand.empty()) {
            bool stolen = false;
            for (int tries = 0; tries < static_cast<int>(opponentHand.size()); ++tries) {
                int index = rand() % opponentHand.size();
                if (dynamic_cast<Thief*>(opponentHand[index].get())) continue;

                std::cout << m_name << " (Thief) steals card " << opponentHand[index]->getName() << " from AI!\n";
                currentHand.push_back(std::move(opponentHand[index]));
                opponentHand.erase(opponentHand.begin() + index);
                stolen = true;
                break;
            }
            if (!stolen)
                std::cout << "Nothing to steal (opponent only has Thief cards)!\n";
        } else {
            std::cout << "AI has no cards to steal.\n";
        }

    } else {
        gm.addAICharacter(newChar);
        auto& opponentHand = gm.getPlayerHand();
        auto& currentHand = gm.getAIHand();

        if (!opponentHand.empty()) {
            bool stolen = false;
            for (int tries = 0; tries < static_cast<int>(opponentHand.size()); ++tries) {
                int index = rand() % opponentHand.size();
                if (dynamic_cast<Thief*>(opponentHand[index].get())) continue;

                std::cout << m_name << " (Thief) steals card " << opponentHand[index]->getName() << " from Player!\n";
                currentHand.push_back(std::move(opponentHand[index]));
                opponentHand.erase(opponentHand.begin() + index);
                stolen = true;
                break;
            }
            if (!stolen)
                std::cout << "Nothing to steal (opponent only has Thief cards)!\n";
        } else {
            std::cout << "Player has no cards to steal.\n";
        }
    }
}

