/**
 * @file main.c
 *
 * @date 7 oct. 2016
 * @author jilias
 */

#include "player_manager.h"
#include "board_view.h"
#include "board.h"

// -------------------------------------------- DECLARATIONS -----------------------------------------------------------

/**
 * The marker that tells if the game is finished
 */
bool endOfGameMarker;

// -------------------------------------------- FUNCTIONS --------------------------------------------------------------

/**
 * Display the view on square changes
 *
 * @param [in] x the board's column where the square is
 * @param [in] y the board's row where the square is
 * @param [in] newContent the new square's content
 */
void Game_SquareChangeCallback(Coordinate x, Coordinate y, PieceType newContent)
{
    // TODO: à compléter
    BoardView_displaySquare(x, y, newContent);
}

/**
 * Display the result when the game ends.
 *
 * @param [in] result result of the game (who wins or not)
 */
void Game_EndOfGameCallback(GameResult result)
{
    // TODO: à compléter
    endOfGameMarker = true;
    BoardView_displayEndOfGame(result);
}

void Game_init (void)
{
  // TODO: initialiser tous les modules

  // Initialize the end of game marker at false
  endOfGameMarker = false;

  // Initialize modules
  Board_init(Game_SquareChangeCallback, Game_EndOfGameCallback);
  BoardView_init();
  PlayerManager_init();
}

void Game_free (void)
{
    Board_free();
    PlayerManager_free();
    BoardView_free();
}

void Game_loop (void)
{
	// TODO: à compléter
    do
    {
        // Manage the turn of the current player
        PlayerManager_oneTurn();
    }
    while(!endOfGameMarker);
}


