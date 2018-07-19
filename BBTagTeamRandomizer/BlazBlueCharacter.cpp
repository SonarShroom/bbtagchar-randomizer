#include "BlazBlueCharacter.h"

#include <SDL.h>

BlazBlueCharacter::BlazBlueCharacter(){ }


BlazBlueCharacter::~BlazBlueCharacter()
{
	if (characterIcon != nullptr)
	{
		SDL_DestroyTexture(characterIcon);
	}
}


void BlazBlueCharacter::SetCharName(char* charName) { characterName = charName; }
char* BlazBlueCharacter::GetCharName() const { return characterName; }

void BlazBlueCharacter::SetCharIcon(SDL_Texture* charIcon) { characterIcon = charIcon; }
SDL_Texture* BlazBlueCharacter::GetCharIcon() const { return characterIcon; }
