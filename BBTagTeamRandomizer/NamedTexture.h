#pragma once

#include <string>

#ifndef _NAMED_TEXTURE_HEADER
#define _NAMED_TEXTURE_HEADER

typedef struct NamedTexture
{
	const char* m_textureName;
	struct SDL_Texture* m_texture;
	struct SDL_Rect m_textureRect;
} BlazBlueCharacter, MiscTexture;

bool LoadPNGFiles(const char* pathPrefix, const char* fileNamesWithoutExtention[], size_t numTexturesToLoad, NamedTexture controlledTexture[], SDL_Renderer** windowRenderer)
{
	bool success = true;

	const char* loadedMsg = " loaded!";
	SDL_Surface* currentImgSurf;

	for (int i = 0; i < numTexturesToLoad; i++)
	{
		controlledTexture[i].m_textureName = fileNamesWithoutExtention[i];
		/* Builds the path to the image. */
		std::string currentPathString = pathPrefix;
		currentPathString += fileNamesWithoutExtention[i];
		currentPathString += ".png";

		/* Loads the icon */
		currentImgSurf = IMG_Load(currentPathString.c_str());
		if (currentImgSurf == nullptr)
		{
			DebugSDLIMGError();
			continue;
		}
		else
		{
			/* Set the current char icon */
			controlledTexture[i].m_texture = SDL_CreateTextureFromSurface(*windowRenderer, currentImgSurf);

			/* If the surface was not successfully converted, set error message */
			if (controlledTexture[i].m_texture == nullptr)
			{
				DebugSDLError();
				success = false;
				continue;
			}
			/* Set the character icon rect's size */
			controlledTexture[i].m_textureRect = { 0, 0, currentImgSurf->w, currentImgSurf->h };
			/* When finished free surf from memory. */
			SDL_FreeSurface(currentImgSurf);
			currentPathString += loadedMsg;
			DebugVerbose(currentPathString.c_str());
		}
	}

	return success;
}

#endif // !_BLAZBLUECHARACTER_HEADER

