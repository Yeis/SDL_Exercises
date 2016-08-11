//
//
//#include <SDL.h>
//#include <SDL_image.h>
//#include <stdio.h>
//#include <string>
//#include <cmath>
//#include <cstdio>
//#include <vector>
//#include <iostream>
//#include <algorithm>
//
//
//
////My screen dimensions
//const int SCREEN_WIDTH = 640;
//const int SCREEN_HEIGHT = 480;
//
//
////Declaration of functions 
//void Close();
//bool Init();
//bool loadMedia();
//
////new function of exercise 7  that loads a texture 
//SDL_Texture* loadTexture(std::string path);
//
////window to be rendered
//SDL_Window* gWindow = NULL;
//
////The renderer 
//SDL_Renderer* gRenderer = NULL;
//
////Current displayed texture 
//SDL_Texture* gTexture = NULL;
//
//std::string error;
////Functions 
//
//bool Init() 
//{
//	bool success = true;
//	gWindow = SDL_CreateWindow("Execise07", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
//	if (gWindow == NULL)
//	{
//		printf("Could not create the window! %s \n", SDL_GetError());
//		success = false;
//		scanf_s("%s",error);
//	}
//	else 
//	{
//		//Create Renderer
//		gRenderer = SDL_CreateRenderer(gWindow, -1, SDL_RENDERER_ACCELERATED);
//		if (gRenderer == NULL)
//		{
//			printf("Renderer could not be created! SDL Error: %s\n", SDL_GetError());
//			success = false;
//			scanf_s("%s",error);
//		}
//		else 
//		{
//			//Initialize renderer color
//			SDL_SetRenderDrawColor(gRenderer , 0xFF ,0xFF , 0xFF ,0xFF);
//
//			//initialize png image 
//			int imgFlags = IMG_INIT_PNG;
//			if (!(IMG_Init(imgFlags) &imgFlags))
//			{
//				printf("SDL_image could not initialize! SDL_image Error: %s\n", IMG_GetError());
//				success = false;
//			}
//		}
//	}
//	return success;
//}
//
//
//SDL_Texture* loadTexture(std::string path) 
//{
//	//the final texture 
//	SDL_Texture* newTexture = NULL;
//
//	//load image at specific path 
//	SDL_Surface* loadSurface = IMG_Load(path.c_str());
//	if (loadSurface == NULL)
//	{
//		printf("Unable to load image %s! SDL_image Error: %s\n", path.c_str(), IMG_GetError());
//		scanf_s("%s");
//	}
//	else 
//	{
//		//create texture from surface pixels
//		newTexture = SDL_CreateTextureFromSurface(gRenderer,loadSurface);
//		if (newTexture == NULL)
//		{
//			printf("Unable to create texture from %s! SDL Error: %s\n", path.c_str(), SDL_GetError());
//
//		}
//		//deallocate old loaded surface
//		SDL_FreeSurface(loadSurface);
//		return newTexture;
//
//	}
//
//}
//
//bool loadMedia() 
//{
//	//loading success flag
//	bool success = true;
//
//	//load png texture 
//	gTexture = loadTexture("c://Users/Admin/Documents/SDL/CppTesting/SDLSet/Images/texture.png");
//	if (gTexture == NULL)
//	{
//		printf("Failed to load texture image!\n");
//		success = false;
//	}
//	return success;
//}
//
//void Close() 
//{
//	//free resources 
//	SDL_DestroyTexture(gTexture);
//	gTexture = NULL;
//
//	SDL_DestroyRenderer(gRenderer);
//	gRenderer = NULL;
//
//	SDL_DestroyWindow(gWindow);
//	gWindow = NULL;
//
//	//Quit SDL SubSystems
//	IMG_Quit();
//	SDL_Quit();
//
//}
//
//
//int main(int argc, char* args[]) 
//{
//	if (!Init()) 
//	{
//		printf("Failed to initialize!\n");
//	}
//	else
//	{
//		if (!loadMedia())
//		{
//			printf("Failed to load media!\n");
//
//		}
//		else {
//			bool quit = false;
//			SDL_Event e;
//			while (!quit)
//			{
//				while (SDL_PollEvent(&e) != 0)
//				{
//					if (e.type == SDL_QUIT)
//					{
//						quit = true;
//					}
//				}
//
//				//clear Screen
//				SDL_RenderClear(gRenderer);
//
//				//Render texture to screen
//				SDL_RenderCopy(gRenderer, gTexture, NULL, NULL);
//
//				//Update Screen
//				SDL_RenderPresent(gRenderer);
//			}
//		}
//	}
//	Close();
//
//	return 0;
//
//}