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

void Game_init (void)
{
  // TODO: initialiser tous les modules
  temoinFinPartie = false;
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

void Game_SquareChangeCallback(void)
{
    // TODO: à compléter
    BoardView_displayAll();
}

void Game_EndOfGameCallback(void)
{
    // TODO: à compléter
    temoinFinPartie = true;
}
