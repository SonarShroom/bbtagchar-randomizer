#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>

#include <string.h>

#include "BlazBlueCharacter.h"

int main(int argc, char* args[])
{
	//Try init all SDL subsystems.
	if (SDL_Init(SDL_INIT_EVERYTHING) < 0)
	{
		return -1;
	}
	else if (IMG_Init(IMG_INIT_PNG) < 0)
	{
		return -1;
	}
	else if (TTF_Init() < 0)
	{
		return -1;
	}
	
	//Allocate mem for all bbtag chars.
	const unsigned short int CHARS_IN_GAME = 31;
	BBTagChar bbtagCharacters[CHARS_IN_GAME];

	/* Loads resources to be used. */
	LoadResources(bbtagCharacters, CHARS_IN_GAME);

}

void LoadResources(BBTagChar* charArr, unsigned int short const charsInGame)
{
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
	const char* pathPrefix = "icons/", *imgType = ".png";

	SDL_Surface* currentImgSurf;
	SDL_Texture* currentImage;
	/* TODO: Create SDL_Textures from images */

	for (int i = 0; i < charsInGame; i++)
	{
		/* Builds the path to the image. */
		char* currentPathString = nullptr;
		strcat(currentPathString, pathPrefix);
		strcat(currentPathString, charNames[i]);
		strcat(currentPathString, imgType);

		/* Loads the icon */
		currentImgSurf = IMG_Load(currentPathString);
		if (currentImgSurf != nullptr)
		{
			/* TODO: initialize window, and send renderer towards this function. 
			   then load everything into the structs textures. */
		}
	}
}