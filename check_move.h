#ifndef CHECK_MOVE_H
#define CHECK_MOVE_H

int move_is_valid(char board[3][3], int row, int col);
int is_not_within_bounds(int row, int col);
int position_is_not_empty(char board[3][3], int row, int col);
void smart_bot_move(char (*board)[3], char bot, char player);
int has_fork(char board[3][3], char player);

#endif