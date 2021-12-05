/**
 * @file player_manager_scanf.c
 *
 * @date 7 oct. 2016
 * @author jilias
 */

#include "board.h"
#include "board_view.h"
#include <assert.h>
#include <stdio.h>

PieceType current_player;


#define CONFIG_PLAYER_MANAGER_SCANF

#if defined CONFIG_PLAYER_MANAGER_SCANF

void PlayerManager_init (void)
{
    current_player = CROSS;
}

void PlayerManager_free (void)
{
}

void PlayerManager_oneTurn (void)
{
    // Display who is the next player to play
    BoardView_displayPlayersTurn(current_player);

    // Ask for coordinates to put a piece
    PutPieceResult result;
    do
    {
        // Ask for a line and a column
        int col ;
        int line ;

        do {
            printf("Choose a column and a line between  and 3 (X,Y)\n");
            scanf("%d,%d", &col, &line);
        }
        while (line < 0 || line > 2 || col < 0 || col > 2);

        // Check if the piece is correctly placed
        result = Board_putPiece(line, col,current_player);
        if (result == SQUARE_IS_NOT_EMPTY)
            BoardView_sayCannotPutPiece();
    }
    while (result == SQUARE_IS_NOT_EMPTY);

    // Switch to the other player
    switch (current_player) {
        case CROSS: current_player = CIRCLE; break;
        case CIRCLE: current_player = CROSS; break;
    }
}
#endif // defined CONFIG_PLAYER_MANAGER_SCANF
