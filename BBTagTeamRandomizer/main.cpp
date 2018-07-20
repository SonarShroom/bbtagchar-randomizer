#include <stdio.h>
#include <string>

#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>

#include "BlazBlueCharacter.h"

/* Generic error message macros */
#define DebugSDLError() printf("SDL2 Error: %s\n", SDL_GetError())
#define DebugSDLIMGError() printf("SDL IMG Error: %s\n", IMG_GetError())
#define DebugSDLTTFError() printf("SDL IMG Error: %s\n", TTF_GetError())

#define DebugVerbose(msg) printf(msg); printf("\n")

void LoadResources(unsigned int short const charsInGame, BBTagChar* charArr, SDL_Renderer** windowRenderer)
{
	bool fullSuccess = true;
	/* Set all character names */
	const char* charNames[31] =
	{
		"Ragna",
		"Jin",
		"Noel",
		"Rachel",
		"Hazama",
		"Tager",
		"Nu",
		"Makoto",
		"Azrael",
		"Es",
		"Platinum",
		"Jubei",
		"Hakumen",
		"Yu",
		"Yosuke",
		"Chie",
		"Yukiko",
		"Kanji",
		"Aegis",
		"Naoto",
		"Hyde",
		"Linne",
		"Waldstein",
		"Gordeau",
		"Orie",
		"Carmine",
		"Vatista",
		"Ruby",
		"Weiss",
		"Blake",
		"Yang"
	};
	const char* pathPrefix = "char_icons/", *imgType = ".png", *loadedMsg = " loaded!";

	SDL_Surface* currentImgSurf;

	for (int i = 0; i < charsInGame; i++)
	{
		charArr[i].characterName = charNames[i];
		/* Builds the path to the image. */
		std::string currentPathString = pathPrefix;
		currentPathString += charNames[i];
		currentPathString += imgType;

		/* Loads the icon */
		currentImgSurf = IMG_Load(currentPathString.c_str());
		if (currentImgSurf == nullptr)
		{
			DebugSDLIMGError();
		}
		else
		{
			/* Set the current char icon */
			charArr[i].characterIcon = SDL_CreateTextureFromSurface(*windowRenderer, currentImgSurf);
			/* If the surface was not successfully converted, set error message */
			if (charArr[i].characterIcon == nullptr)
			{
				DebugSDLError();
			}
			/* When finished free surf from memory. */
			SDL_FreeSurface(currentImgSurf);
			currentPathString += loadedMsg;
			DebugVerbose(currentPathString.c_str());
		}
	}
}

int main(int argc, char* args[])
{
	//Try init all SDL subsystems.
	if (SDL_Init(SDL_INIT_EVERYTHING) < 0)
	{
		DebugSDLError();
		return -1;
	}
	else if (IMG_Init(IMG_INIT_PNG) < 0)
	{
		DebugSDLIMGError();
		return -1;
	}
	else if (TTF_Init() < 0)
	{
		DebugSDLTTFError();
		return -1;
	}
	
	//Allocate mem for all bbtag chars.
	const unsigned short int CHARS_IN_GAME = 31;
	BBTagChar bbtagCharacters[CHARS_IN_GAME];

	//SDL window to be created
	SDL_Window* mainWindow;
	SDL_Renderer* mainWindowRenderer;

	/* Create window and renderer */
	SDL_CreateWindowAndRenderer(640, 480, SDL_WINDOW_RESIZABLE | SDL_WINDOW_BORDERLESS, &mainWindow, &mainWindowRenderer);

	/* Loads resources to be used. */
	LoadResources(CHARS_IN_GAME, bbtagCharacters, &mainWindowRenderer);

	bool csgoLootBoxSimulatorIsRunning = true;

	while (csgoLootBoxSimulatorIsRunning)
	{

	}
}