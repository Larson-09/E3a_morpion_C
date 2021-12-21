/**
 * @file player_manager.c
 *
 * @date 19/12/2021
 * @author Hugo BURY and Jordan LAUDE
 */

#include "board.h"
#include "board_view.h"
#include <assert.h>
#include <SDL.h>
#include <stdbool.h>

#if defined CONFIG_PLAYER_MANAGER_SDL

// GLOBAL VARIABLES ----------------------------------------------------------------------------------------------------

/**
 * The piece type of the current player
 */
PieceType currentPlayer;

/**
 * The marker that tells if the game is finished
 */
extern bool endOfGameMarker;

// MAIN FUNCTIONS ------------------------------------------------------------------------------------------------------

void PlayerManager_init (void)
{
    currentPlayer = CROSS;
	assert (SDL_WasInit (SDL_INIT_VIDEO) != 0);
}

void PlayerManager_free (void)
{
}

static bool tryMove (int x, int y)
{

    // Check the coordinates validity
    if (x >= 0 && x < 3 && y >= 0 && y < 3) {
        // If the square is available, put the piece
        if (Board_putPiece(x, y, currentPlayer) == PIECE_IN_PLACE) {
            return true;
        }
        // Else, display the error message
        else {
            BoardView_sayCannotPutPiece();
            return false;
        }
    }
    }

void PlayerManager_oneTurn (void)
{
	int error;
	SDL_Event event;
	bool validMove;

    // Mouse coordinates
    int mouseX, mouseY;
    
    // Display who is about to play
    BoardView_displayPlayersTurn(currentPlayer);
    BoardView_displayAll();

	do
	{
        // Wait for an event
        error = SDL_WaitEvent (&event);
        
        // If there is no event, abord the program
        assert (error == 1);
        
        // Init validMove
		validMove = false;
        
        // Act regarding the event type
		switch (event.type)
		{
            // In case of window interaction
			case SDL_WINDOWEVENT:
                // If the player ask to close the window
				if (event.window.event == SDL_WINDOWEVENT_CLOSE) {
					validMove = true;     
					endOfGameMarker = true;
				}
				break;
                
            // In case of mouse click interaction
            case SDL_MOUSEBUTTONDOWN:
                
                // Get the mouse click position
				SDL_GetMouseState(&mouseX, &mouseY);
                
                // Transform coordinates
				mouseX = mouseX / 158;
				mouseY = mouseY / 158;
                
                // Check if the move is valid or not
				validMove = tryMove(mouseX, mouseY);
                
                // Display the board
				BoardView_displayAll();
				break;
		}
	}
	while (!validMove);

    // Switch to the next player
	switch (currentPlayer) {
        case CROSS : currentPlayer = CIRCLE; break;
        case CIRCLE : currentPlayer = CROSS; break;
	}
}

#endif // defined CONFIG_PLAYER_MANAGER_SCANF
