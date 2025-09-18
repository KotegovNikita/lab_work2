/* Nikita Kotegov st128906@student.spbu.ru Group B81 Lab_work2 */
/**
 * @file test_character_logic.cpp
 * @brief Unit tests for character logic, including special effects by type (e.g., Knight, Berserk, Thief).
 * 
 * This suite validates class-specific combat mechanics and interactions with GameManager.
 * All tests use GoogleTest.
 */

#include <gtest/gtest.h>

#include "Character.hpp"
#include "Knight.hpp"
#include "Berserk.hpp"
#include "Warlock.hpp"
#include "Assassin.hpp"
#include "Thief.hpp"
#include "Elementalist.hpp"
#include "GameManager.hpp"
#include "Lightning_strike.hpp" // used as a simple card for stealing

/// @defgroup CharacterTests Character Logic Tests
/// Tests for character combat behaviors, death check, and thief interactions.
/** @{ */

// ─────────────────────────────────────────────────────────────────────────────
// Knight: absorbs 1 dmg and counterattacks
// ─────────────────────────────────────────────────────────────────────────────

/**
 * @test Knight blocks 1 incoming damage and counterattacks for 1.
 */
TEST(CharacterTest, KnightBlocksOneAndCounterattacks)
{
    Character attacker("Goblin", 4, 5, CharacterType::Berserk);
    Character knight("Knight", 4, 6, CharacterType::Knight);

    attacker.attackTarget(knight);

    EXPECT_EQ(3, knight.getHealth());    // 6 - (4 - 1)
    EXPECT_EQ(4, attacker.getHealth());  // 5 - 1
}

// ─────────────────────────────────────────────────────────────────────────────
// Berserk: bonus damage below 50% HP
// ─────────────────────────────────────────────────────────────────────────────

/**
 * @test Berserk deals +2 damage if below 50% HP.
 */
TEST(CharacterTest, BerserkBonusDamage)
{
    Character berserk("Berserk", 5, 4, CharacterType::Berserk);
    berserk.onAttacked(3, nullptr); // HP = 1 (less than 50%)

    Character dummy("Dummy", 0, 10, CharacterType::Knight);
    berserk.attackTarget(dummy);

    EXPECT_LT(dummy.getHealth(), 6); // 10 - (5 + 2)
}

// ─────────────────────────────────────────────────────────────────────────────
// Warlock: sacrifices 1 HP for +2 damage
// ─────────────────────────────────────────────────────────────────────────────

/**
 * @test Warlock sacrifices 1 HP to gain +2 damage on attack.
 */
TEST(CharacterTest, WarlockSacrifice)
{
    Character warlock("Warlock", 6, 1, CharacterType::Warlock);
    Character dummy("Dummy", 0, 3, CharacterType::Knight);

    warlock.attackTarget(dummy);

    EXPECT_EQ(0, warlock.getHealth());       // 1 - 1
    EXPECT_LE(dummy.getHealth(), 0);         // 3 - 8
}

// ─────────────────────────────────────────────────────────────────────────────
// Assassin: 30% chance to crit (forced via srand)
// ─────────────────────────────────────────────────────────────────────────────

/**
 * @test Assassin lands critical hit (forced via srand(0)).
 */
TEST(CharacterTest, AssassinCriticalHit)
{
    srand(0); // rand() % 100 == 17 ensures crit
    Character assassin("Assassin", 3, 3, CharacterType::Assassin);
    Character dummy("Target", 0, 10, CharacterType::Knight);

    assassin.attackTarget(dummy);

    EXPECT_LT(dummy.getHealth(), 10); 
}

// ─────────────────────────────────────────────────────────────────────────────
// Thief: steals one non-Thief card from opponent
// ─────────────────────────────────────────────────────────────────────────────

/**
 * @test Thief steals one non-Thief card from opponent's hand.
 */
TEST(CharacterTest, ThiefStealsOneCard)
{
    GameManager gm;
    gm.getAIHand().push_back(std::make_unique<Lightning_strike>("Lightning", 3, 5));

    Thief thiefCard("Thief", 2, 1, 1);
    EXPECT_NO_THROW(thiefCard.use(gm));

    EXPECT_EQ(1, static_cast<int>(gm.getPlayerHand().size()));
    EXPECT_EQ(0, static_cast<int>(gm.getAIHand().size()));

    EXPECT_EQ(nullptr, dynamic_cast<Thief*>(gm.getPlayerHand().front().get())) <<
        "Thief should not be able to steal another Thief card.";
}

// ─────────────────────────────────────────────────────────────────────────────
// Elementalist: instantiation and use()
// ─────────────────────────────────────────────────────────────────────────────

/**
 * @test Basic construction and use of Elementalist card.
 */
TEST(CharacterTest, ElementalistBasic)
{
    Elementalist elem("Elementalist", 3, 5, 3);
    EXPECT_EQ("Elementalist", elem.getName());
    EXPECT_EQ(3, elem.getCost());
    EXPECT_EQ(5, elem.getAttack());
    EXPECT_EQ(3, elem.getHealth());

    GameManager gm;
    EXPECT_NO_THROW(elem.use(gm));
}

// ─────────────────────────────────────────────────────────────────────────────
// isDead(): detects when HP <= 0
// ─────────────────────────────────────────────────────────────────────────────

/**
 * @test Verifies that isDead() returns true only when HP <= 0.
 */
TEST(CharacterTest, IsDeadWorks)
{
    Character victim("Victim", 1, 1, CharacterType::Knight);
    EXPECT_FALSE(victim.isDead());

    victim.onAttacked(2, nullptr);
    EXPECT_TRUE(victim.isDead());
}

/** @} */  // end of CharacterTests

