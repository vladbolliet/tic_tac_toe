#include "game_end.h"
#include "constants.h"

char game_end(char board[3][3], char player, char bot){

    for(int i = 0; i < 3; i++){

        //check if there are 3 consecutive x's or o's in a row

        if(board[i][0] == player && board[i][1] == player && board[i][2] == player){
            return player;
        }
        else if(board[i][0] == bot && board[i][1] == bot && board[i][2] == bot){
            return bot;
        }

        //check if there are 3 consecutive x's or o's in a column

        else if (board[0][i] == player && board[1][i] == player && board[2][i] == player){
            return player;
        }
        else if (board[0][i] == bot && board[1][i] == bot && board[2][i] == bot){
            return bot;
        }
    }

    //check if there are 3 consecutive x's or o's in a diagonal

    if(board[0][0] == player && board[1][1] == player && board[2][2] == player){
        return player;
    }
    else if(board[0][0] == bot && board[1][1] == bot && board[2][2] == bot){
        return bot;
    }
    else if(board[0][2] == player && board[1][1] == player && board[2][0] == player){
        return player;
    }
    else if(board[0][2] == bot && board[1][1] == bot && board[2][0] == bot){
        return bot;
    }

    // check if the board is full

    int is_full = TRUE;
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            if(board[i][j] == EMPTY){
                is_full = FALSE;
                break;
            }
        }
    }
    if(is_full){
        return 'd';
    }
}