/**
 * @file tictactoe_erros.c
 *
 * @date 19/12/2021
 * @author Hugo BURY and Jordan LAUDE
 */

#include "tictactoe_errors.h"
#include <stdio.h>
#include <stdlib.h>

// FUNCTIONS -----------------------------------------------------------------------------------------------------------
void fatalError (const char *message)
{
	fprintf (stderr, "%s\n", message);
	exit (1);
}
