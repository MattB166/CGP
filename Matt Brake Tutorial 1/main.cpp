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
	SDL_Window* sdlWindow = SDL_CreateWindow("Week 1 - Intro and Window", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 800, 600, NULL);

	//error checking
	if (sdlWindow == nullptr)
	{
		std::cout << "Failed to create window. SDL error: " << SDL_GetError() << std::endl;
	}

	

	//std::cout << "Hello World" << std::endl; 
	
	getchar();

	//clean up
	SDL_DestroyWindow(sdlWindow);
	SDL_Quit(); 

	return 0;
}