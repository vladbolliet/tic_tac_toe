#ifndef UI_H
#define UI_H

void ui(char board[3][3]);
void initialize_players(char *player1, char *player2);
void print_board(char board[3][3]);
void welcome_message();
int choose_game_mode();

#endif