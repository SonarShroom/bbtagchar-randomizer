#include <stdio.h>

#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>

#include "DebugHelpers.h"
#include "NamedTexture.h"
#include "GUIText.h"

#define CHARS_IN_GAME 31
#define TEXTURES_TO_LOAD 1

enum LootBoxSimulatorMode
{
	MAIN_MENU = 0,
	GENERATING_TEAM,
	SHOWING_TEAM
};



bool LoadCharacters(BlazBlueCharacter charArr[], SDL_Renderer** windowRenderer)
{
	/* Set all character names */
	const char* charNames[CHARS_IN_GAME] =
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

	return LoadPNGFiles("char_icons/", charNames, CHARS_IN_GAME, charArr, windowRenderer);
}

bool LoadGeneralTextures(MiscTexture* generalTextures, SDL_Renderer** windowRenderer)
{
	const char* texturesToLoad[TEXTURES_TO_LOAD] =
	{
		"bbtag_logo"
	};

	return LoadPNGFiles("imgs/", texturesToLoad, TEXTURES_TO_LOAD, generalTextures, windowRenderer);
}

bool LoadResources(BlazBlueCharacter* charArr,
				   MiscTexture* generalTextures,
				   SDL_Renderer** windowRenderer)
{
	return LoadCharacters(charArr, windowRenderer) && 
		   LoadGeneralTextures(generalTextures, windowRenderer);
}

void RenderMenu()
{

}

void GenerateNewTeam(unsigned int charsInGame, BlazBlueCharacter bbtagCharacters[], BlazBlueCharacter* generatedTeam[])
{
	srand(SDL_GetTicks());
	int char0 = rand() % charsInGame, char1 = rand() % charsInGame;
	while (char0 == char1)
	{
		char1 = rand() % charsInGame;
	}
	generatedTeam[0] = &bbtagCharacters[char0];
	generatedTeam[1] = &bbtagCharacters[char1];
}

void RenderTeamGeneration(BlazBlueCharacter* generatedTeam[])
{
	
}

void PollSDLEvents(bool& csgoLootBoxSimulatorIsRunning, LootBoxSimulatorMode& currentMode)
{
	SDL_Event e;

	if (SDL_PollEvent(&e))
	{
		switch (e.type)
		{
			case SDL_QUIT:
				csgoLootBoxSimulatorIsRunning = false;
				break;
			case SDL_EventType::SDL_KEYDOWN:
				switch (e.key.keysym.sym)
				{
					case SDLK_SPACE:
						switch (currentMode)
						{
							case LootBoxSimulatorMode::MAIN_MENU:
								currentMode = LootBoxSimulatorMode::GENERATING_TEAM;
							case LootBoxSimulatorMode::SHOWING_TEAM:
								currentMode = LootBoxSimulatorMode::GENERATING_TEAM;
						}
						break;
					case SDLK_RETURN:
						if (currentMode == LootBoxSimulatorMode::SHOWING_TEAM)
						{
							currentMode = LootBoxSimulatorMode::MAIN_MENU;
						}
						break;
					case SDLK_ESCAPE:
						csgoLootBoxSimulatorIsRunning = false;
						break;
					default:
						break;
				}
			break;
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
	BlazBlueCharacter bbtagCharacters[CHARS_IN_GAME];

	/* The misc textures to load (from imgs folder) */
	MiscTexture miscTextures[TEXTURES_TO_LOAD];

	//SDL window to be created
	SDL_Window* mainWindow;
	SDL_Renderer* mainWindowRenderer;

	/* Create window and renderer */
	SDL_CreateWindowAndRenderer(640, 480, SDL_WINDOW_RESIZABLE, &mainWindow, &mainWindowRenderer);

	/* Loads resources to be used. */
	if (!LoadResources(bbtagCharacters, miscTextures, &mainWindowRenderer))
	{
		DebugVerbose("Could not load some resources!");
		return -1;
	}

	bool csgoLootBoxSimulatorIsRunning = true;
	LootBoxSimulatorMode currentMode = LootBoxSimulatorMode::MAIN_MENU;
	BlazBlueCharacter* generatedTeam[2] = { nullptr, nullptr };

	while (csgoLootBoxSimulatorIsRunning)
	{
		switch (currentMode)
		{
			// This one is not needed rn, due to not showing any animation.
			case LootBoxSimulatorMode::GENERATING_TEAM:
				GenerateNewTeam(CHARS_IN_GAME, bbtagCharacters, generatedTeam);
				currentMode = LootBoxSimulatorMode::SHOWING_TEAM;
				break;
			case LootBoxSimulatorMode::SHOWING_TEAM:
				RenderTeamGeneration(generatedTeam);
				break;
			case LootBoxSimulatorMode::MAIN_MENU:
			default:
				RenderMenu();
				break;
		}
		PollSDLEvents(csgoLootBoxSimulatorIsRunning, currentMode);
	}
}