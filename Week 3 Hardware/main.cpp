#include <iostream>
#include "SDL.h"

SDL_Window* g_sdlWindow;
SDL_Renderer* g_sdlRenderer;

SDL_Texture* LoadTexture(const char* filename)
{
	//load door bmp as a surface
	SDL_Surface* image = SDL_LoadBMP(filename);
	if (image == nullptr)
	{
		std::cout << "Failed to load " << filename << ". SDL ERROR: " << SDL_GetError() << std::endl;
	}

	//convert surface of loaded bmp into a texture
	SDL_Texture* texture = SDL_CreateTextureFromSurface(g_sdlRenderer, image);
	if (texture == nullptr)
	{
		std::cout << "Failed to create texture from surface" << std::endl;
	}

	//free surface
	SDL_FreeSurface(image);

	return texture;
}








int main(int argc, char* argv[])
{
	
	//initialise all SDL subsystems
	if (SDL_Init(SDL_INIT_EVERYTHING) < 0)
	{
		std::cout << "Failed to initialise SDL. SDL error: " << SDL_GetError() << std::endl; 
	}
	
	//create a window with specified name, anywhere on screen, 800x600 pixel size and no SDL_windowflags.	

	//flag testing 
	int iwindowflag = SDL_WINDOW_FULLSCREEN_DESKTOP | SDL_WINDOW_FULLSCREEN_DESKTOP;
	 g_sdlWindow = SDL_CreateWindow("Week 1 - Intro and Window", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 800, 600, NULL);

	//error checking
	if (g_sdlWindow == nullptr)
	{
		std::cout << "Failed to create window. SDL error: " << SDL_GetError() << std::endl;
	}


	//Create a rendering context for our window. Enable Hardware acceleration with the SLD_RENDERER_ACCELERATED FLAG

	 g_sdlRenderer = SDL_CreateRenderer(g_sdlWindow, -1, SDL_RENDERER_ACCELERATED);
	if (g_sdlRenderer == nullptr)
	{
		std::cout << "Failed to create renderer. SDL error: " << SDL_GetError() << std::endl; 

    }

	//load door as a surface
	SDL_Surface* image = SDL_LoadBMP("assets/door.bmp");
	////error checking
	if (image == nullptr)
	{
		std::cout << "Failed to load image" << SDL_GetError();
	}

	SDL_Texture* doorTexture = LoadTexture("assets/door.bmp");
	

	
	
	SDL_Texture* texture = SDL_CreateTextureFromSurface(g_sdlRenderer, image);
	//error checking
	if (texture == nullptr)
	{
		std::cout << "Failed to create texture from surface. SDL ERROR: " << SDL_GetError() << std::endl;
	}

	for(int framecount = 0; framecount < 850; framecount ++)
	{
		SDL_SetRenderDrawColor(g_sdlRenderer,19,47,209,255);
		SDL_RenderClear(g_sdlRenderer);
		
		//create destination for where the image will be copied{x,y,w,h}
		SDL_Rect destinationRect{ framecount,25,16,16 };
		//copy texture onto rendering target
		SDL_RenderCopy(g_sdlRenderer, doorTexture, NULL, &destinationRect);

		//update the screen with the state of the render target
		SDL_RenderPresent(g_sdlRenderer);
		SDL_Delay(16);

	}
	SDL_FreeSurface(image);



	//std::cout << "Hello World" << std::endl; 
	
	//getchar();

	//clean up
	SDL_DestroyTexture(doorTexture);
	SDL_DestroyRenderer(g_sdlRenderer);
	SDL_DestroyWindow(g_sdlWindow);
	SDL_Quit(); 

	return 0;
}