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

#define CONFIG_PLAYER_MANAGER_SCANF
#if defined CONFIG_PLAYER_MANAGER_SCANF

void PlayerManager_init (void)
{
}

void PlayerManager_free (void)
{
}

void PlayerManager_oneTurn (void)
{
    //
    PutPieceResult result;
    do
    {
        result = Board_putPiece(1, 1, CROSS);
    }
    while (result == SQUARE_IS_NOT_EMPTY);

    // Call the SquareChangeCallback


    // Check if the game is finished


}

#endif // defined CONFIG_PLAYER_MANAGER_SCANF
