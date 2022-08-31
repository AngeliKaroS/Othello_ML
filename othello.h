#include "linked_list.h";

struct point
{
    int x;
    int y;
};

const struct point DIRECTIONS[8];

void          print_board(int board[8][8]);
struct point* get_playable(int board[8][8], int turn);
void          set_stone(int board[8][8], int turn);
int           togle_turn(int turn);
int           win check(int board[8][8]);
