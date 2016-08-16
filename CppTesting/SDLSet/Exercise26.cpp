//#include <SDL.h>
//#include <SDL_image.h>
//#include <stdio.h>
//#include <string>
//#include <SDL_ttf.h>
//#include  <cmath>
//#include <sstream>
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
//	//Function of exercise 16 create image from font string
//	//bool loadFromRenderedText(std::string textureText, SDL_Color textColor);
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
//	void render(int x, int y, SDL_Rect*  clip = NULL, double angle = 0.0, SDL_Point* center = NULL, SDL_RendererFlip flip = SDL_FLIP_NONE);
//
//	//Get image dimensions
//	int getWidth();
//	int getHeight();
//
//};
//class LTimer
//{
//private:
//	//The Clock time when the timer started
//	Uint32 mStartTicks;
//
//	//The ticks stored when the timer was paused
//	Uint32 mPausedTicks;
//
//	//The timer status 
//	bool mPaused;
//	bool mStarted;
//
//public:
//};
//
//
//class Dot 
//{
//private:
//	int mPosX, mPosY;
//	int mVelx, mVely;
//
//public:
//	//dimensions of the dot 
//	static const int DOT_WIDTH = 20;
//	static const int DOT_HEIGHT = 20;
//	static const int DOT_VEL = 10;
//
//	//initializes the dot 
//	Dot();
//	void handleEvent(SDL_Event& e);
//	void move();
//	void render();
//
//};
//
////Dot functions 
//
//
//
//
//
////variables 
//SDL_Window* gWindow = NULL;
//SDL_Renderer* gRenderer = NULL;
////rendered texture 
//LTexture gDotTexture ;
//
//
////functions
//
//bool Init();
//bool loadMedia();
//void Close();
//
//
//Dot::Dot()
//{
//	mPosX = 0;
//	mPosY = 0;
//	//velocity
//	mVelx = 0;
//	mVely = 0;
//
//};
//
//void Dot::handleEvent(SDL_Event& e)
//{
//	if (e.type == SDL_KEYDOWN && e.key.repeat == 0)
//	{
//		//Adjust Vel
//		switch (e.key.keysym.sym)
//		{
//		case SDLK_UP: mVely -= DOT_VEL; break;
//		case SDLK_DOWN: mVely += DOT_VEL; break;
//		case SDLK_RIGHT: mVelx += DOT_VEL; break;
//		case SDLK_LEFT: mVelx -= DOT_VEL; break;
//
//		default:
//			break;
//		}
//	}
//	else if (e.type == SDL_KEYUP && e.key.repeat == 0)
//	{
//		//Adjust the velocity
//		switch (e.key.keysym.sym)
//		{
//		case SDLK_UP: mVely += DOT_VEL; break;
//		case SDLK_DOWN: mVely -= DOT_VEL; break;
//		case SDLK_LEFT: mVelx += DOT_VEL; break;
//		case SDLK_RIGHT: mVelx -= DOT_VEL; break;
//		}
//	}
//}
//
//void Dot::move()
//{
//	mPosX += mVelx;
//	if ((mPosX < 0) || (mPosX + DOT_WIDTH > SCREEN_WIDTH))
//	{
//		//move back 
//		mPosX -= mVelx;
//	}
//	//the same for going u and going down
//	mPosY += mVely;
//	if ((mPosY <  0) || (mPosY + DOT_HEIGHT > SCREEN_HEIGHT))
//	{
//		mPosY -= mVely;
//	}
//}
//
//void Dot::render()
//{
//	gDotTexture.render(mPosX, mPosY);
//}
//
//
//
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
//
//
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
//void LTexture::render(int x, int y, SDL_Rect* clip, double angle, SDL_Point* center, SDL_RendererFlip flip)
//{
//	//set rendering space and render to screen 
//	SDL_Rect renderQuad = { x , y ,mWidth,mHeight };
//	//set clip dimensions 
//	if (clip != NULL)
//	{
//		renderQuad.w = clip->w;
//		renderQuad.h = clip->h;
//	}
//	SDL_RenderCopyEx(gRenderer, mTexture, clip, &renderQuad, angle, center, flip);
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
//			gRenderer = SDL_CreateRenderer(gWindow, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
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
//
//
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
//	gDotTexture.Free();
//	//Destroy Window
//	SDL_DestroyWindow(gWindow);
//	gWindow = NULL;
//	//Destroy Renderer
//	SDL_DestroyRenderer(gRenderer);
//	gRenderer = NULL;
//
//
//	//Quit SubSystems
//	IMG_Quit();
//	SDL_Quit();
//}
//bool loadMedia()
//{
//	bool success = true;
//	//load front Font  "C://Users/Admin/Documents/SDL/CppTesting/SDLSet/Images/dot.bmp"
//	if (!gDotTexture.loadFromFile("C://Users/Yeis/Documents/SDL_Exercises/CppTesting/SDLSet/Images/dot.bmp"))
//	{
//		printf("Failed to load dot texture!\n");
//		success = false;
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
//			Dot dot;
//			while (!quit)
//			{
//				while (SDL_PollEvent(&e) != 0)
//				{
//					if (e.type == SDL_QUIT)
//					{
//						quit = true;
//					}
//					//handle event of the dot 
//					dot.handleEvent(e);
//				}
//				//move dot 
//				dot.move();
//
//				//clear screen 
//				SDL_SetRenderDrawColor(gRenderer, 0xFF, 0xFF, 0xFF, 0xFF);
//				SDL_RenderClear(gRenderer);
//
//				//Render Objects
//				dot.render();
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
