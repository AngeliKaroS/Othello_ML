#include <stdio.h>
#include "othello.h"
#include "linked_list.h"

int
main()
{
    int board[8][8];

    int winner;

    init_board(board);
    init_direction();

    winner = play_othello(board);

    printf("player%d has won", winner);

    return 0;
}
