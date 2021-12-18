/**
 * @file player_manager_mock.c
 *
 * @date 7 oct. 2016
 * @author jilias
 */
#include "board.h"
#include <assert.h>
#include <stdio.h>

// -------------------------------------------- DECLARATIONS -----------------------------------------------------------

/**
 * The piece type of the current player
 */
PieceType currentPlayer;


/**
 * Counter used to go through the testing array
 */
int i;

#if defined CONFIG_PLAYER_MANAGER_MOCK

// -------------------------------------------- FUNCTIONS --------------------------------------------------------------

void PlayerManager_init (void)
{
    currentPlayer = CROSS;
    i = 0;
}

void PlayerManager_free (void)
{
}

void PlayerManager_oneTurn (void)
{
    //test cross wins case
#if defined MOCKFLAG_CROSS_WINS
    int testSetRow[20] = {0,1,0,1,0};
    int testSetCol[20] = {0,0,1,2,2};
#endif

    //test circle wins case
#if defined MOCKFLAG_CIRCLE_WINS
    int testSetRow[20] = {2,0,1,1,0,2};
    int testSetCol[20] = {1,0,2,1,2,2};
#endif

    // test the draw case
#if defined MOCKFLAG_DRAW
    int testSetRow[20] = {0,0,0,1,1,1,2,2,2};
    int testSetCol[20] = {0,1,2,1,0,2,1,0,2};
#endif

    Board_putPiece(testSetCol[i], testSetRow[i], currentPlayer);

    // Switch to the zzz player
    switch (currentPlayer) {
        case CROSS: currentPlayer = CIRCLE; break;
        case CIRCLE: currentPlayer = CROSS; break;
    }
    i++;
}

#endif //  #if defined CONFIG_PLAYER_MANAGER_MOCK
