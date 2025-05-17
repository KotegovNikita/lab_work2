/**
 * @file test_gamemanager.cpp
 * @brief Unit tests for the GameManager class, covering deck logic, hand mechanics, game over checks, and AI behavior.
 * 
 * These tests validate core functionality of the turn-based card engine, focusing on card dealing, turn progression,
 * and end-game evaluation.
 */

#include <gtest/gtest.h>

#include "GameManager.hpp"
#include "Card.hpp"
#include "Thief.hpp"
#include "Lightning_strike.hpp"
#include "FlameWave.hpp"
#include "Heal.hpp"
#include "Barrier.hpp"
#include "AbilityCard.hpp"
#include <memory>

/**
 * @defgroup GameManagerTests GameManager Logic Tests
 * @brief Covers deck initialization, drawing, hand constraints, AI behavior, and game-over detection.
 */
/** @{ */

/**
 * @brief Test fixture for GameManager-based tests.
 */
class GameManagerTest : public ::testing::Test {
protected:
    void SetUp() override {
        gm = new GameManager();
    }
    void TearDown() override {
        delete gm;
    }

    GameManager* gm;
};

/**
 * @test Ensures both player and AI decks are initialized with 10 cards.
 */
TEST_F(GameManagerTest, InitializeDecks) {
    gm->initializePlayerDeck();
    gm->initializeAIDeck();

    EXPECT_EQ(10, gm->getPlayerDeck().size()) << "Player deck must have 10 cards";
    EXPECT_EQ(10, gm->getAIDeck().size()) << "AI deck must have 10 cards";
}

/**
 * @test Validates that dealCards respects card composition rules:
 * - max 1 Thief
 * - attempts to limit to 4 AbilityCards (may be exceeded via fallback).
 */
TEST_F(GameManagerTest, DealCardsCheckLimits) {
    gm->initializePlayerDeck();
    gm->dealCards(10, gm->getPlayerHand(), gm->getPlayerDeck());

    auto& hand = gm->getPlayerHand();
    EXPECT_EQ(10, static_cast<int>(hand.size()));

    int abilityCount = 0, thiefCount = 0;
    for (auto& c : hand) {
        if (dynamic_cast<AbilityCard*>(c.get())) ++abilityCount;
        if (dynamic_cast<Thief*>(c.get())) ++thiefCount;
    }

    EXPECT_LE(thiefCount, 1) << "Should not contain more than 1 Thief";
}

/**
 * @test Ensures drawing a card adds to player's hand and removes from deck.
 */
TEST_F(GameManagerTest, DrawCardForPlayer) {
    gm->initializePlayerDeck();
    auto& hand = gm->getPlayerHand();
    EXPECT_TRUE(hand.empty());

    gm->drawCardForPlayer();

    EXPECT_EQ(1, static_cast<int>(hand.size()));
    EXPECT_EQ(9, static_cast<int>(gm->getPlayerDeck().size()));
}

/**
 * @test Verifies that game ends and reports a draw when all resources are empty.
 */
TEST_F(GameManagerTest, CheckGameOverAndDetermineWinnerEmpty) {
    gm->initializePlayerDeck();
    gm->initializeAIDeck();
    gm->dealCards(10, gm->getPlayerHand(), gm->getPlayerDeck());
    gm->dealCards(10, gm->getAIHand(), gm->getAIDeck());

    gm->getPlayerHand().clear();
    gm->getAIHand().clear();
    gm->getPlayerDeck().clear();
    gm->getAIDeck().clear();

    gm->checkGameOver();
    EXPECT_TRUE(gm->isGameOver()) << "Game should be over if all cards are used";

    EXPECT_EQ("Game over! It's a draw!", gm->determineWinner());
}

/**
 * @test Ensures the AI plays a card if its hand is non-empty and its field is empty.
 */
TEST_F(GameManagerTest, AiMakeMoveNonEmptyHand) {
    gm->initializeAIDeck();
    auto& deck = gm->getAIDeck();
    EXPECT_EQ(10, static_cast<int>(deck.size()));

    gm->dealCards(10, gm->getAIHand(), deck);
    EXPECT_EQ(10, static_cast<int>(gm->getAIHand().size()));
    EXPECT_EQ(0, static_cast<int>(deck.size()));

    auto& field = gm->getAIField();
    EXPECT_TRUE(field.empty());

    gm->aiMakeMove();

    EXPECT_FALSE(field.empty()) << "AI should play a hero if its field is empty and hand is not";
}

/** @} */ // end of GameManagerTests

/*
 * Optional main for standalone testing.
 * GoogleTest provides default main automatically if this is not used.
 *
 * #if 0
 * int main(int argc, char** argv) {
 *     ::testing::InitGoogleTest(&argc, argv);
 *     return RUN_ALL_TESTS();
 * }
 * #endif
 */

