/**
 * @file player_manager_mock.c
 *
 * @date 7 oct. 2016
 * @author jilias
 */

#include "board.h"
#include <assert.h>
#include <stdio.h>

#define CONFIG_PLAYER_MANAGER_MOCK

#if defined CONFIG_PLAYER_MANAGER_MOCK

void PlayerManager_init (void)
{
    Board_init(*SquareChangeCallback, *EndOfGameCallback);
}

void PlayerManager_free (void)
{
}

void PlayerManager_oneTurn (void)
{
    /* TODO: à compléter */

    PutPieceResult result;

    do {
        result = Board_putPiece(1, 1, CROSS);
    } while (result == SQUARE_IS_NOT_EMPTY);

}

#endif //  #if defined CONFIG_PLAYER_MANAGER_MOCK
