/*
 * SDL2-Basics: 00-HelloWorld
 * 
 * from: https://www.youtube.com/channel/UCkBKfq3QzleueGrjjcRiPMw
 * GitHub: github.com/daywithstars/SDL2-Tutorials
 */


/* Using standard c library and SDL2 */
#include <stdio.h>
#include <SDL2/SDL.h>




int main(int argc, char **argv)
{
	/* Initialize SDL and VIDEO system */
	if ( SDL_Init(SDL_INIT_VIDEO) < 0 )
	{
		SDL_Log("%s\n", SDL_GetError());
		return -1;
	}
	
	/* Creates the application window and set basics properties */
	SDL_Window* window = SDL_CreateWindow("Hello World: SDL",
	100, 100, 640, 480, 0);
	
	/* Creates the render as software type */
	SDL_Renderer* renderer = SDL_CreateRenderer(window, -1,
	SDL_RENDERER_SOFTWARE);
	
	/* Clear the backbuffer from the render then, swap/shows it */
	SDL_RenderClear(renderer);
	SDL_RenderPresent(renderer);
	
	/* Wait 3 seconds or 3000 milliseconds */
	SDL_Delay(3000);
	
	/* Free the memory from renderer and window */
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	
	/* Finalize SDL2 systems */
	SDL_Quit();
	
	/* To not make tests for every function, for now, let's show the last error occurred */
	SDL_Log("Last SDL Error: %s\n", SDL_GetError());
	
	return 0;
}
