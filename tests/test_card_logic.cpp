/* Nikita Kotegov st128906@student.spbu.ru Group B81 Lab_work2 */
/**
 * @file test_card_logic.cpp
 * @brief Unit tests for card types (CharacterCard, AbilityCard, AttackCard, SupportCard, and their derivatives).
 * 
 * This test suite uses GoogleTest to verify basic behavior of individual card classes.
 * Each test validates constructor data (name, cost, etc.) and ensures that `use(GameManager&)` does not throw.
 */

#include <gtest/gtest.h>

#include "Card.hpp"
#include "CharacterCard.hpp"
#include "AbilityCard.hpp"
#include "AttackCard.hpp"
#include "SupportCard.hpp"

#include "Barrier.hpp"
#include "Heal.hpp"
#include "FlameWave.hpp"
#include "Lightning_strike.hpp"
#include "Elementalist.hpp"
#include "Warlock.hpp"
#include "Thief.hpp"
#include "Berserk.hpp"
#include "Knight.hpp"
#include "Assassin.hpp"

#include "GameManager.hpp"

/// @brief Test implementation of pure virtual Card
class TestCard : public Card {
public:
    TestCard(const std::string& n, int c) : m_name(n), m_cost(c) {}
    std::string getName() const override { return m_name; }
    int getCost() const override { return m_cost; }
    void use(GameManager&) override {}
private:
    std::string m_name; int m_cost;
};

/// @brief Test implementation of CharacterCard
class TestCharacterCard : public CharacterCard {
public:
    TestCharacterCard(const std::string& n, int c, int a, int h)
        : CharacterCard(n, c, a, h) {}
    int getAttack() const override { return m_attack; }
    int getHealth() const override { return m_health; }
    void use(GameManager&) override {}
};

/// @brief Test implementation of AbilityCard
class TestAbilityCard : public AbilityCard {
public:
    TestAbilityCard(const std::string& n, int c, int p)
        : AbilityCard(n, c, p) {}
    void use(GameManager&) override {}
};

/// @brief Test implementation of AttackCard
class TestAttackCard : public AttackCard {
public:
    TestAttackCard(const std::string& n, int c, int d)
        : AttackCard(n, c, d) {}
    void use(GameManager&) override {}
};

/// @brief Test implementation of SupportCard
class TestSupportCard : public SupportCard {
public:
    TestSupportCard(const std::string& n, int c, int p)
        : SupportCard(n, c, p) {}
    void use(GameManager&) override {}
};

/// @defgroup CardLogicTests Card Logic Tests
/// Unit tests for various card types and their basic properties.

/** @{ */

// --- Barrier ---
TEST(CardLogicTest, BarrierBasic) {
    Barrier barrier("Barrier", 3, 2);
    EXPECT_EQ("Barrier", barrier.getName());
    EXPECT_EQ(3, barrier.getCost());
    GameManager gm;
    EXPECT_NO_THROW(barrier.use(gm));
}

// --- Heal ---
TEST(CardLogicTest, HealBasic) {
    Heal heal("Heal", 2, 4);
    EXPECT_EQ("Heal", heal.getName());
    EXPECT_EQ(2, heal.getCost());
    GameManager gm;
    EXPECT_NO_THROW(heal.use(gm));
}

// --- FlameWave ---
TEST(CardLogicTest, FlameWaveBasic) {
    FlameWave fw("FlameWave", 4, 3);
    EXPECT_EQ("FlameWave", fw.getName());
    EXPECT_EQ(4, fw.getCost());
    GameManager gm;
    EXPECT_NO_THROW(fw.use(gm));
}

// --- Lightning Strike ---
TEST(CardLogicTest, LightningStrikeBasic) {
    Lightning_strike ls("Lightning_strike", 3, 5);
    EXPECT_EQ("Lightning_strike", ls.getName());
    EXPECT_EQ(3, ls.getCost());
    GameManager gm;
    EXPECT_NO_THROW(ls.use(gm));
}

// --- Elementalist ---
TEST(CardLogicTest, ElementalistBasic) {
    Elementalist elem("Elementalist", 3, 5, 3);
    EXPECT_EQ("Elementalist", elem.getName());
    EXPECT_EQ(3, elem.getCost());
    EXPECT_EQ(5, elem.getAttack());
    EXPECT_EQ(3, elem.getHealth());
    GameManager gm;
    EXPECT_NO_THROW(elem.use(gm));
}

// --- Warlock ---
TEST(CardLogicTest, WarlockBasic) {
    Warlock war("Warlock", 2, 6, 2);
    EXPECT_EQ("Warlock", war.getName());
    EXPECT_EQ(2, war.getCost());
    EXPECT_EQ(6, war.getAttack());
    EXPECT_EQ(2, war.getHealth());
    GameManager gm;
    EXPECT_NO_THROW(war.use(gm));
}

// --- Thief ---
TEST(CardLogicTest, ThiefBasic) {
    Thief thief("Thief", 2, 1, 1);
    EXPECT_EQ("Thief", thief.getName());
    EXPECT_EQ(2, thief.getCost());
    EXPECT_EQ(1, thief.getAttack());
    EXPECT_EQ(1, thief.getHealth());
    GameManager gm;
    EXPECT_NO_THROW(thief.use(gm));
}

// --- Berserk ---
TEST(CardLogicTest, BerserkBasic) {
    Berserk berserk("Berserk", 2, 5, 4);
    EXPECT_EQ("Berserk", berserk.getName());
    EXPECT_EQ(2, berserk.getCost());
    EXPECT_EQ(5, berserk.getAttack());
    EXPECT_EQ(4, berserk.getHealth());
    GameManager gm;
    EXPECT_NO_THROW(berserk.use(gm));
}

// --- Knight ---
TEST(CardLogicTest, KnightBasic) {
    Knight knight("Knight", 3, 4, 6);
    EXPECT_EQ("Knight", knight.getName());
    EXPECT_EQ(3, knight.getCost());
    EXPECT_EQ(4, knight.getAttack());
    EXPECT_EQ(6, knight.getHealth());
    GameManager gm;
    EXPECT_NO_THROW(knight.use(gm));
}

// --- Assassin ---
TEST(CardLogicTest, AssassinBasic) {
    Assassin assassin("Assassin", 2, 3, 3);
    EXPECT_EQ("Assassin", assassin.getName());
    EXPECT_EQ(2, assassin.getCost());
    EXPECT_EQ(3, assassin.getAttack());
    EXPECT_EQ(3, assassin.getHealth());
    GameManager gm;
    EXPECT_NO_THROW(assassin.use(gm));
}

// --- Base Card ---
TEST(CardLogicTest, CardBasic) {
    TestCard tc("TestCard", 10);
    EXPECT_EQ("TestCard", tc.getName());
    EXPECT_EQ(10, tc.getCost());
    GameManager gm;
    EXPECT_NO_THROW(tc.use(gm));
}

// --- CharacterCard ---
TEST(CardLogicTest, CharacterCardBasic) {
    TestCharacterCard tcc("TestCharacter", 2, 5, 6);
    EXPECT_EQ("TestCharacter", tcc.getName());
    EXPECT_EQ(2, tcc.getCost());
    EXPECT_EQ(5, tcc.getAttack());
    EXPECT_EQ(6, tcc.getHealth());
    GameManager gm;
    EXPECT_NO_THROW(tcc.use(gm));
}

// --- AbilityCard ---
TEST(CardLogicTest, AbilityCardBasic) {
    TestAbilityCard tac("TestAbility", 3, 7);
    EXPECT_EQ("TestAbility", tac.getName());
    EXPECT_EQ(3, tac.getCost());
    GameManager gm;
    EXPECT_NO_THROW(tac.use(gm));
}

// --- AttackCard ---
TEST(CardLogicTest, AttackCardBasic) {
    TestAttackCard tac("TestAttack", 5, 10);
    EXPECT_EQ("TestAttack", tac.getName());
    EXPECT_EQ(5, tac.getCost());
    GameManager gm;
    EXPECT_NO_THROW(tac.use(gm));
}

// --- SupportCard ---
TEST(CardLogicTest, SupportCardBasic) {
    TestSupportCard tsc("TestSupport", 4, 6);
    EXPECT_EQ("TestSupport", tsc.getName());
    EXPECT_EQ(4, tsc.getCost());
    GameManager gm;
    EXPECT_NO_THROW(tsc.use(gm));
}

/** @} */  // end of CardLogicTests

