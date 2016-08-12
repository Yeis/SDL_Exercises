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
//	//Function for color modulation
//	void setColor(Uint8 red, Uint8 green, Uint8 blue);
//
//	//Function Set Blending
//	void setBlendMode(SDL_BlendMode blending);
//
//	//function that sets Alpha modulatoin
//	void setAlpha(Uint8 alpha);
//
//
//	//Deallocates texture 
//	void Free();
//
//	//Renders Texture at given Point
//	void render(int x, int y, SDL_Rect*  clip = NULL);
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
//
////walking information
//
//const int WALKING_ANIMATION_FRAMES = 4;
//SDL_Rect gSpriteClips[WALKING_ANIMATION_FRAMES];
//LTexture gSpriteSheetTexture;
//
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
//
//void LTexture::setColor(Uint8  red, Uint8 green, Uint8 blue)
//{
//	//Modulate texture
//	SDL_SetTextureColorMod(mTexture, red, green, blue);
//}
//
//void LTexture::setBlendMode(SDL_BlendMode blending)
//{
//	//set blending function
//	SDL_SetTextureBlendMode(mTexture, blending);
//}
//
//void LTexture::setAlpha(Uint8 alpha)
//{
//	SDL_SetTextureAlphaMod(mTexture, alpha);
//}
//
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
//void LTexture::render(int x, int y, SDL_Rect* clip)
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
//		gWindow = SDL_CreateWindow("Exercise 14", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
//		if (gWindow == NULL)
//		{
//			printf("Window could not be created! SDL Error: %s\n", SDL_GetError());
//			success = false;
//		}
//		else
//		{
//			//create v synced renderer for the windows 
//			gRenderer = SDL_CreateRenderer(gWindow, -1, SDL_RENDERER_ACCELERATED| SDL_RENDERER_PRESENTVSYNC);
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
//	//load front alpha texture 
//	if (!gSpriteSheetTexture.loadFromFile("C://Users/Admin/Documents/SDL/CppTesting/SDLSet/Images/foo.png"))
//	{
//		printf("Failed to load Front' texture image!\n");
//		success = false;
//	}
//	else
//	{
//		//Set Sprite Clips 
//				gSpriteClips[0].x = 0;
//				gSpriteClips[0].y = 0;
//				gSpriteClips[0].w = 64;
//				gSpriteClips[0].h = 205;
//
//				gSpriteClips[1].x = 64;
//				gSpriteClips[1].y = 0;
//				gSpriteClips[1].w = 64;
//				gSpriteClips[1].h = 205;
//
//				gSpriteClips[2].x = 128;
//				gSpriteClips[2].y = 0;
//				gSpriteClips[2].w = 64;
//				gSpriteClips[2].h = 205;
//
//				gSpriteClips[3].x = 196;
//				gSpriteClips[3].y = 0;
//				gSpriteClips[3].w = 64;
//				gSpriteClips[3].h = 205;
//	}
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
//
//			//Current animation Frame
//			int Frame = 0;
//
//
//			while (!quit)
//			{
//				while (SDL_PollEvent(&e) != 0)
//				{
//					if (e.type == SDL_QUIT)
//					{
//						quit = true;
//					}
//					
//				}
//				//Clear screen
//				SDL_SetRenderDrawColor(gRenderer, 0xFF, 0xFF, 0xFF, 0xFF);
//				SDL_RenderClear(gRenderer);
//
//				//render current  frame 
//				SDL_Rect* currentClip = &gSpriteClips[Frame / 10];
//
//				gSpriteSheetTexture.render((SCREEN_WIDTH - currentClip->w) / 2  , (SCREEN_HEIGHT  - currentClip->h)/ 2 , currentClip);
//
//
//				++Frame;
//				if (Frame /10 >= WALKING_ANIMATION_FRAMES)
//				{
//					Frame = 0;
//				}
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
