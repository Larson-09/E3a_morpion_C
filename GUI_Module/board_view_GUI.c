/**
 * @file board_view.c
 *
 * @date 19/12/2021
 * @author Hugo BURY and Jordan LAUDE
 */

#include "board_view_GUI.h"
#include <assert.h>
#include <stdio.h>
#include <SDL.h>
#include <SDL_image.h>
#include "tictactoe_errors.h"

#if defined CONFIG_SDLUI

// GLOBAL VARIABLES ----------------------------------------------------------------------------------------------------

static SDL_Window *MainWindow;

static SDL_Renderer *MainRenderer;

static SDL_Surface *BackgroundImage;
static SDL_Surface *SpriteO;
static SDL_Surface *SpriteX;
static SDL_Surface *SpriteCrossWins;
static SDL_Surface *SpriteCircleWins;
static SDL_Surface *SpriteDraw;
static SDL_Surface *SpriteCrossTurn;
static SDL_Surface *SpriteCircleTurn;
static SDL_Surface *SpriteCannotPutPiece;

// FUNCTIONS -----------------------------------------------------------------------------------------------------------

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
		BackgroundImage = IMG_Load ("../images/sprite_background.png");
		if (BackgroundImage == NULL)
					fatalError(IMG_GetError ());

		SpriteO = IMG_Load ("../images/sprite_circle.png");
		if (SpriteO == NULL)
					fatalError(IMG_GetError ());

		SpriteX = IMG_Load ("../images/sprite_cross.png");
		if (SpriteX == NULL)
			fatalError(IMG_GetError ());

        SpriteCrossWins= IMG_Load ("../images/sprite_crossWins.png");
		if (SpriteX == NULL)
			fatalError(IMG_GetError ());

        SpriteCircleWins= IMG_Load ("../images/sprite_circleWins.png");
		if (SpriteX == NULL)
			fatalError(IMG_GetError ());

        SpriteDraw= IMG_Load ("../images/sprite_draw.png");
		if (SpriteX == NULL)
			fatalError(IMG_GetError ());

        SpriteCrossTurn = IMG_Load ("../images/sprite_crossTurn.png");
		if (SpriteX == NULL)
			fatalError(IMG_GetError ());

        SpriteCircleTurn = IMG_Load ("../images/sprite_circleTurn.png");
		if (SpriteX == NULL)
			fatalError(IMG_GetError ());

        SpriteCannotPutPiece = IMG_Load ("../images/sprite_cannotPutPiece.png");
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

void BoardView_displayAll (void)
{
    PieceType pieceToDisplay = NONE;
	renderImage(BackgroundImage, 0, 0);

	for (int i = 0; i < 4; ++i) {
		for (int j = 0; j < 4; ++j) {
			pieceToDisplay = Board_getSquareContent(i, j);
			BoardView_displaySquare(j, i, pieceToDisplay);
			SDL_Delay(10);
		}
	}
}

void BoardView_displaySquare (Coordinate x, Coordinate y, PieceType kindOfPiece)
{
    // Precondition
    if (x < 0 || x > 2 || y < 0 || y > 2)
        perror("X and Y must be contained between 0 and 2");

    if (kindOfPiece != CROSS && kindOfPiece != CIRCLE)
        perror("kindOfPiece must be CROSS or CIRCLE");

    // Adapt coordinates
    int displayX, displayY;
    int coord0 = 35;
    int coord1 = 195;
    int coord2 = 355;

    switch(x){
        case 0 : displayX = coord0 ; break ;
        case 1 : displayX = coord1 ; break ;
        case 2 : displayX = coord2 ; break ;
    }

    switch(y){
        case 0 : displayY = coord0 ; break ;
        case 1 : displayY = coord1 ; break ;
        case 2 : displayY = coord2 ; break ;
    }

    switch (kindOfPiece) {
        case CROSS : renderImage(SpriteX, displayY, displayX); break ;
        case CIRCLE : renderImage(SpriteO, displayY, displayX); break ;
    }
}

void BoardView_displayPlayersTurn (PieceType thisPlayer)
{
    switch (thisPlayer) {
        case CROSS: renderImage(SpriteCrossTurn, 0, 0); break;
        case CIRCLE: renderImage(SpriteCircleTurn, 0, 0); break;
    }

	SDL_Delay(2000);
}

void BoardView_displayEndOfGame (GameResult result)
{
    // Precondition
    if (result != CROSS_WINS && result != CIRCLE_WINS)
        perror("kindOfPiece must be CROSS or CIRCLE");

    // Display Result
    switch (result) {
        case CROSS_WINS: renderImage(SpriteCrossWins, 0, 0); break;
        case CIRCLE_WINS: renderImage(SpriteCircleWins, 0, 0); break;
        case DRAW: renderImage(SpriteDraw, 0, 0); break;
    }

    SDL_Delay(5000);
}

void BoardView_sayCannotPutPiece (void)
{
    renderImage(SpriteCannotPutPiece, 0, 0);
	SDL_Delay(2000);
}

#endif // defined CONFIG_SDLUI
