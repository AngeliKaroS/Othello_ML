#include <stdio.h>
#include "othello.h"

// player_1 = 1 - black
// player_2 = 2 - white

// left top is 0,0
// right bottom is 7,7

void
init_direction()
{
    int i;
    int j;
    int dir_index = 0;

    for(i = -1; i =< 1; i++)
    {
        for(j = -1; j =< 1; j++)
        {
            DIRECTIONS[dir_index]->x = i;
            DIRECTIONS[dir_index]->y = j;

            dir_index++;
        }
    }
}

void
init_board(int board[8][8])
{
    int i;
    int j;

    for (i = 0; i < 8; i++)
    {
        for (j = 0; j < 8; j++)
        {
            board[i][j] = 0;
        }
    }

    board[3][3] = 1;
    board[4][4] = 1;

    board[3][4] = 2;
    board[4][3] = 2;
}

void
init_list()
{
    list = new LinkedList;
}

void
print_board(int board[8][8])
{
    int i;
    int j;

    for (i = 0; i < 8; i++)
    {
        for (j = 0; j < 8; j++)
        {
            printf("%d", board[i][j]);
        }

        printf("\n");
    }
}

int
is_gameover(int board[8][8])
{
    int i;
    int j;

    int full = 1;

    for (i = 0; i < 8; i++)
    {
        for (j = 0; j < 8; j++)
        {
            if (!board[i][j])
                full = 0;
        }
    }

    if (full)
    {
        printf("board is full. game will over\n");
        return 1;
    }

    // must be type conversion
    struct point* point1 = is_playable(board, 1);
    struct point* point2 = is_playable(board, 2);

    // int len1 = is_playable(board, 1);
    // int len2 = is_playable(board, 1);

    if (!len1 && !len2)
    {
        printf("board is full. game will over\n");
        return 1;
    }

    delete(point1);
    delete(point2);

    return 0;
}

struct point*
check_empty(int board[8][8], int x, int y)
{
/*
    direction index
    0 1 2
    3   4
    5 6 7
*/
    int ret  = 0b00000000;
    int turn = board[x][y];

    int direction = 256;

    int i;

    int tmp_x;
    int tmp_y;

    struct point ret[8];

    int point_index = 0;

    for (i = 0; i < 8; i++)
    {
        tmp_x = x + DIRECTIONS[i]->x;
        tmp_y = y + DIRECTIONS[i]->y;

        if (board[tmp_x][tmp_y] == 0)
        {
            ret[point_index]->x = tmp_x;
            ret[point_index]->y = tmp_y;
        }
    }

    return ret;
}

void
get_playable(int board[8][8], int turn)
{
    int i;
    int j;

    struct point* empty = new struct point*;

    delete(list);

    list = new LinkedList;

    for (i = 0; i < 8; i++)
    {
        for (j = 0; j < 8; j++)
        {
            if (board[i][j] == 0 || board[i][j] == turn)
                continue;

            empty = new struct point;

            list->append(empty);

            check_empty(board, i, j);
        }
    }
}

void set_stone(int board[8][8])
{
    //TODO: Add set stone code and calculate reverse stones
}

int
play_othello(int board[8][8])
{
    int turn = 1;
    int winner;

    struct point* points;

    while (is_gameover(board))
    {
        print_board(board);

        get_playable(board, turn);

        set_stone(board);

        turn = togle_turn(turn);
    }

    winner = win_check(board);

    return winner;
}

int
togle_turn(int turn)
{
    if (turn == 1)
        return 2;

    else
        return 1;
}
