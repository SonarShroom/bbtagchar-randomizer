#pragma once

#include <SDL_ttf.h>

#ifndef _GUI_TEXT_HEADER
#define _GUI_TEXT_HEADER

typedef struct GUIText
{
	const char* m_text;
	struct SDL_Texture* m_textTexture;

} TextObject;

void CreateTextObject(const char* text, TTF_Font* font, GUIText* outTextObject)
{

}

#endif // !_GUI_TEXT_HEADER
