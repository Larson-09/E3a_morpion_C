/**
 * @file game.c
 *
 * @date 19/12/2021
 * @author Hugo BURY and Jordan LAUDE
 */

#include "player_manager.h"
#include "board_view.h"
#include "game.h"

// GLOBAL VARIABLES ----------------------------------------------------------------------------------------------------

/**
 * The marker that tells if the game is finished
 */
bool endOfGameMarker;

// FUNCTIONS -----------------------------------------------------------------------------------------------------------

void Game_init (void)
{
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
    do
    {
        // Manage the turn of the current player
        PlayerManager_oneTurn();
    }
    while(!endOfGameMarker);
}

void Game_SquareChangeCallback(Coordinate x, Coordinate y, PieceType newContent)
{
    BoardView_displaySquare(x, y, newContent);
}

void Game_EndOfGameCallback(GameResult result)
{
    endOfGameMarker = true;
    BoardView_displayEndOfGame(result);
}
