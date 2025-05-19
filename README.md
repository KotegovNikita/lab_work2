# lab_work2
##Author
Kotegov Nikita Andreevich | Group B81
##Contacts
st128906@student.spbu.ru

## Description

The player controls a deck of cards consisting of character and ability cards. During combat, character cards summon fighters onto the field, and ability cards are used to deal damage, heal, or provide shields. The AI opponent follows the same rules. The winner is the one who eliminates all enemy characters.

## How to Play

1. **Start the game**: After building the project, run:  
   $ ./my_game  
2. **Initial hand**: Both you and the AI receive cards into your hand.  
3. **Player turn**:  
   - Select a card index from your hand and press Enter.  
   - If it’s a **character card**, it summons a character to your field.  
   - If it’s an **ability card**, its effect (damage, heal, or shield) is applied.  
4. **AI turn**: The AI plays a card following the same rules.  
5. **Attack phase**: If both sides have characters on the field, you’ll be prompted:  
   `Attack? (y/n)`  
   - If you choose **y**, select your attacker index and then target index.  
6. **Game end**: The game repeats until one of the following occurs:  
   - Both hands and decks are empty.  
   - One side has no characters on the field.

## Build and Run

### Prerequisites

- CMake (version 3.10 or higher)  
- A C++17 compatible compiler  
- Google Test (for unit testing)  

### Build steps

    mkdir build && cd build
    cmake ..
    make

### Run the game

    ./my_game

## Testing

Unit tests use Google Test. From the `build` directory, run:

    ./tests/my_game_tests
