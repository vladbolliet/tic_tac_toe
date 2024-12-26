#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h> //for sleep function
#include <string.h> //for strcat function
#include <math.h> //for abs function

#include "ui.h"
#include "constants.h"
#include "check_move.h"
#include "game_end.h"

void ui(char board[3][3]) {
    welcome_message();
    int row, col;
    char player, bot; //players
    int is_first_move = TRUE;
    initialize_players(&player, &bot);
    srand(time(NULL)); //seed for random number generator
    print_board(board);
    while(1){

        // check if the game has ended

        if(game_end(board, player, bot) == player){ 
            printf("Player 1 (%c) wins!\n", player);
            break;
         }
        else if(game_end(board, player, bot) == bot){ 
            printf("Bot (%c) wins!\n", bot);
            break;
        }
        else if(game_end(board, player, bot) == 'd'){ 
            printf("It's a draw!\n");
            break;
        }

         //bot goes first if he's 'x' and it's the first move

        if(bot == 'x' && is_first_move == TRUE){ goto bot_goes_first; }

        // player's turn
        
        while(1){
            printf("Player 1 (%c) enter your move (row column): ", player);
            scanf("%d %d", &row, &col);
            printf("\n");
            row--; col--; //decrement by 1 to match array indices
            if(move_is_valid(board, row, col)){
                board[row][col] = player;
                is_first_move = FALSE;
                break;
            }
            else{
                printf("Invalid move. Try again.\n");
                continue;
            }
        }

        print_board(board);

        //bot's turn

        bot_goes_first:
        
        int seconds = 2;

        // bot is thinking

        while(seconds){
            for (int i = 1; i <= 3; i++) {
                printf("\r\033[KBot is thinking"); // "\r" for carriage return, "\033[K" to clear the line starting from cursor position to the end
                for (int j = 0; j < i; j++) {
                    printf(".");
                    fflush(stdout);
                }
                usleep(333000); // 333ms delay
            }
            seconds--;
        }

        printf("\n");

        // bot's turn

        while(1){
            row = abs(rand() % 3); //abs to avoid negative values
            col = abs(rand() % 3);
            if(move_is_valid(board, row, col)){
                printf("\nBot (%c) played at %d %d\n\n", bot, row + 1, col + 1);
                board[row][col] = bot;
                is_first_move = FALSE;
                break;
            }
        } //end of bot's turn

        print_board(board);

    } //end of big while

} //end of ui

void initialize_players(char *player, char *bot) {
    
    // Randomly assign 'x' to player and 'o' to bot

    srand(time(NULL));
    int random = rand() % 2;
    if (random == 0) {
        *player = 'x';
        *bot = 'o';
    } else {
        *player = 'o';
        *bot = 'x';
    }

    // Print the players
    // \033[4m  \033[0m
    printf("Let's start the game!\n\n");
    char message[200] = "Player plays with ";
    if(*player == 'x') {
        strcat(message, "\033[31mx\033[0m and bot with \033[34mo\033[0m\n\n");
    }
    else {
        strcat(message, "\033[34mo\033[0m and bot with \033[31mx\033[0m\n\n");
    }
    printf("%s", message);
    printf("------------------------------\n\n");
}

void print_board(char board[3][3]) {
    printf("  +---+---+---+\n"); // Top border
    for (int i = 0; i < 3; i++) {
        printf("\033[33m%d\033[0m |", i + 1); // Row numbers
        for (int j = 0; j < 3; j++) {
            if (board[i][j] == 'x') {
                printf(" \033[31m%c\033[0m", board[i][j]); // Red color for 'X'
            }
            else if (board[i][j] == 'o') {
                printf(" \033[34m%c\033[0m", board[i][j]); // Blue color for 'O'
            }
            else {
                printf(" %c", board[i][j]);
            }
            printf(" |");
        }
        printf("\n");
        if (i < 2) {
            printf("  +---+---+---+\n"); // Middle border
        }
    }
    printf("  +---+---+---+\n"); // Bottom border
    printf("    \033[33m1\033[0m   \033[33m2\033[0m   \033[33m3\033[0m\n\n"); // Column numbers
}

void welcome_message() {
    printf("\nWelcome to Tic Tac Toe!\n");
    printf("Unconventional rule: X goes first\n\n");
}