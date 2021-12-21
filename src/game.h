/**
 * @file game.h
 *
 * Whole game's management module
 *
 * @date 19/12/2021
 * @author Hugo BURY and Jordan LAUDE
 */

#include "board.h"

#if !defined GAME_H_
#define GAME_H_

// FUNCTIONS DECLARATIONS ----------------------------------------------------------------------------------------------
extern void Game_init (void);
/**
 * Game constructor.
 */

extern void Game_free (void);
/**
 * Game constructor.
 */

extern void Game_loop (void);
/**
 * Starts game loop.
 *
 * Exits as soon as the game has ended. This function can then
 * be called again.
 */

void Game_SquareChangeCallback(Coordinate x, Coordinate y, PieceType newContent);
/**
 * Display the view on square changes
 *
 * @param [in] x the board's column where the square is
 * @param [in] y the board's row where the square is
 * @param [in] newContent the new square's content
 */

void Game_EndOfGameCallback(GameResult result);
/**
 * Display the result when the game ends.
 *
 * @param [in] result result of the game (who wins or not)
 */
#endif /* !defined GAME_H_ */