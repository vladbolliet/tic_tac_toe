#include <stdio.h>

// header files written by me

#include "constants.h"
#include "check_move.h"
#include "game_end.h"
#include "ui.h"

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

void smart_bot_move(char (*board)[3], char bot, char player) {
    
    //STEP 1: if a winning move exists, take it

    // make a copy of board to simulate moves

    char copy[3][3];

    //int counter=0; //to check if its the first move

    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            copy[i][j] = board[i][j];
            if(board[i][j] != EMPTY){
                //counter++;
            }
        }
    }

    // STEP 1: if a winning move exists, take it
    //printf("DEBUG: checking for winning move\n");
    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            if(move_is_valid(copy, i, j)){
                copy[i][j] = bot;
                if(game_end(copy, player, bot) == bot){
                    board[i][j] = bot;
                    return;
                }
                copy[i][j] = EMPTY;
            }
        }
    }

    //STEP 2: if a winning move for player exists, block it
    //printf("DEBUG: checking for blocking move\n");
    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            if(move_is_valid(copy, i, j)){
                //printf("DEBUG: checking %d %d\n", i, j);
                copy[i][j] = player;
                if(game_end(copy, player, bot) == player){
                    //printf("DEBUG: found winning move for player\n");
                    board[i][j] = bot;
                    return;
                }
                copy[i][j] = EMPTY;
            }
        }
    }

    //STEP 3: if player has fork, block it
    //printf("DEBUG: checking for player's fork\n");
    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            
            if(move_is_valid(copy, i, j)){
                //printf("DEBUG: checking %d %d\n", i, j);
                copy[i][j] = player;
                if(has_fork(copy, player)){
                    //printf("DEBUG: found player's fork at %d %d\n", i, j);
                    board[i][j] = bot;
                    return;
                }
                copy[i][j] = EMPTY;
            }
        }
    }

    //STEP 4: if bot has fork, make a fork
    //printf("DEBUG: checking for bot's fork\n");
    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            if(move_is_valid(copy, i, j)){
                copy[i][j] = bot;
                if(has_fork(copy, bot)){
                    board[i][j] = bot;
                    return;
                }
                copy[i][j] = EMPTY;
            }
        }
    }

    //take the center if it's empty
    //printf("DEBUG: taking center\n");
    if(board[1][1] == EMPTY){
        board[1][1] = bot;
        return;
    }

    

    //take a corner if it's empty
    //printf("DEBUG: taking corner\n");
    if(board[0][0] == EMPTY){
        board[0][0] = bot;
        return;
    }
    if(board[0][2] == EMPTY){
        board[0][2] = bot;
        return;
    }
    if(board[2][0] == EMPTY){
        board[2][0] = bot;
        return;
    }
    if(board[2][2] == EMPTY){
        board[2][2] = bot;
        return;
    }

    //take an edge if it's empty
    //printf("DEBUG: taking edge\n");
    if(board[0][1] == EMPTY){
        board[0][1] = bot;
        return;
    }
    if(board[1][0] == EMPTY){
        board[1][0] = bot;
        return;
    }
    if(board[1][2] == EMPTY){
        board[1][2] = bot;
        return;
    }
    if(board[2][1] == EMPTY){
        board[2][1] = bot;
        return;
    }
}

int has_fork(char board[3][3], char player) {

    // check if player owns two corners

    int cornersOwned = -1; //one in minus because we simulated the move 
    if (board[0][0] == player) cornersOwned++;
    if (board[0][2] == player) cornersOwned++;
    if (board[2][0] == player) cornersOwned++;
    if (board[2][2] == player) cornersOwned++;
    if (cornersOwned < 2) return FALSE;

    //printf("DEBUG: %c owns %d corners\n", player,cornersOwned);

    if(
        //the two corners are on top row
        (board[0][0] == player && board[0][2] == player && board[0][1] == EMPTY && board[1][1] == EMPTY) ||
        //the two corners are on bottom row
        (board[2][0] == player && board[2][2] == player && board[2][1] == EMPTY && board[1][1] == EMPTY) ||
        //the two corners are on left column
        (board[0][0] == player && board[2][0] == player && board[1][0] == EMPTY && board[1][1] == EMPTY) ||
        //the two corners are on right column
        (board[0][2] == player && board[2][2] == player && board[1][2] == EMPTY && board[1][1] == EMPTY) ||
        //the two corners are on first diagonal
        (
            board[0][0] == player && board[2][2] == player && 
            (
                (board[0][1] == EMPTY && board[0][2] == EMPTY && board[1][2] == EMPTY) || 
                (board[1][0] == EMPTY && board[2][0] == EMPTY && board[2][1] == EMPTY)
            )
        ) ||
        //the two corners are on second diagonal
        (
            board[0][2] == player && board[2][0] == player && 
            (
                (board[0][1] == EMPTY && board[0][0] == EMPTY && board[1][0] == EMPTY) || 
                (board[1][2] == EMPTY && board[2][2] == EMPTY && board[2][1] == EMPTY)
            )
        )
      )
    {
        return TRUE;
    }

    return FALSE;
}