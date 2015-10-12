#include <iostream>
#include "SDL2/SDL.h"

int main(){
	if (SDL_Init(SDL_INIT_VIDEO) == -1)
	{
		printf("Can't init SDL:  %s\n", SDL_GetError());
	}

	atexit(SDL_Quit);

	SDL_Delay(3000);
	system("pause");
	return 0;
}