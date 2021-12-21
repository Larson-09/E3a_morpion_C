/**
 * @file board.c
 *
 * @date 19/12/2021
 * @author Hugo BURY & Jordan LAUDE
 */
#include "board.h"
#include "stdio.h"
#include <assert.h>

// GLOBAL VARIABLES ----------------------------------------------------------------------------------------------------

/**
 * The size of the grid
 */
#define GRID_SIZE 3

/**
 * The tic-tac-toe board
 */
PieceType boardSquares[GRID_SIZE][GRID_SIZE];

/**
 * Function callback to use when the value of a square changes
 */
SquareChangeCallback Board_onSquareChange;

/**
 * Function callback to use when the game is finished
 */
EndOfGameCallback Board_onEndGame;

/**
 * The result of the game
 */
GameResult Board_gameResult;

// PRECONDITIONS FUNCTIONS ---------------------------------------------------------------------------------------------

void prec_valid_coordinates(Coordinate x, Coordinate y)
{
    // Precondition
    if (x < 0 || x > 2 || y < 0 || y > 2)
        perror("X and Y must be contained between 0 and 2");
}

void prec_valid_piecetype(PieceType kindOfPiece)
{
    if (kindOfPiece != CROSS && kindOfPiece != CIRCLE)
        perror("kindOfPiece must be CROSS or CIRCLE");
}

// MAIN FUNCTIONS ------------------------------------------------------------------------------------------------------

static bool Board_isGameFinished (const PieceType boardSquares[GRID_SIZE][GRID_SIZE], Coordinate lastChangeX,
                                  Coordinate lastChangeY, GameResult *gameResult)
{
    // Preconditions
    prec_valid_coordinates(lastChangeX, lastChangeY);
    *gameResult = DRAW;

    // Test if the grid is empty
    bool isGridEmpty = true;
    for(int i = 0 ; i < GRID_SIZE ; i++){
        for (int j = 0; j < GRID_SIZE ; ++j) {
            if (boardSquares[i][j] != NONE)
                isGridEmpty = false;
        }
    }
    if(isGridEmpty) return false;

    // Check if the grid is full
    bool is_grid_full = true;

    for (int i = 0; i < GRID_SIZE; i++) {
        for (int j = 0; j < GRID_SIZE; ++j) {
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
    // Init callback function variables
    Board_onSquareChange = onSquareChange;
    Board_onEndGame = onEndOfGame;

    // Init the board (full of NONE)
    for (int i = 0; i < GRID_SIZE ; ++i) {
        for (int j = 0; j < GRID_SIZE ; ++j) {
            boardSquares[i][j] = NONE;
        }
    }
}

void Board_free ()
{
}

PutPieceResult Board_putPiece (Coordinate x, Coordinate y, PieceType kindOfPiece)
{
    // Preconditions
    prec_valid_coordinates(x, y);
    prec_valid_piecetype(kindOfPiece);

    // Check if the case is empty
    if (Board_getSquareContent(x,y) == NONE)
    {
        // Place the piece
        boardSquares[y][x] = kindOfPiece;
        Board_onSquareChange(x,y, kindOfPiece);

        // Check if the game is finished
        if (Board_isGameFinished(boardSquares, x,y, &Board_gameResult))
        {
            Board_onEndGame(Board_gameResult);
        }

        // Return the fact that the piece is in place
        return PIECE_IN_PLACE;
    }
    else
    {
        // Return the fact that the place was not empty
        return SQUARE_IS_NOT_EMPTY;
    }
}

PieceType Board_getSquareContent (Coordinate x, Coordinate y)
{
    // Preconditions
    prec_valid_coordinates(x, y);
    return boardSquares[y][x];
}




