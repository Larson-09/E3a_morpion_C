#include "board_view.h"
#include <assert.h>
#include <stdio.h>

#define CONFIG_TEXTUI ;

#define GRID_SIZE 3 ;
PieceType boardSquares[GRID_SIZE][GRID_SIZE];

#if defined CONFIG_TEXTUI

void BoardView_init (void)
{
    // Initialize the board
    for (int i = 0; i < GRID_SIZE; ++i) {
        for (int j = 0; j < GRID_SIZE; ++j) {
            boardSquares[i][j] = Board_getSquareContent(i,j);
        }
    }
}

void BoardView_free (void)
{
}

void BoardView_displayAll (void)
{
    printf ("\n_______\n");

    // For each square of the grid, draw a O or a X if there is one in the current grid
    for(int i = 0 ; i < GRID_SIZE ; i++)
    {
        for(int j = 0 ; j < GRID_SIZE ; j++)
        {
            printf("|");
            switch(boardSquares[i][j])
            {
                case NONE : printf(" "); break;
                case CIRCLE : printf("O"); break;
                case CROSS : printf("X"); break;
            }
        }
        printf ("|\n");
        printf ("\n_______\n");
    }
}


void BoardView_displaySquare (Coordinate x, Coordinate y, PieceType kindOfPiece)
{
	BoardView_displayAll();
}

void BoardView_displayEndOfGame (GameResult result)
{
    // Precondition
    if (result != CROSS && result != CIRCLE)
        perror("kindOfPiece must be CROSS or CIRCLE");

    // Display the result
    switch(result)
    {
        case DRAW : printf("The game is finished. Result : DRAW\n"); break;
        case CROSS_WINS : printf("The game is finished. Result : Cross wins\n"); break;
        case CIRCLE_WINS : printf("The game is finished. Result : Circle wins\n"); break;
    }
}

void BoardView_displayPlayersTurn (PieceType thisPlayer)
{
    // Precondition
    if (thisPlayer != CROSS && thisPlayer != CIRCLE)
        perror("kindOfPiece must be CROSS or CIRCLE");

    switch(thisPlayer)
    {
        case CROSS : printf("Turn to play : CROSS\n"); break;
        case CIRCLE : printf("Turn to play : CIRCLE\n"); break;
        default: break;
    }
}

void BoardView_sayCannotPutPiece (void)
{
    printf("The piece can not be placed here because the square is not empty");
}

#endif // defined CONFIG_TEXTUI
