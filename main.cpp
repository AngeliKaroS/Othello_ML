#include <stdio.h>
#include "othello.h"

// player_1 = 1 - black
// player_2 = 2 - white

// left top is 0,0
// right bottom is 7,7

int
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

    return 0;
}

int
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

    return 0;
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

int
check_empty(int board[8][8], int x, int y)
{
    /*
    direction bits
    128  64  32
     16       8
      4   2   1
    */
    int ret  = 0b00000000;
    int turn = board[x][y];

    int direction = 256;

    int i;
    int j;

    for (i = -1; i < 1; i++)
    {
        for (j = -1; j < 1; j++)
        {
            direction >>= 1;

            if ((x + i) < 0 || (y + j) < 0)
                continue;

            if (board[x + i][y + j] == 0)
            {
                ret |= direction;
            }

            direction = check_empty(board, i, j);
        }
    }

    return ret;
}

struct point*
is_playable(int board[8][8], int turn)
{
    struct point* points = new struct point;

    int i;
    int j;

    int direction;

    for (i = 0; i < 8; i++)
    {
        for (j = 0; j < 8; j++)
        {
            if (board[i][j] == 0 || board[i][j] == turn)
                continue;

            direction = check_empty(board, i, j);

            if (!direction)
                continue;
        }
    }

    return points;
}

int
play_othello(int board[8][8])
{
    int turn = 1;

    while (is_gameover(board))
    {

        print_board(board);
    }

    return 0;
}

int
main()
{
    int board[8][8];

    init_board(board);

    play_othello(board);

    return 0;
}
