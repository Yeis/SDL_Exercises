#include <SDL.h>
#include <SDL_image.h>
#include <stdio.h>
#include <string>

//constatnts
const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;


//Texture Wrapper class

class LTexture
{
private:
	SDL_Texture* mTexture;
	//dimensions
	int mWidth;
	int mHeight;

public:
	//Initializes Variables
	LTexture();

	//Deallocates Memory
	~LTexture();

	//load image at specific path
	bool loadFromFile(std::string path);

	//Function for color modulation
	void setColor(Uint8 red, Uint8 green, Uint8 blue);

	//Function Set Blending
	void setBlendMode(SDL_BlendMode blending);

	//function that sets Alpha modulatoin
	void setAlpha(Uint8 alpha);


	//Deallocates texture 
	void Free();

	//Renders Texture at given Point
	void render(int x, int y, SDL_Rect*  clip = NULL , double angle = 0.0 , SDL_Point* center = NULL , SDL_RendererFlip flip  = SDL_FLIP_NONE);

	//Get image dimensions
	int getWidth();
	int getHeight();

};

//variables 
SDL_Window* gWindow = NULL;
SDL_Renderer* gRenderer = NULL;


//walking information


LTexture gArrowTexture;



//functions

bool Init();
bool loadMedia();
void Close();



// LTexture describen fucntions 
LTexture::LTexture()
{
	//Initialize 
	mTexture = NULL;
	mWidth = 0;
	mHeight = 0;
}
LTexture::~LTexture()
{
	//Deallocate
	Free();
}

void LTexture::setColor(Uint8  red, Uint8 green, Uint8 blue)
{
	//Modulate texture
	SDL_SetTextureColorMod(mTexture, red, green, blue);
}

void LTexture::setBlendMode(SDL_BlendMode blending)
{
	//set blending function
	SDL_SetTextureBlendMode(mTexture, blending);
}

void LTexture::setAlpha(Uint8 alpha)
{
	SDL_SetTextureAlphaMod(mTexture, alpha);
}

void LTexture::Free()
{
	//Free texture if exists
	if (mTexture != NULL)
	{
		SDL_DestroyTexture(mTexture);
		mTexture = NULL;
		mWidth = 0;
		mHeight = 0;
	}
}
bool LTexture::loadFromFile(std::string path)
{
	bool success = true;

	//get rid of previous texture 
	Free();
	//Final texture 
	SDL_Texture* newTexture = NULL;
	//load image first 
	SDL_Surface* loadedImage = IMG_Load(path.c_str());
	if (loadedImage == NULL)
	{
		printf("Unable to load image %s! SDL_image Error: %s\n", path.c_str(), IMG_GetError());
	}
	else
	{
		//Color key Image 
		SDL_SetColorKey(loadedImage, SDL_TRUE, SDL_MapRGB(loadedImage->format, 0, 0xFF, 0xFF));

		//Create texture from surface pixels 
		newTexture = SDL_CreateTextureFromSurface(gRenderer, loadedImage);
		if (newTexture == NULL)
		{
			printf("Unable to create texture from %s! SDL Error: %s\n", path.c_str(), SDL_GetError());
		}
		else
		{
			//get image dimesions 
			mWidth = loadedImage->w;
			mHeight = loadedImage->h;
		}
		//get rid of old surface 
		SDL_FreeSurface(loadedImage);
	}
	mTexture = newTexture;
	return success;


}
void LTexture::render(int x, int y, SDL_Rect* clip ,double angle , SDL_Point* center, SDL_RendererFlip flip )
{
	//set rendering space and render to screen 
	SDL_Rect renderQuad = { x , y ,mWidth,mHeight };
	//set clip dimensions 
	if (clip != NULL)
	{
		renderQuad.w = clip->w;
		renderQuad.h = clip->h;
	}
	SDL_RenderCopyEx(gRenderer, mTexture, clip, &renderQuad, angle, center, flip);
}
int LTexture::getHeight()
{
	return mHeight;
}
int LTexture::getWidth()
{
	return mWidth;
}


//Program Functions


bool Init()
{
	bool success = true;

	if (SDL_Init(SDL_INIT_VIDEO) <  0)
	{
		printf("SDL could not initialize! SDL Error: %s\n", SDL_GetError());
		success = false;
	}
	else
	{
		if (!SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "1"))
		{
			printf("Warning: Linear texture filtering not enabled!");
		}
		//create window 

		gWindow = SDL_CreateWindow("Exercise 14", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
		if (gWindow == NULL)
		{
			printf("Window could not be created! SDL Error: %s\n", SDL_GetError());
			success = false;
		}
		else
		{
			//create v synced renderer for the windows 
			gRenderer = SDL_CreateRenderer(gWindow, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
			if (gRenderer == NULL)
			{
				printf("Renderer could not be created! SDL Error: %s\n", SDL_GetError());
				success = false;
			}
			else
			{
				//Initialize renderer color
				SDL_SetRenderDrawColor(gRenderer, 0xFF, 0xFF, 0xFF, 0xFF);

				//Initialize PNG loading
				int imgFlags = IMG_INIT_PNG;
				if (!(IMG_Init(imgFlags) & imgFlags))
				{
					printf("SDL_image could not initialize! SDL_image Error: %s\n", IMG_GetError());
					success = false;
				}
			}
		}
	}

	return success;
}

void Close()
{
	//Free loaded IMages 
	gArrowTexture.Free();
	//Destroy Window
	SDL_DestroyWindow(gWindow);
	gWindow = NULL;
	//Destroy Renderer
	SDL_DestroyRenderer(gRenderer);
	gRenderer = NULL;
	//Quit SubSystems
	IMG_Quit();
	SDL_Quit();
}
bool loadMedia()
{
	bool success = true;
	//load front alpha texture 
	if (!gArrowTexture.loadFromFile("C://Users/Admin/Documents/SDL/CppTesting/SDLSet/Images/arrow.png"))
	{
		printf("Failed to load Arrow' texture image!\n");
		success = false;
	}
	
	return success;
}

int main(int argc, char* args[])
{

	if (!Init())
	{
		printf("Failed to initialize!\n");
	}
	else
	{
		if (!loadMedia())
		{
			printf("Failed to load media!\n");
		}
		else
		{
			bool quit = false;
			SDL_Event e;

			//Current Degrees
			double  degrees  = 0;
			//Flip Type 
			SDL_RendererFlip fliptype = SDL_FLIP_NONE;


			while (!quit)
			{
				while (SDL_PollEvent(&e) != 0)
				{
					if (e.type == SDL_QUIT)
					{
						quit = true;
					}
					else if (e.type == SDL_KEYDOWN)
					{
						switch (e.key.keysym.sym)
						{
						case SDLK_a:
							degrees -= 60;
							break;
						case SDLK_d:
							degrees += 60;
							break;
						case SDLK_q:
							fliptype = SDL_FLIP_HORIZONTAL;
							break;
						case SDLK_w:
							fliptype = SDL_FLIP_NONE;
							break;
						case SDLK_e:
							fliptype = SDL_FLIP_VERTICAL;
							break;
						default:
							break;
						}
					}



				}
				//Clear screen
				SDL_SetRenderDrawColor(gRenderer, 0xFF, 0xFF, 0xFF, 0xFF);
				SDL_RenderClear(gRenderer);

				//render current  frame 
				gArrowTexture.render((SCREEN_WIDTH - gArrowTexture.getWidth()) / 2, (SCREEN_HEIGHT - gArrowTexture.getHeight()) / 2, NULL, degrees, NULL, fliptype);
				

				//update screen 
				SDL_RenderPresent(gRenderer);
			}
		}
	}

	int error;
	scanf_s("%d", &error);
	Close();
	return 0;
}
