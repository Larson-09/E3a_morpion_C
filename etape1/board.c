#include "board.h"
#include <assert.h>

PieceType boardSquares[3][3];

static bool is_contained(PieceType elem, PieceType array[])
{
  for (int i = 0 ; i < sizeof(array) ; i++)
  {
    if (array[i] == elem)
      return true;
  }

  return false
}

/**
 * Check if the game has to be ended. Only alignment from the last
 * modified square are checked.
 *
 * @param [in] boardSquares the board to check
 * @param [in] lastChangeX the colum where the last piece has been put
 * @param [in] lastChangeY the row where the last piece has been put
 * @param [out] gameResult the winning status if the game has ended (value is not set if
 * the game is not finished)
 *
 * @pre lastChangeX must be in [0..2]
 * @pre lastChangeY must be in [0..2]
 * @pre gameResult must point on an allocated GameResult variable
 *
 * @return a boolean that tells if the game is finished
 */
static bool isGameFinished (const PieceType boardSquares[3][3], Coordinate lastChangeX, Coordinate lastChangeY, GameResult *gameResult)
{

  // Test on lines
  if ( boardSquares[lastChangeY][0] == boardSquares[lastChangeY][1] == boardSquares[lastChangeY][2]) 
  {
      *gameResult = boardSquares[lastChangeX][lastChangeY];
      return true;
  }

    // Test on column
    if (boardSquares[0][lastChangeX] == boardSquares[1][lastChangeX] == boardSquares[2][lastChangeX] )
    {
        *gameResult = boardSquares[lastChangeX][lastChangeY];
        return true;
    }

    // Test on diagonals
    if(lastChangeX == lastChangeY)
    {
      // Test on the first diagonal
      if (boardSquares[0][0] == boardSquares[1][1] == boardSquares[2][2] ) 
      { 
        *gameResult = boardSquares[lastChangeX][lastChangeY];
        return true;
      }
    }
    else if (lastChangeX + lastChangeY == 2)
    {
      // Test on the second diagonal
      if(boardSquares[0][2] == boardSquares[1][1] == boardSquares[2][0] ) 
      {
        *gameResult = boardSquares[lastChangeX][lastChangeY];
        return true;
      }
    }

    //Test the draw
    // Une case n'est pas winable si on a les trois enums differentes sur sa ligne, sa colonne ou sa diag
    bool is_game_winnable = false;

    
    for(int i = 0 ; i < 3 ; i++)
    {
      for (int j = 0; j < 3; j++)
      {
        // Check if the square is empty
        if(boardSquares[i][j] == NONE)
        {
          //Check if the line is winable

          // Create a tab with values of the current line
          PieceType line[3] = {boardSquares[i][0], boardSquares[i][1], boardSquares[i][2]};

          // Check if the line contains each possible enum
          if (is_contained(CIRCLE, line) && is_contained(CROSS, line), is_contained(NONE, line))
          {
            is_game_winnable = true;
            goto end_loop_is_winnable;
          }

          /*----------------------------------------*/

          //Check if the column is winable

          // Create a tab with values of the current line
          PieceType column[3] = {boardSquares[0][j], boardSquares[1][j], boardSquares[2][j]};

          // Check if the line contains each possible enum
          if (is_contained(CIRCLE, column) && is_contained(CROSS, column), is_contained(NONE, column))
          {
            is_game_winnable = true;
            goto end_loop_is_winnable;
          }

          /*----------------------------------------*/

          //Check if the first diagonal is winable

          // Create a tab with values of the current line
          PieceType diag_1[3] = {boardSquares[0][0], boardSquares[1][1], boardSquares[2][2]};

          // Check if the line contains each possible enum
          if (is_contained(CIRCLE, diag_1) && is_contained(CROSS, diag_1), is_contained(NONE, diag_1))
          {
            is_game_winnable = true;
            goto end_loop_is_winnable;
          }

          /*----------------------------------------*/

          //Check if the first diagonal is winable

          // Create a tab with values of the current line
          PieceType diag_2[3] = {boardSquares[0][0], boardSquares[1][1], boardSquares[2][2]};

          // Check if the line contains each possible enum
          if (is_contained(CIRCLE, diag_2) && is_contained(CROSS, diag_2), is_contained(NONE, diag_2))
          {
            is_game_winnable = true;
            goto end_loop_is_winnable;
          }
        }
      }    
    }
    end_loop_is_winnable:

    
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



