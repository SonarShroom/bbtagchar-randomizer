#pragma once

#ifndef _DEBUG_HELPERS_HEADER
#define _DEBUG_HELPERS_HEADER

/* Generic error message macros */
#define DebugSDLError() printf("SDL2 Error: %s\n", SDL_GetError())
#define DebugSDLIMGError() printf("SDL IMG Error: %s\n", IMG_GetError())
#define DebugSDLTTFError() printf("SDL IMG Error: %s\n", TTF_GetError())

/* Debugs */
#define DebugVerbose(msg) printf(msg); printf("\n")

#endif // !_DEBUG_HELPERS_HEADER
