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
PieceType current_player;
int i;

#define CONFIG_PLAYER_MANAGER_MOCK
#if defined CONFIG_PLAYER_MANAGER_MOCK

void PlayerManager_init (void)
{
    current_player = CROSS;
    i = 0;
}

void PlayerManager_free (void)
{
}

void PlayerManager_oneTurn (void)
{
    /* TODO: à compléter */
    //test board
//    int test_cross_wins_x[20] = {0,1,0,1,2,1};
//    int test_cross_wins_y[20] = {0,0,1,2,1,1};
//    Board_putPiece(test_cross_wins_y[i], test_cross_wins_x[i], current_player);

    int test_circle_wins_x[20] = {2,0,1,1,0,2};
    int test_circle_wins_y[20] = {1,0,2,1,2,2};
    Board_putPiece(test_circle_wins_y[i], test_circle_wins_x[i], current_player);

    // Switch to the other player
    switch (current_player) {
        case CROSS: current_player = CIRCLE; break;
        case CIRCLE: current_player = CROSS; break;
    }

    i++;
}

#endif //  #if defined CONFIG_PLAYER_MANAGER_MOCK
