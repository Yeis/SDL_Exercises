//#include <SDL.h>
//#include <SDL_image.h>
//#include <stdio.h>
//#include <string>
//
////constatnts
//const int SCREEN_WIDTH = 640;
//const int SCREEN_HEIGHT = 480;
//
//
////Texture Wrapper class
//
//class LTexture
//{
//private:
//	SDL_Texture* mTexture;
//	//dimensions
//	int mWidth;
//	int mHeight;
//
//public:
//	//Initializes Variables
//	LTexture();
//
//	//Deallocates Memory
//	~LTexture();
//
//	//load image at specific path
//	bool loadFromFile(std::string path);
//
//	//Deallocates texture 
//	void Free();
//
//	//Renders Texture at given Point
//	void render(int x, int y , SDL_Rect*  clip =  NULL);
//
//	//Get image dimensions
//	int getWidth();
//	int getHeight();
//
//};
//
////variables 
//SDL_Window* gWindow = NULL;
//SDL_Renderer* gRenderer = NULL;
//
//SDL_Rect gSpriteClips[4];
//LTexture gSpriteSheetTexture;
//
//
////functions
//
//bool Init();
//bool loadMedia();
//void Close();
//
//
//
//// LTexture describen fucntions 
//LTexture::LTexture()
//{
//	//Initialize 
//	mTexture = NULL;
//	mWidth = 0;
//	mHeight = 0;
//}
//LTexture::~LTexture()
//{
//	//Deallocate
//	Free();
//}
//void LTexture::Free()
//{
//	//Free texture if exists
//	if (mTexture != NULL)
//	{
//		SDL_DestroyTexture(mTexture);
//		mTexture = NULL;
//		mWidth = 0;
//		mHeight = 0;
//	}
//}
//bool LTexture::loadFromFile(std::string path)
//{
//	bool success = true;
//
//	//get rid of previous texture 
//	Free();
//	//Final texture 
//	SDL_Texture* newTexture = NULL;
//	//load image first 
//	SDL_Surface* loadedImage = IMG_Load(path.c_str());
//	if (loadedImage == NULL)
//	{
//		printf("Unable to load image %s! SDL_image Error: %s\n", path.c_str(), IMG_GetError());
//	}
//	else
//	{
//		//Color key Image 
//		SDL_SetColorKey(loadedImage, SDL_TRUE, SDL_MapRGB(loadedImage->format, 0, 0xFF, 0xFF));
//
//		//Create texture from surface pixels 
//		newTexture = SDL_CreateTextureFromSurface(gRenderer, loadedImage);
//		if (newTexture == NULL)
//		{
//			printf("Unable to create texture from %s! SDL Error: %s\n", path.c_str(), SDL_GetError());
//		}
//		else
//		{
//			//get image dimesions 
//			mWidth = loadedImage->w;
//			mHeight = loadedImage->h;
//		}
//		//get rid of old surface 
//		SDL_FreeSurface(loadedImage);
//	}
//	mTexture = newTexture;
//	return success;
//
//
//}
//void LTexture::render(int x, int y , SDL_Rect* clip )
//{
//	//set rendering space and render to screen 
//	SDL_Rect renderQuad = { x , y ,mWidth,mHeight };
//	//set clip dimensions 
//	if (clip != NULL)
//	{
//		renderQuad.w = clip->w;
//		renderQuad.h = clip->h;
//	}
//	SDL_RenderCopy(gRenderer, mTexture, clip, &renderQuad);
//}
//int LTexture::getHeight()
//{
//	return mHeight;
//}
//int LTexture::getWidth()
//{
//	return mWidth;
//}
//
//
////Program Functions
//
//
//bool Init()
//{
//	bool success = true;
//
//	if (SDL_Init(SDL_INIT_VIDEO) <  0)
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
//		gWindow = SDL_CreateWindow("Exercise 11", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
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
//	//Free loaded IMages 
//	gSpriteSheetTexture.Free();
//	
//	//Destroy Window
//	SDL_DestroyWindow(gWindow);
//	gWindow = NULL;
//	//Destroy Renderer
//	SDL_DestroyRenderer(gRenderer);
//	gRenderer = NULL;
//	//Quit SubSystems
//	IMG_Quit();
//	SDL_Quit();
//}
//bool loadMedia()
//{
//	bool success = true;
//	//load dots texture 
//	if (!gSpriteSheetTexture.loadFromFile("C://Users/Admin/Documents/SDL/CppTesting/SDLSet/Images/dots.png"))
//	{
//		printf("Failed to load Dots' texture image!\n");
//		success = false;
//	}
//	else
//	{
//		//set top left sprite 
//		gSpriteClips[0].x = 0;
//		gSpriteClips[0].y = 0;
//		gSpriteClips[0].w = 100;
//		gSpriteClips[0].h = 100;
//		//set top right sprite 
//		gSpriteClips[1].x = 100;
//		gSpriteClips[1].y = 0;
//		gSpriteClips[1].w = 100;
//		gSpriteClips[1].h = 100;
//		//set bottom left sprite 
//		gSpriteClips[2].x = 0;
//		gSpriteClips[2].y = 100;
//		gSpriteClips[2].w = 100;
//		gSpriteClips[2].h = 100;
//		//set bottom right sprite 
//		gSpriteClips[3].x = 100;
//		gSpriteClips[3].y = 100;
//		gSpriteClips[3].w = 100;
//		gSpriteClips[3].h = 100;
//	}
//
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
//				while (SDL_PollEvent(&e) != 0)
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
//				//render textures 
//				gSpriteSheetTexture.render(0, 0, &gSpriteClips[0]);
//				gSpriteSheetTexture.render(SCREEN_WIDTH - gSpriteClips[1].w, 0, &gSpriteClips[1]);
//				gSpriteSheetTexture.render(0, SCREEN_HEIGHT - gSpriteClips[2].h, &gSpriteClips[2]);
//				gSpriteSheetTexture.render(SCREEN_WIDTH - gSpriteClips[3].w, SCREEN_HEIGHT - gSpriteClips[2].h, &gSpriteClips[3]);
//
//				//update screen 
//				SDL_RenderPresent(gRenderer);
//			}
//		}
//	}
//
//	int error;
//	scanf_s("%d", &error);
//	Close();
//	return 0;
//}
