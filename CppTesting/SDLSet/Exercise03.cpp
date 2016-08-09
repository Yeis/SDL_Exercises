#include <SDL.h>
#include <stdio.h>

//The window we'll be rendering to
SDL_Window* gWindow = NULL;

//The surface contained by the window
SDL_Surface* gScreenSurface = NULL;

//The image we will load and show on the screen
SDL_Surface* gHelloWorld = NULL;

// SDL Event Handler 
SDL_Event e;

bool quit = false;
