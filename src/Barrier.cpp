#include "Barrier.hpp"
#include "GameManager.hpp"
#include <iostream>

/**
 * @brief Constructs a Barrier support card with a name, cost, and shield power.
 * 
 * @param name The name of the Barrier card.
 * @param cost The cost required to play the card.
 * @param shieldPower The amount of shielding power applied to allies.
 */
Barrier::Barrier(const std::string& name, int cost, int shieldPower)
    : SupportCard(name, cost, shieldPower)
{}

/**
 * @brief Applies the shield effect to allied characters.
 * 
 * If there are allies on the field, this method applies a shield effect to them.
 * The current implementation only logs the action. Shield mechanics should be
 * properly implemented in the game logic (e.g., via status effects or a 
 * shield attribute).
 * 
 * @param gm Reference to the GameManager which handles the game state.
 */
void Barrier::use(GameManager& gm) {
    std::cout << "[Barrier::use()] " << m_name 
              << " creates a shield of power " << m_power << "\n";

    auto& allies = gm.getPlayerField();
    if (allies.empty()) {
        std::cout << "No allies to protect.\n";
        return;
    }

    std::cout << "Applies Barrier to " << allies.size() 
              << " allies.\n";

    // TODO: Implement actual shield mechanics.
}

