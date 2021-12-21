/**
 * @file player_manager.h
 *
 * Players interaction's manager module
 *
 * @date 19/12/2021
 * @author Hugo BURY and Jordan LAUDE
 */

#include <stdbool.h>

#if !defined PLAYER_MANAGER_H_
#define PLAYER_MANAGER_H_

// FUNCTIONS DECLARATIONS ----------------------------------------------------------------------------------------------

extern void PlayerManager_init (void);
/**
 * Constructor of player manager.
 */


extern void PlayerManager_free (void);
/**
 * Destructor of player manager.
 */

extern bool tryMove (int x, int y);
/**
 * Check if the chosen square is empty
 * @param [in] x logical column coordinate
 * @param [in] y logical row coordinate
 *
 * @pre x must be in [0..2]
 * @pre y must be in [0..2]
 *
 * @return True if the square is available, False if it is already occupied
 */

extern void PlayerManager_oneTurn (void);
/**
 * Waits for one player move and do subsequent actions.
 *
 * This function does not return until the player has made a
 * valid move.
 */

#endif /* !defined PLAYER_MANAGER_H_ */