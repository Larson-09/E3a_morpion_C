/**
 * @file main.c
 *
 * @date 7 oct. 2016
 * @author jilias
 */

#include "player_manager.h"
#include "board_view.h"
#include "board.h"

bool temoinFinPartie;
SquareChangeCallback game_onSquareChange;
EndOfGameCallback game_endOfGame;


void Game_init (void)
{
  // TODO: initialiser tous les modules
  temoinFinPartie = false;
  game_onSquareChange = &Game_SquareChangeCallback;
  game_endOfGame = Game_EndOfGameCallback;
}

void Game_free (void)
{
    // TODO: libérer tous les modules
}

void Game_loop (void)
{
	// TODO: à compléter
    do
    {
        PlayerManager_oneTurn();
    }
    while(!temoinFinPartie);

    BoardView_displayEndOfGame();
}

void Game_SquareChangeCallback(Coordinate x, Coordinate y, PieceType newContent)
{
    // TODO: à compléter
    BoardView_displayAll();
}

void Game_EndOfGameCallback(GameResult result)
{
    // TODO: à compléter
    temoinFinPartie = true;
}
