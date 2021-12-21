/**
 * @file main.c
 *
 * @date 19/12/2021
 * @author Hugo BURY and Jordan LAUDE
 */

#include "game.h"

int main (void)
{
	Game_init ();

	Game_loop ();

	Game_free ();

	return 0;
}
