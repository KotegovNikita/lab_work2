Functional Requirements

 - The player must be able to:

   1)Select and play cards.

   2)Attack the opponent with characters.

   3)Use the abilities of the cards.

 - The AI should analyze the situation and choose the best actions.

 - The game should automatically determine the winner.

 - A text interface (console version) should be implemented.

 - The code should be modular, covered by tests.


Scenario 1: Start of the game
 - Who goes: Player.

  1)Player starts the game.

  2)Gets 5 cards in his hand.

  3)Starts a turn.

Scenario 2: Player's turn
 - Who moves: Player.

  1)Selects a character card and plays it.

  2)Selects an ability and uses it.

  3)Ends the turn.

Scenario 3: AI Action

 - Who moves: AI.

  1)Analyses the situation.

  2)Selects the optimal action (attack, defend or heal).

  3)Ends the turn.

Scenario 4: Game Completion

 - Who moves: System.

  1)Checks if the players have characters on the field.

  2)If one of the players has no more characters → declares a winner.

  3)If both players have no cards in the deck, but one player has characters → he wins.

  4)Displays the result of the game.

  5)Suggests starting a new game.
