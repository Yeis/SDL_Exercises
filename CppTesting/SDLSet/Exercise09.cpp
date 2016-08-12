//#include <SDL.h>
//#include <SDL_image.h>
//#include <stdio.h>
//#include <string>
//
////constatnts
//const int SCREEN_WIDTH = 640;
//const int SCREEN_HEIGHT = 480;
//
////variables 
//SDL_Texture* gTexture = NULL;
//SDL_Window* gWindow = NULL;
//SDL_Renderer* gRenderer = NULL;
//
//
////functions
//
//bool Init();
//bool loadMedia();
//void Close();
//SDL_Texture* loadTexture (std::string path);
//
//
//
//
//
//bool Init()
//{
//	bool success = true;
//
//	if (SDL_Init(SDL_INIT_VIDEO ) <  0)
//	{
//		printf("SDL could not initialize! SDL Error: %s\n", SDL_GetError());
//		success = false;
//	}
//	else 
//	{
//		if (!SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "1"))
//		{
//			printf("Warning: Linear texture filtering not enabled!");
//		}
//		//create window 
//
//		gWindow = SDL_CreateWindow("Exercise 09", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
//		if (gWindow == NULL)
//		{
//			printf("Window could not be created! SDL Error: %s\n", SDL_GetError());
//			success = false;
//		}
//		else 
//		{
//			//create renderer
//			gRenderer = SDL_CreateRenderer(gWindow, -1, SDL_RENDERER_ACCELERATED);
//			if (gRenderer == NULL)
//			{
//				printf("Renderer could not be created! SDL Error: %s\n", SDL_GetError());
//				success = false;
//			}
//			else 
//			{
//				//Initialize renderer color
//				SDL_SetRenderDrawColor(gRenderer, 0xFF, 0xFF, 0xFF, 0xFF);
//
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
//	SDL_DestroyTexture(gTexture);
//	SDL_DestroyWindow(gWindow);
//	SDL_DestroyRenderer(gRenderer);
//	gRenderer = NULL;
//	gTexture = NULL;
//	gWindow = NULL;
//
//	IMG_Quit();
//	SDL_Quit();
//}
//
//SDL_Texture* loadTexture(std::string path) 
//{
//
//	SDL_Texture* newTexture = NULL;
//	SDL_Surface* loadedImage = IMG_Load(path.c_str());
//	if (loadedImage == NULL)
//	{
//		printf("Unable to load image %s! SDL_image Error: %s\n", path.c_str(), IMG_GetError());
//	}
//	else 
//	{
//		newTexture = SDL_CreateTextureFromSurface(gRenderer, loadedImage);
//		if (newTexture == NULL)
//		{
//			printf("Unable to create texture from %s! SDL Error: %s\n", path.c_str(), SDL_GetError());
//		}
//		SDL_FreeSurface(loadedImage);
//	}
//	return newTexture;
//}
//
//
//bool loadMedia() 
//{
//	bool success = true;
//	
//	gTexture = loadTexture("C://Users/Admin/Documents/SDL/CppTesting/SDLSet/Images/viewport.png");
//		if (gTexture == NULL)
//		{
//			printf("Failed to load texture image!\n");
//			success = false;
//		}
//
//	return success;
//}
//
//int main(int argc, char* args[]) 
//{
//
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
//			while (!quit)
//			{
//				while (SDL_PollEvent(&e) != 0 )
//				{
//					if (e.type == SDL_QUIT)
//					{
//						quit = true; 
//					}
//				}
//				//Clear screen
//				SDL_SetRenderDrawColor(gRenderer, 0xFF, 0xFF, 0xFF, 0xFF);
//				SDL_RenderClear(gRenderer);
//				 
//				//top left viewport
//				SDL_Rect topleftViewPort;
//				topleftViewPort.x = 0;
//				topleftViewPort.y = 0;
//				topleftViewPort.w = SCREEN_WIDTH / 2;
//				topleftViewPort.h = SCREEN_HEIGHT / 2;
//				SDL_RenderSetViewport(gRenderer, &topleftViewPort);
//
//				SDL_RenderCopy(gRenderer, gTexture, NULL, NULL);
//
//				//top right viewport
//				SDL_Rect topRIghtViewPport;
//				topRIghtViewPport.x = SCREEN_WIDTH / 2;
//				topRIghtViewPport.y = 0;
//				topRIghtViewPport.w = SCREEN_WIDTH /2;
//				topRIghtViewPport.h = SCREEN_HEIGHT / 2;
//				SDL_RenderSetViewport(gRenderer, &topRIghtViewPport);
//
//				SDL_RenderCopy(gRenderer, gTexture, NULL, NULL);
//
//
//				//Buttom viewport
//				SDL_Rect buttomViewPort;
//				buttomViewPort.x = 0;
//				buttomViewPort.y = SCREEN_HEIGHT / 2 ;
//				buttomViewPort.w = SCREEN_WIDTH ;
//				buttomViewPort.h = SCREEN_HEIGHT / 2;
//				SDL_RenderSetViewport(gRenderer, &buttomViewPort);
//
//				SDL_RenderCopy(gRenderer, gTexture, NULL, NULL);
//			
//				SDL_RenderPresent(gRenderer);
//
//
//
//			}
//		}
//	}
//
//	int error;
//	scanf_s("%d", &error);
//	Close();
//	return 0;
//}
