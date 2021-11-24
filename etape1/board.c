#include "board.h"
#include "stdio.h"
#include <assert.h>

// Declare variables and callbacks
#define GRID_SIZE 3 ;
PieceType boardSquares[GRID_SIZE][GRID_SIZE];

SquareChangeCallback boardOnSquareChange;
EndOfGameCallback boardOnEndGame;

GameResult boardGameResult;


static bool isGameFinished (const PieceType boardSquares[GRID_SIZE][GRID_SIZE], Coordinate lastChangeX, Coordinate lastChangeY, GameResult *gameResult)
{
    *gameResult = DRAW;

    // Test if the grid is empty
    bool is_grid_empty = true;
    for(int i = 0 ; i < GRID_SIZE ; i++){
        for (int j = 0; j < GRID_SIZE ; ++j) {
            if (boardSquares[i][j] != NONE)
                is_grid_empty = false;
        }
    }
    if(is_grid_empty) return false;

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
    // Initialize callback function variables
    boardOnSquareChange = onSquareChange;
    boardOnEndGame = onEndOfGame;

    // Initialize the board (full of NONE)
    for (int i = 0; i < GRID_SIZE ; ++i) {
        for (int j = 0; j < GRID_SIZE ; ++j) {
            boardSquares[i][j] = NONE;
        }
    }

}

void Board_free ()
{
    // Precondition
    if (!boardSquares)
        perror("The board square does not exist");
}

PutPieceResult Board_putPiece (Coordinate x, Coordinate y, PieceType kindOfPiece)
{
    // Precondition
    if (x < 0 || x > 2 || y < 0 || y > 2)
        perror("X and Y must be contained between 0 and 2");

    if (kindOfPiece != CROSS && kindOfPiece != CIRCLE)
        perror("kindOfPiece must be CROSS or CIRCLE");

    GameResult *gameResult;
    
    // Check if the case is empty
    if (Board_getSquareContent(x,y) == NONE)
    {
        // Place the piece
        boardSquares[y][x] = kindOfPiece;
        boardOnSquareChange(x,y, kindOfPiece);
        
        // Check if the game is finished
        if (isGameFinished(boardSquares, x,y, ))
        {
            boardOnEndGame(*gameResult);
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
  return boardSquares[y][x];
}



