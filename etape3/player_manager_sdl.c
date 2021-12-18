/**
 * @file player_manager_scanf.c
 *
 * @date 7 oct. 2016
 * @author jilias
 */

#include "../etape1/board.h"
#include "../etape1/board_view.h"
#include <assert.h>
#include <SDL.h>
#include <stdbool.h>

#if defined CONFIG_PLAYER_MANAGER_SDL

PieceType current_player;
extern bool endOfGameMarker;


void PlayerManager_init (void)
{
    current_player = CROSS;
	assert (SDL_WasInit (SDL_INIT_VIDEO) != 0);
}

void PlayerManager_free (void)
{
}

static bool tryMove (int x, int y)
{

  // TODO: à compléter
  if (x >= 0 && x < 3 && y >= 0 && y < 3) {// Check if coordinate are valid
		//if the square is empty
		if (Board_putPiece(x, y, thisPlayer) == PIECE_IN_PLACE) {
			return true;
		}
        else {
			BoardView_sayCannotPutPiece();//else display msg
			return false;
		}
	}
}

void PlayerManager_oneTurn (void)
{
	int error;
	SDL_Event event;
	bool validMove;
    
    int mouse_x, mouse_y;
    
    // Display who is about to play
    BoardView_display_PlayersTurn(current_player);
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
				SDL_GetMouseState(&xMouse, &yMouse);
                
                // Transform coordinates
				xMouse = xMouse / 158;
				yMouse = yMouse / 158;
                
                // Check if the move is valid or not
				validMove = tryMove(xMouse, yMouse);
                
                // Display the board
				BoardView_displayAll();
				break;
		}
	}
	while (!validMove);
}

#endif // defined CONFIG_PLAYER_MANAGER_SCANF
