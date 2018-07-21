#pragma once

#ifndef _NAMED_TEXTURE_HEADER
#define _NAMED_TEXTURE_HEADER

typedef struct NamedTexture
{
	const char* m_textureName;
	struct SDL_Texture* m_texture;
	struct SDL_Rect m_textureRect;
} BlazBlueCharacter, MiscTexture;

#endif // !_BLAZBLUECHARACTER_HEADER

