///*This source code copyrighted by Lazy Foo' Productions (2004-2015)
//and may not be redistributed without written permission.*/
//
////Using SDL and standard IO
//#include <SDL.h>
//#include <stdio.h>
//#include <string>
////Screen dimension constants
//const int SCREEN_WIDTH = 640;
//const int SCREEN_HEIGHT = 480;
//
////Starts up SDL and creates window
//bool init();
//
////Loads media
//bool loadMedia();
//
////Frees media and shuts down SDL
//void close();
//
////The window we'll be rendering to
//SDL_Window* gWindow = NULL;
//
////The surface contained by the window
//SDL_Surface* gScreenSurface = NULL;
//
////The image we will load and show on the screen
//SDL_Surface* gHelloWorld = NULL;
//
//
////EXERCICE 04 KEY PRESS 
//
//SDL_Surface* loadSurface(std::string path);
//
//
//
////Current displayed image
//SDL_Surface* gCurrentSurface = NULL;
//
//enum KeyPressSurfaces 
//{
//	KEY_PRESS_SURFACE_DEFAULT,
//	KEY_PRESS_SURFACE_UP,
//	KEY_PRESS_SURFACE_LEFT,
//	KEY_PRESS_SURFACE_RIGHT,
//	KEY_PRESS_SURFACE_DOWN,
//	KEY_PRESS_SURFACE_TOTAL
//
//
//};
////The images that correspond to a keypress
//SDL_Surface* gKeyPressSurfaces[KEY_PRESS_SURFACE_TOTAL];
//
//
//SDL_Surface* loadSurface(std::string path) 
//{
//	//load image at specified path 
//	SDL_Surface* loadedSurface = SDL_LoadBMP(path.c_str());
//	if (loadedSurface == NULL)
//	{
//		printf("Unable to load the image! %s \n",SDL_GetError());
//	}
//	return loadedSurface;
//}
//
//
//
//bool init()
//{
//	//Initialization flag
//	bool success = true;
//
//	//Initialize SDL
//	if (SDL_Init(SDL_INIT_VIDEO) < 0)
//	{
//		printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
//		success = false;
//	}
//	else
//	{
//		//Create window
//		gWindow = SDL_CreateWindow("SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
//		if (gWindow == NULL)
//		{
//			printf("Window could not be created! SDL_Error: %s\n", SDL_GetError());
//			success = false;
//		}
//		else
//		{
//			//Get window surface
//			gScreenSurface = SDL_GetWindowSurface(gWindow);
//		}
//	}
//
//	return success;
//}
//
//bool loadMedia()
//{
//	//Loading success flag
//	bool success = true;
//
//	//Load splash image
//	//gHelloWorld = SDL_LoadBMP("c://hello_world.bmp");
//	gKeyPressSurfaces[KEY_PRESS_SURFACE_DEFAULT] = loadSurface("c://Users/Yeis/Documents/SDL_Exercises/CppTesting/SDLSet/Images/press.bmp");
//	if (gKeyPressSurfaces[KEY_PRESS_SURFACE_DEFAULT] == NULL)
//	{
//		printf("Failed to load default image!\n");
//		success = false;
//	}
//	//Load up surface
//	gKeyPressSurfaces[KEY_PRESS_SURFACE_UP] = loadSurface("c://Users/Yeis/Documents/SDL_Exercises/CppTesting/SDLSet/Images/up.bmp");
//	if (gKeyPressSurfaces[KEY_PRESS_SURFACE_UP] == NULL)
//	{
//		printf("Failed to load up image!\n");
//		success = false;
//	}
//
//	//Load down surface
//	gKeyPressSurfaces[KEY_PRESS_SURFACE_DOWN] = loadSurface("c://Users/Yeis/Documents/SDL_Exercises/CppTesting/SDLSet/Images/down.bmp");
//	if (gKeyPressSurfaces[KEY_PRESS_SURFACE_DOWN] == NULL)
//	{
//		printf("Failed to load down image!\n");
//		success = false;
//	}
//
//	//Load left surface
//	gKeyPressSurfaces[KEY_PRESS_SURFACE_LEFT] = loadSurface("c://Users/Yeis/Documents/SDL_Exercises/CppTesting/SDLSet/Images/left.bmp");
//	if (gKeyPressSurfaces[KEY_PRESS_SURFACE_LEFT] == NULL)
//	{
//		printf("Failed to load left image!\n");
//		success = false;
//	}
//
//	//Load right surface
//	gKeyPressSurfaces[KEY_PRESS_SURFACE_RIGHT] = loadSurface("c://Users/Yeis/Documents/SDL_Exercises/CppTesting/SDLSet/Images/right.bmp");
//	if (gKeyPressSurfaces[KEY_PRESS_SURFACE_RIGHT] == NULL)
//	{
//		printf("Failed to load right image!\n");
//		success = false;
//	}
//
//	return success;
//}
//
//void close()
//{
//
//
//	//Deallocate Surfaces 
//	for (int i = 0; i < KEY_PRESS_SURFACE_TOTAL; ++i)
//	{
//		SDL_FreeSurface(gKeyPressSurfaces[i]);
//		gKeyPressSurfaces[i] = NULL;
//	}
//
//	//Deallocate surface
//	SDL_FreeSurface(gHelloWorld);
//	gHelloWorld = NULL;
//
//	//Destroy window
//	SDL_DestroyWindow(gWindow);
//	gWindow = NULL;
//
//	//Quit SDL subsystems
//	SDL_Quit();
//}
//
//int main(int argc, char* args[])
//{
//
//
//
//	//Start up SDL and create window
//	if (!init())
//	{
//
//		printf("Failed to initialize!\n");
//	}
//	else
//	{
//		//Load media
//		if (!loadMedia())
//		{
//
//			printf("Failed to load media!\n");
//		}
//		else
//		{
//			// MAIN PART OF EXERCISE 03 
//			// SDL Event Handler 
//			SDL_Event e;
//
//			bool quit = false;
//
//			gCurrentSurface = gKeyPressSurfaces[KEY_PRESS_SURFACE_DEFAULT];
//
//
//			while (!quit)
//			{
//				while (SDL_PollEvent(&e) != 0 )
//				{
//					//user press quit
//					if (e.type == SDL_QUIT)
//					{
//						quit = true;
//					}
//					//user press a key button
//					else if (e.type == SDL_KEYDOWN) 
//					{
//						//CHange image depending on button pressed 
//						switch (e.key.keysym.sym)
//						{
//						case SDLK_UP:
//							gCurrentSurface = gKeyPressSurfaces[KEY_PRESS_SURFACE_UP];
//							break;
//						case SDLK_DOWN:
//							gCurrentSurface = gKeyPressSurfaces[KEY_PRESS_SURFACE_DOWN];
//							break;
//						case SDLK_RIGHT:
//							gCurrentSurface = gKeyPressSurfaces[KEY_PRESS_SURFACE_RIGHT];
//							break;
//						case SDLK_LEFT:
//							gCurrentSurface = gKeyPressSurfaces[KEY_PRESS_SURFACE_LEFT];
//							break;
//
//						default:
//							gCurrentSurface = gKeyPressSurfaces[KEY_PRESS_SURFACE_DEFAULT];
//							break;
//						}
//					}
//
//					//Apply the image
//					SDL_BlitSurface(gCurrentSurface, NULL, gScreenSurface, NULL);
//
//					//Update the surface
//					SDL_UpdateWindowSurface(gWindow);
//
//				}
//			}
//
//
//			
//			//Wait two seconds
//		}
//	}
//
//	//Free resources and close SDL
//	close();
//
//	return 0;
//}