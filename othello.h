#pragma once

#include "linked_list.h"

struct point
{
    int x;
    int y;
};

struct point DIRECTIONS[8];

LinkedList list;

struct point* check_empty(int board[8][8], int x, int y);
struct point* get_playable(int board[8][8], int turn);
void          init_direction();
void          init_board(int board[8][8]);
int           print_board(int board[8][8]);
int           is_gameover(int board[8][8]);
int           play_othello(int board[8][8]);
int           togle_turn(int turn);
