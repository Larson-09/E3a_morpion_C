#include "board.h"
#include "stdio.h"
#include <assert.h>

PieceType boardSquares[3][3];

static bool isGameFinished (const PieceType boardSquares[3][3], Coordinate lastChangeX, Coordinate lastChangeY, GameResult *gameResult)
{
    *gameResult = DRAW;

    // Test if the grid is empty
    bool is_grid_empty = true;
    for(int i = 0 ; i < 3 ; i++){
        for (int j = 0; j < 3 ; ++j) {
            if (boardSquares[i][j] != NONE)
                is_grid_empty = false;
        }
    }
    if(is_grid_empty) return false;

    // Check if the grid is full
    bool is_grid_full = true;

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; ++j) {
            if (boardSquares[i][j] == NONE) {
                is_grid_full = false;
            }
        }
    }
    if(is_grid_full) return true;

    // Test on lines
    if (boardSquares[lastChangeY][0] == boardSquares[lastChangeY][1]
        && boardSquares[lastChangeY][1] == boardSquares[lastChangeY][2]) {
        // Check what was the last symbol played and return the winner
        switch (boardSquares[lastChangeY][lastChangeX]) {
            case CROSS : *gameResult = CROSS_WINS; return true;
            case CIRCLE : *gameResult = CIRCLE_WINS; return true;
            default : break;
        }
    }

    // Test on column
    if (boardSquares[0][lastChangeX] == boardSquares[1][lastChangeX]
        && boardSquares[1][lastChangeX] == boardSquares[2][lastChangeX]) {
        // Check what was the last symbol played and return the winner
        switch (boardSquares[lastChangeY][lastChangeX]) {
            case CROSS : *gameResult = CROSS_WINS; return true;
            case CIRCLE : *gameResult = CIRCLE_WINS; return true;
            default : break;
        }
    }

    // Test on diagonals
    if (lastChangeX == lastChangeY) {
        // Test on the first diagonal
        if (boardSquares[0][0] == boardSquares[1][1]
            && boardSquares[1][1] == boardSquares[2][2]) {
            // Check what was the last symbol played and return the winner
            switch (boardSquares[lastChangeY][lastChangeX]) {
                case CROSS : *gameResult = CROSS_WINS; return true;
                case CIRCLE : *gameResult = CIRCLE_WINS; return true;
                default : break;
            }
        }
    }

    if (lastChangeX + lastChangeY == 2) {
        // Test on the second diagonal
        if (boardSquares[0][2] == boardSquares[1][1]
            && boardSquares[1][1]  == boardSquares[2][0]) {
            // Check what was the last symbol played and return the winner
            switch (boardSquares[lastChangeY][lastChangeX]) {
                case CROSS : *gameResult = CROSS_WINS; return true;
                case CIRCLE : *gameResult = CIRCLE_WINS; return true;
                default : break;
            }
        }
    }

    // If zero case is verified, the game is not finished
    return false;
}


void Board_init (SquareChangeCallback onSquareChange, EndOfGameCallback onEndOfGame)
{
  // TODO: à compléter
}

void Board_free ()
{
  // TODO: à compléter
}

PutPieceResult Board_putPiece (Coordinate x, Coordinate y, PieceType kindOfPiece)
{
  // TODO: à compléter
}

PieceType Board_getSquareContent (Coordinate x, Coordinate y)
{
  // TODO: à compléter
}



