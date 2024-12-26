#include <stdio.h> 

//include headers written by me

#include "constants.h"
#include "ui.h"

int main() {
    char board[3][3] = {
        {EMPTY, EMPTY, EMPTY},
        {EMPTY, EMPTY, EMPTY},
        {EMPTY, EMPTY, EMPTY}
    };
    char player1, player2;
    ui(board);
    return 0;
}