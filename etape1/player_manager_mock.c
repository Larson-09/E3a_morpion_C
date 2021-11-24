/**
 * @file player_manager_mock.c
 *
 * @date 7 oct. 2016
 * @author jilias
 */

// Include files
#include "board.h"
#include <assert.h>
#include <stdio.h>

// Declare callbacks
SquareChangeCallback *onSquareChange;
EndOfGameCallback  *onEndOfGame;

#define CONFIG_PLAYER_MANAGER_MOCK
#if defined CONFIG_PLAYER_MANAGER_MOCK

void PlayerManager_init (void)
{
    Board_init(*onSquareChange, *onEndOfGame);
}

void PlayerManager_free (void)
{
}

void PlayerManager_oneTurn (void)
{
    /* TODO: à compléter */
    Board_putPiece(1, 1, CROSS);


}

#endif //  #if defined CONFIG_PLAYER_MANAGER_MOCK
