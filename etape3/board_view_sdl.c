/**
 * @file board_view_text.c
 *
 * @date 7 oct. 2016
 * @author jilias
 */

#include "board_view.h"
#include <assert.h>
#include <stdio.h>
#include <SDL.h>
#include <SDL_image.h>
#include "tictactoe_errors.h"

#if defined CONFIG_SDLUI

static SDL_Window *MainWindow;
static SDL_Renderer *MainRenderer;
static SDL_Surface *BackgroundImage;
static SDL_Surface *SpriteO;
static SDL_Surface *SpriteX;

static void renderImage (SDL_Surface *image, int x, int y)
{
	SDL_Texture *aTexture;
	aTexture = SDL_CreateTextureFromSurface(MainRenderer, image);
	assert (aTexture != NULL);
	SDL_Rect pos = {x, y, image->w, image->h};
	SDL_RenderCopy(MainRenderer, aTexture, 0, &pos);
	SDL_RenderPresent(MainRenderer);
	SDL_DestroyTexture(aTexture);
}

void BoardView_init (void)
{
		int result;

		// Initialize SDL
		result = SDL_Init (SDL_INIT_VIDEO);
		if (result != 0)
		{
			fatalError (SDL_GetError ());
		}
		atexit (SDL_Quit);

		// Initialize SDL_image
		int initted=IMG_Init(IMG_INIT_PNG);
		if (initted != IMG_INIT_PNG)
		{
			fatalError(IMG_GetError ());
		}

		// Loads images
		BackgroundImage = IMG_Load ("background.png");
		if (BackgroundImage == NULL)
					fatalError(IMG_GetError ());
		SpriteO = IMG_Load ("sprite_O.png");
		if (SpriteO == NULL)
					fatalError(IMG_GetError ());
		SpriteX = IMG_Load ("sprite_X.png");
		if (SpriteX == NULL)
			fatalError(IMG_GetError ());

		// Creates the window
		MainWindow = SDL_CreateWindow ("Tic Tac Toe", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 480, 480, 0);
		if (MainWindow == NULL)
		{
			fatalError (SDL_GetError ());
		}

		// Creates the main renderer
		MainRenderer = SDL_CreateRenderer(MainWindow, -1, SDL_RENDERER_ACCELERATED);
		if (MainRenderer == NULL)
		{
			fatalError(SDL_GetError());
		}
}

void BoardView_free (void)
{
	SDL_DestroyRenderer(MainRenderer);
	SDL_DestroyWindow(MainWindow);
	SDL_FreeSurface(SpriteX);
	SDL_FreeSurface(SpriteO);
	SDL_FreeSurface(BackgroundImage);
	IMG_Quit ();
	SDL_Quit ();
}

void BoardView_displayAll (void)
{
	/* utiliser "renderImage" pour afficher l'image de fond "BackgroundImage",
	 * puis afficher l'ensemble des cases à l'aide de la fonction BoardView_displaySquare
	 */
}

void BoardView_displaySquare (Coordinate x, Coordinate y, PieceType kindOfPiece)
{
	/* utiliser "renderImage" pour afficher le sprite correspondant à kindOfPiece à
	 * l'endroit correspondant aux coordonnées logiques "x" et "y".
	 */

}

void BoardView_displayEndOfGame (GameResult result)
{
	SDL_Delay (2000); // TODO: vous pouvez améliorer ceci (lorsque le reste fonctionnera)
}

void BoardView_displayPlayersTurn (PieceType thisPlayer)
{
	// TODO: vous pouvez améliorer ceci (lorsque le reste fonctionnera)
}

void BoardView_sayCannotPutPiece (void)
{
	// TODO: vous pouvez améliorer ceci (lorsque le reste fonctionnera)
}

#endif // defined CONFIG_SDLUI
