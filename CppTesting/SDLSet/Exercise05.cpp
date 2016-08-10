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
//
//
//
////EXERCICE 04 KEY PRESS 
//
//SDL_Surface* loadSurface(std::string path);
//
//
//
////Current displayed image
//SDL_Surface* gStretchedSurface = NULL;
//
//
//SDL_Surface* loadSurface(std::string path)
//{
//	//load image at specified path 
//	SDL_Surface* optimizedSurface = NULL;
//
//	SDL_Surface* loadedSurface = SDL_LoadBMP(path.c_str());
//	if (loadedSurface == NULL)
//	{
//		printf("Unable to load the image! %s \n", SDL_GetError());
//	}
//	else 
//	{
//		//convert surface to screen format 
//		optimizedSurface = SDL_ConvertSurface(loadedSurface, gScreenSurface->format, NULL);
//		if (optimizedSurface == NULL)
//		{
//			printf("Unable to optimized image! %s  \n",SDL_GetError());
//		}
//		//get rid of oldsurface 
//		SDL_FreeSurface(loadedSurface);
//
//	}
//	return optimizedSurface;
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
//	//Load stretching surface
//	gStretchedSurface = loadSurface("c://Users/Yeis/Documents/SDL_Exercises/CppTesting/SDLSet/Images/stretch.bmp");
//	if (gStretchedSurface == NULL)
//	{
//		printf("Failed to load stretching image!\n");
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
//
//
//	//Deallocate surface
//	SDL_FreeSurface(gStretchedSurface);
//	gStretchedSurface = NULL;
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
//		
//
//
//			while (!quit)
//			{
//				while (SDL_PollEvent(&e) != 0)
//				{
//					//user press quit
//					if (e.type == SDL_QUIT)
//					{
//						quit = true;
//					}
//				
//					SDL_Rect stretchRect;
//					stretchRect.x = 0;
//					stretchRect.y = 0;
//					stretchRect.w = SCREEN_WIDTH;
//					stretchRect.h = SCREEN_HEIGHT;
//					//Apply the image
//					SDL_BlitSurface(gStretchedSurface, NULL, gScreenSurface, NULL);
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