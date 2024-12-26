# Tic Tac Toe

This is a simple command-line Tic Tac Toe game implemented in C. The game allows a player to play against a bot.

## Files

- `main.c`: The main entry point of the game.
- `ui.c`: Handles the user interface and game flow.
- `game_end.c`: Contains logic to check if the game has ended.
- `check_move.c`: Contains logic to validate moves.
- `constants.h`: Defines constants used throughout the game.
- `ui.h`: Header file for `ui.c`.
- `game_end.h`: Header file for `game_end.c`.
- `check_move.h`: Header file for `check_move.c`.
- `Makefile`: Build instructions for the project.

## How to Build

To build the project, run the following command in the terminal:

```sh
make
```

This will compile the source files and generate an executable named `tic_tac_toe`.

## How to Run

After building the project, you can run the game using the following command:

```sh
./tic_tac_toe
```

## Game Rules

- The game is played on a 3x3 grid.
- The player and the bot take turns to place their marks (`X` or `O`) on the grid.
- The first player to get three of their marks in a row (horizontally, vertically, or diagonally) wins.
- If all nine squares are filled and neither player has three in a row, the game is a draw.

## Functions

### main.c

- `int main()`: Initializes the game board and starts the user interface.

### ui.c

- `void ui(char board[3][3])`: Manages the game flow and user interactions.
- `void initialize_players(char *player, char *bot)`: Randomly assigns marks to the player and the bot.
- `void print_board(char board[3][3])`: Prints the current state of the game board.
- `void welcome_message()`: Prints the welcome message.

### game_end.c

- `char game_end(char board[3][3], char player, char bot)`: Checks if the game has ended and returns the result.

### check_move.c

- `int move_is_valid(char board[3][3], int row, int col)`: Validates if a move is valid.
- `int is_not_within_bounds(int row, int col)`: Checks if the move is within the bounds of the board.
- `int position_is_not_empty(char board[3][3], int row, int col)`: Checks if the position on the board is empty.

Enjoy!