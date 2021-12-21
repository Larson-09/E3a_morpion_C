/**
 * @file board_view.h
 *
 * Tic tac toe's board visualisation module
 *
 * @date 19/12/2021
 * @author Hugo BURY and Jordan LAUDE
 */

#if !defined BOARD_VIEW_H_
#define BOARD_VIEW_H_

#include "board.h"
#include <SDL.h>
#include <SDL_image.h>

// FUNCTIONS DEFINITIONS ------------------------------------------------------------------------------------------------

extern void BoardView_init (void);
/**
 * Constructor of the board view.
 *
 * Must be called before any function of this module.
 */


extern void BoardView_free (void);
/**
 * Destructor of the board view.
 *
 * Must be called after using any function of this module to free
 * related resources.
 */

static void renderImage (SDL_Surface *image, int x, int y);
/**
 * Allow to place an image in the window
 * @param [in] SDL_Surface the SDL image we want to place
 * @param [in] x logical column coordinate
 * @param [in] y logical row coordinate
 */

extern void BoardView_displayAll (void);
/**
 * Displays the entire board (including background) at current status.
 */


extern void BoardView_displaySquare (Coordinate x, Coordinate y, PieceType kindOfPiece);
/**
 * Display the specified content into the specified square.
 *
 * @param [in] x logical column coordinate
 * @param [in] y logical row coordinate
 * @param [in] kindOfPiece the content to display (can be NONE if empty)
 *
 * @pre x must be in [0..2]
 * @pre y must be in [0..2]
 */

extern void BoardView_displayPlayersTurn (PieceType thisPlayer);
/**
 * Displays who has to play.
 *
 * @param [in] thisPlayer the player who has to play, designated by its piece type
 *
 * @pre thisPlayer cannot be NONE
 */

extern void BoardView_displayEndOfGame (GameResult result);
/**
 * Displays a message to the user at the end of the game.
 *
 * @param [in] result winning status
 */

extern void BoardView_sayCannotPutPiece (void);
/**
 * Displays a message when a move has been refused because the square is not empty
 */

#endif /* !defined BOARD_VIEW_H_ */