// header files written by me

#include "constants.h"
#include "check_move.h"

// function definitions

int move_is_valid(char board[3][3], int row, int col) {
    if(is_not_within_bounds(row, col)){ return FALSE; }
    else if(position_is_not_empty(board, row, col)){ return FALSE; }
    return TRUE;
}

int is_not_within_bounds(int row, int col) {
    if(row < 0 || row > 2 || col < 0 || col > 2){
        return TRUE;
    }
    return FALSE;
}

int position_is_not_empty(char board[3][3], int row, int col) {
    if(board[row][col] != EMPTY){
        return TRUE;
    }
    return FALSE;
}