#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include <string>
#include <iostream>
#include <algorithm>

/**
 * @file Character.hpp
 * @brief Declaration of the Character class, which represents an active unit on the battlefield.
 */

/**
 * @enum CharacterType
 * @brief Enumerates the possible character archetypes.
 * 
 * Used for classification, effects, or type-based behavior in the game.
 */
enum class CharacterType {
    Knight,
    Berserk,
    Elementalist,
    Warlock,
    Assassin,
    Thief,
    Unknown
};

/**
 * @class Character
 * @brief Represents a combat unit summoned to the battlefield.
 * 
 * Each character has a name, attack value, health, and type. Characters can engage
 * in combat, receive damage, be healed, and be destroyed. They are not playable cards,
 * but rather active units placed on the board.
 */
class Character {
private:
    std::string m_name;        ///< Character's name
    int m_attack;              ///< Attack strength
    int m_health;              ///< Current health
    int m_maxHealth;           ///< Maximum health (for healing cap)
    CharacterType m_type;      ///< Type/classification of the character

public:
    /**
     * @brief Constructs a character with unknown type.
     * 
     * @param name Character name.
     * @param attack Attack value.
     * @param health Starting and maximum health.
     */
    Character(const std::string& name, int attack, int health);

    /**
     * @brief Constructs a character with a specific type.
     * 
     * @param name Character name.
     * @param attack Attack value.
     * @param health Starting and maximum health.
     * @param type The character type.
     */
    Character(const std::string& name, int attack, int health, CharacterType type);

    /**
     * @brief Virtual destructor.
     */
    ~Character() = default;

    /**
     * @brief Gets the character's name.
     * @return String name.
     */
    const std::string getName() const;

    /**
     * @brief Gets the character's attack value.
     * @return Integer attack.
     */
    int getAttack() const;

    /**
     * @brief Gets the character's current health.
     * @return Integer health.
     */
    int getHealth() const;

    /**
     * @brief Attacks another character, reducing its health.
     * 
     * This method applies this character’s attack to the target’s health.
     * 
     * @param target The enemy character to be attacked.
     */
    void attackTarget(Character& target);

    /**
     * @brief Handles receiving damage.
     * 
     * Reduces the character's health by the given damage. Optionally, can receive
     * a pointer to the attacker (unused currently).
     * 
     * @param damage Amount of damage received.
     * @param attacker Optional pointer to the attacker.
     */
    void onAttacked(int damage, Character* attacker = nullptr);

    /**
     * @brief Heals the character by a given amount (capped by max health).
     * @param amount HP to restore.
     */
    void heal(int amount) {
        m_health = std::min(m_health + amount, m_maxHealth);
    }

    /**
     * @brief Returns the character's type.
     * @return CharacterType enum value.
     */
    CharacterType getType() const {
        return m_type;
    }

    /**
     * @brief Checks if the character has 0 or less HP.
     * @return True if dead, false otherwise.
     */
    bool isDead() const;
};

#endif // CHARACTER_HPP

