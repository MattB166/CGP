#include <iostream>
#include "SDL.h"

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
	SDL_Window* sdlWindow = SDL_CreateWindow("Week 1 - Intro and Window", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 960, 540, NULL);

	
	//error checking
	if (sdlWindow == nullptr)
	{
		std::cout << "Failed to create window. SDL error: " << SDL_GetError() << std::endl;
	}

	
	//load door up as a surface
	SDL_Surface* image = SDL_LoadBMP("Assets/door.bmp");
	if (image == nullptr)
	{
		std::cout << "Failed to load door.bmp. SDL ERROR: " << SDL_GetError() << std::endl;
	}

	SDL_Surface* image2 = SDL_LoadBMP("Assets/medival_houses.bmp");
	if (image2 == nullptr)
	{
		std::cout << "Failed to load medival_houses.bmp. SDL error: " << SDL_GetError() << std::endl;
	}

	SDL_Surface* background = SDL_LoadBMP("Assets/bg_space_seamless.bmp");
	if (background == nullptr)
	{
		std::cout << "Failed to load background. " << SDL_GetError() << std::endl; 
	}


	//get a pointer to the window surface so we can draw to it 
	SDL_Surface* windowSurface = SDL_GetWindowSurface(sdlWindow);
	if (windowSurface == nullptr)
	{
		std::cout << "Failed to get window surface. SDL Error: " << SDL_GetError() << std::endl;
	}






		//create a destination for where the image will be copied onto the window surface {x,y,w,h}

		SDL_Rect destinationRect{ 200,200,16,16 };
		SDL_Rect destinationRect2{ 16,16,16,16 };
		SDL_Rect destinationRect3{ 1,1,1,1 };
		//Blit (copy) the image onto the window surface

		SDL_BlitSurface(background, NULL, windowSurface, &destinationRect3);
		SDL_BlitSurface(image, NULL, windowSurface, &destinationRect2);
		SDL_BlitSurface(image2, NULL, windowSurface, &destinationRect);

		//update the window to display the new changes
		SDL_UpdateWindowSurface(sdlWindow);


		getchar();
	
		//clean up
		
		SDL_FreeSurface(image);
		SDL_FreeSurface(image2);
		SDL_FreeSurface(background);
		SDL_DestroyWindow(sdlWindow);
		SDL_Quit();
	
	
	

	return 0;
}