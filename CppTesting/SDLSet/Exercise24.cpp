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
//	bool loadFromRenderedText(std::string textureText, SDL_Color textColor);
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
//	LTimer();
//	void Start();
//	void Pause();
//	void unPause();
//	void Stop();
//	Uint32 getTicks();
//	bool isStarted();
//	bool isPaused();
//
//};
////variables 
//SDL_Window* gWindow = NULL;
//SDL_Renderer* gRenderer = NULL;
//TTF_Font *gFont = NULL;
////rendered texture 
//LTexture gTimeTextTexture;
//LTexture gPromptTextTexture;
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
//
//bool LTexture::loadFromRenderedText(std::string textureText, SDL_Color textColor)
//{
//	//get rid of preexisting texture 
//	Free();
//
//	//render texture surface 
//	SDL_Surface* textSurface = TTF_RenderText_Solid(gFont, textureText.c_str(), textColor);
//	if (textSurface == NULL)
//	{
//		printf("Unable to render text surface! SDL_ttf Error: %s\n", TTF_GetError());
//	}
//	else
//	{
//		//create texture from surface pixels 
//		mTexture = SDL_CreateTextureFromSurface(gRenderer, textSurface);
//		if (mTexture == NULL)
//		{
//			printf("Unable to create texture from rendered text! SDL Error: %s\n", SDL_GetError());
//		}
//		else
//		{
//			//get image dimensions
//			mWidth = textSurface->w;
//			mHeight = textSurface->h;
//		}
//		//get rid of old surface 
//		SDL_FreeSurface(textSurface);
//	}
//	return mTexture != NULL;
//}
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
////Ltimer methods 
//
//LTimer::LTimer()
//{
//	//init variables 
//	mPausedTicks = 0;
//	mStartTicks = 0;
//	mPaused = false;
//	mStarted = false;
//}
//void LTimer::Start()
//{
//	//start the timer 
//	mStarted = true;
//	mPaused = false;
//
//	mStartTicks = SDL_GetTicks();
//	mPausedTicks = 0;
//}
//void LTimer::Stop()
//{
//	mStarted = false;
//	mPaused = false;
//	//clear ticks variables 
//	mStartTicks = 0;
//	mPausedTicks = 0;
//}
//void LTimer::Pause()
//{
//	if (mStarted && !mPaused)
//	{
//		//pause the timer 
//		mPaused = true;
//		mPausedTicks = SDL_GetTicks() - mStartTicks;
//		mStartTicks = 0;
//	}
//}
//void LTimer::unPause()
//{
//	if (mStarted && mPaused)
//	{
//		mPaused = false;
//		mStartTicks = SDL_GetTicks() - mPausedTicks;
//		mPausedTicks = 0;
//	}
//}
//Uint32	LTimer::getTicks()
//{
//	//the actual time 
//	Uint32 time = 0;
//	if (mStarted)
//	{
//		if (mPaused)
//		{
//			//return the number of ticks when the timer was paused 
//			time = mPausedTicks;
//		}
//		else
//		{
//			time = SDL_GetTicks() - mStartTicks;
//		}
//	}
//	return time;
//}
//bool LTimer::isStarted()
//{
//	return mStarted;
//}
//bool LTimer::isPaused()
//{
//	return mPaused;
//}
//
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
//				//Initialize SDL TTF 
//				if (TTF_Init() == -1)
//				{
//					printf("SDL_ttf could not initialize! SDL_ttf Error: %s\n", TTF_GetError());
//					success = false;
//				}
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
//	gTimeTextTexture.Free();
//	//Destroy Window
//	SDL_DestroyWindow(gWindow);
//	gWindow = NULL;
//	//Destroy Renderer
//	SDL_DestroyRenderer(gRenderer);
//	gRenderer = NULL;
//	//Destroy Font
//	TTF_CloseFont(gFont);
//	gFont = NULL;
//
//	//Quit SubSystems
//	IMG_Quit();
//	SDL_Quit();
//	TTF_Quit();
//}
//bool loadMedia()
//{
//	bool success = true;
//	//load front Font   C:\Users\Yeis\Documents\SDL_Exercises\CppTesting\SDLSet\Images
//	gFont = TTF_OpenFont("C://Users/Yeis/Documents/SDL_Exercises/CppTesting/SDLSet/Images/lazy.ttf", 28);
//	if (gFont == NULL)
//	{
//		printf("Failed to load lazy font! SDL_ttf Error: %s\n", TTF_GetError());
//		success = false;
//	}
//	else
//	{
//		//render text set text color as black 
//		SDL_Color textColor = { 0,0,0,255 };
//		if (!gPromptTextTexture.loadFromRenderedText("The quick brown fox jumps over the lazy dog", textColor))
//		{
//			printf("Failed to render text texture!\n");
//			success = false;
//		}
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
//			//text color 
//			SDL_Color textColor = { 0,0,0,255 };
//			//Current time start time
//			LTimer fpsTimer;
//			//In memory textStream
//			std::stringstream timtetext;
//			//start counting frames per second 
//			int countedFrames = 0;
//			fpsTimer.Start();
//
//
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
//					//Reset start time on return keypress
//				}
//
//				//calculate and correct fps 
//				float avgFPS = countedFrames / (fpsTimer.getTicks() / 1000.f);
//				if (avgFPS > 2000000)
//				{
//					avgFPS = 0;	
//						 
//				}
//
//				//set text to be rendered
//				timtetext.str("");
//				timtetext << " Average Frames per Second " << avgFPS;
//
//
//				//render text 
//				if (!gTimeTextTexture.loadFromRenderedText(timtetext.str().c_str(), textColor))
//				{
//					printf("Unable to render time texture!\n");
//				}
//
//				//Clear screen
//				SDL_SetRenderDrawColor(gRenderer, 0xFF, 0xFF, 0xFF, 0xFF);
//				SDL_RenderClear(gRenderer);
//
//				//render current  frame 
//				gPromptTextTexture.render((SCREEN_WIDTH - gPromptTextTexture.getWidth()) / 2, 0);
//
//				gTimeTextTexture.render((SCREEN_WIDTH - gTimeTextTexture.getWidth()) / 2, (SCREEN_HEIGHT - gTimeTextTexture.getHeight()) / 2);
//
//				//update screen 
//				SDL_RenderPresent(gRenderer);
//				++countedFrames;
//			}
//		}
//	}
//
//	int error;
//	scanf_s("%d", &error);
//	Close();
//	return 0;
//}
