/**
 * @file main.c
 *
 * @date 7/10/2016
 * @author Jonathan ILIAS-PILLET & Richard WOODWARD
 */
// gcc main.c game.c game.h player_manager_scanf.c player_manager.h board_view_text.c board_view.h board.c board.h -o main
#include "game.h"

int main (void)
{
	Game_init ();

	Game_loop ();

	Game_free ();

	return 0;
}
