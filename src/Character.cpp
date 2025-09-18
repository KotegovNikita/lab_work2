/* Nikita Kotegov st128906@student.spbu.ru Group B81 Lab_work2 */
#include "Character.hpp"
#include <string>

/**
 * @brief Constructs a Character with a name, attack, and health.
 * 
 * @param name The character's name.
 * @param attack The base attack value.
 * @param health The initial health value.
 */
Character::Character(const std::string& name, int attack, int health) {
	m_name = name;
	m_attack = attack;
	m_health = health;
}

/**
 * @brief Constructs a Character with an assigned type.
 * 
 * Also sets max health equal to the starting health.
 * 
 * @param name The character's name.
 * @param attack The base attack value.
 * @param health The initial and max health value.
 * @param type The character's class/type.
 */
Character::Character(const std::string& name, int attack, int health, CharacterType type) {
	m_name = name;
	m_attack = attack;
	m_health = health;
	m_type = type;
	m_maxHealth = health;
}

/**
 * @brief Gets the character's name.
 * 
 * @return Name as a std::string.
 */
const std::string Character::getName() const {
	return m_name;
}

/**
 * @brief Gets the character's current attack value.
 * 
 * @return Attack value as an integer.
 */
int Character::getAttack() const {
	return m_attack;
}

/**
 * @brief Gets the character's current health.
 * 
 * @return Health as an integer.
 */
int Character::getHealth() const {
	return m_health;
}

/**
 * @brief Performs an attack on another character.
 * 
 * Applies class-based effects depending on the character type:
 * - Berserk: Bonus damage when below 50% health.
 * - Warlock: Sacrifices HP for extra damage.
 * - Assassin: 30% chance to deal critical (double) damage.
 * 
 * @param target Reference to the character being attacked.
 */
void Character::attackTarget(Character& target)
{
    int damage = m_attack;

    // ─ Berserk бонус
    if (m_type == CharacterType::Berserk && m_health < m_maxHealth / 2) {
        damage += 2;                                 // 5 → 7
        std::cout << m_name << " (Berserk) deals enhanced damage!\n";
    }

    /* Warlock: жертвует 1 HP → +2 dmg */
    if (m_type == CharacterType::Warlock) {
        m_health -= 1;
        damage   += 2;
        std::cout << " (Warlock) sacrifices 1 HP for more power!\n";
    }

    /* Assassin: 30 % крит (гарантирован при srand(0)) */
    if (m_type == CharacterType::Assassin) {
        int critChance = std::rand() % 100;
        if (critChance < 30) {
            damage = m_attack * 2 + 2;               // 3*2 +2 = 8
            std::cout << m_name << " (Assassin) lands a critical strike!\n";
        }
    }
    std::cout << m_name << " attacks " << target.getName()
              << " for " << damage << " damage.\n";
    target.onAttacked(damage, this);
}


/**
 * @brief Handles receiving damage from another character.
 * 
 * @param damage The amount of damage taken.
 * @param attacker Pointer to the attacking character (can be null).
 */
void Character::onAttacked(int damage, Character* attacker)
{
    /* --- Knight: броня 1 + контратака --- */
    if (m_type == CharacterType::Knight) {
        damage = std::max(0, damage - 1);          // поглотили 1
    }

    m_health -= damage;
    if (m_health < 0) m_health = 0;

    std::cout << m_name << " receives " << damage << " damage";
    if (attacker) std::cout << " from " << attacker->getName();
    std::cout << ". Remaining HP: " << m_health << "\n";

    /* контратака (если рыцарь жив и есть цель) */
    if (m_type == CharacterType::Knight && !isDead() && attacker) {
        attacker->onAttacked(1, this);
    }
}

/**
 * @brief Checks whether the character is dead (health <= 0).
 * 
 * @return True if dead, false otherwise.
 */
bool Character::isDead() const {
	return m_health <= 0;
}

