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
//
//bool loadMedia() 
//{
//	//nothing to load or render 
//	bool success = true;
//	return success;
//}
//
//bool Init() 
//{
//	bool success = true;
//
//	if (SDL_Init(SDL_INIT_VIDEO) <  0 )
//	{
//		printf("SDL could not initialize! SDL Error: %s\n", SDL_GetError());
//		success = false;
//	}
//	else
//	{
//		//set texture filtering to linear 
//		if (!SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "1"))
//		{
//			printf("Warning: Linear texture filtering not enabled!");
//		}
//		//Create window 
//		gWindow = SDL_CreateWindow("Exercise08",SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,SCREEN_WIDTH , SCREEN_HEIGHT, SDL_WINDOWEVENT_SHOWN);
//		if (gWindow == NULL)
//		{
//			printf("Window could not be created! SDL Error: %s\n", SDL_GetError());
//			success = false;
//		}
//		else 
//		{
//			gRenderer = SDL_CreateRenderer(gWindow, -1, SDL_RENDERER_ACCELERATED);
//			if (gRenderer == NULL)
//			{
//				printf("Renderer could not be created! SDL Error: %s\n", SDL_GetError());
//				success = false;
//			}
//			else 
//			{
//				//Initialize Render Color 
//				SDL_SetRenderDrawColor(gRenderer, 0xFF, 0xFF, 0xFF, 0xFF);
//				//Initialize PNG loading
//				int imgFlags = IMG_INIT_PNG;
//				if (!(IMG_Init(imgFlags) & imgFlags))
//				{
//					printf("SDL_image could not initialize! SDL_image Error: %s\n", IMG_GetError());
//					success = false;
//				}
//			}
//		}
//	}
//	
//	return success;
//}
//
//void Close() 
//{
//	SDL_DestroyRenderer(gRenderer);
//	SDL_DestroyWindow(gWindow);
//	gWindow = NULL;
//	gRenderer = NULL;
//
//	IMG_Quit();
//	SDL_Quit();
//}
//
//SDL_Texture* loadTexture(std::string path) 
//{
//	SDL_Texture* newTexture = NULL;
//
//
//	SDL_Surface* loadedsurface = IMG_Load(path.c_str());
//	if (loadedsurface == NULL)
//	{
//		printf("Unable to load image %s! SDL_image Error: %s\n", path.c_str(), IMG_GetError());
//	}
//	else 
//	{
//		//Create texture from surface pixels
//		newTexture = SDL_CreateTextureFromSurface(gRenderer, loadedsurface);
//		if (newTexture == NULL)
//		{
//			printf("Unable to create texture from %s! SDL Error: %s\n", path.c_str(), SDL_GetError());
//
//		}
//		SDL_FreeSurface(loadedsurface);
//	}
//	return newTexture;
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
//		}
//		else 
//		{
//			bool quit = false;
//			SDL_Event e;
//
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
//				//Clear Screen
//				SDL_SetRenderDrawColor(gRenderer, 0xFF, 0xFF, 0xFF, 0xFF);
//				SDL_RenderClear(gRenderer);
//
//				//Render red rectangle
//				SDL_Rect fillRect = {SCREEN_WIDTH/4, SCREEN_HEIGHT/4 , SCREEN_WIDTH /2 , SCREEN_HEIGHT/2};
//				SDL_SetRenderDrawColor(gRenderer,0xFF , 0x00,0x00,0xFF);
//				SDL_RenderFillRect(gRenderer, &fillRect);
//
//
//				//Render green line outline rectangle
//				SDL_Rect outlineRect = {SCREEN_WIDTH / 6  , SCREEN_HEIGHT / 6 , SCREEN_WIDTH * 2  / 3 , SCREEN_HEIGHT * 2 / 3};
//				SDL_SetRenderDrawColor(gRenderer ,0x00,0xFF ,0x00 ,0x00);
//				SDL_RenderDrawRect(gRenderer ,&outlineRect);
//
//
//				//Draw Blue line
//				SDL_SetRenderDrawColor(gRenderer, 0x00, 0x00, 0xFF, 0x00);
//				SDL_RenderDrawLine(gRenderer, 0, SCREEN_HEIGHT / 2  ,  SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2);
//
//
//
//				SDL_RenderPresent(gRenderer);
//			}
//		}
//	}
//	Close();
//	return 0;
//}