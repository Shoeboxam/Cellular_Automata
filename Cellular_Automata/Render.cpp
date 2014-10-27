#include "Render.h"


Render::Render(Automaton* m_autom){
	//Save pointer to automaton
	autom = m_autom;

	//Start SDL, check for failures
	if (SDL_Init(SDL_INIT_VIDEO) < 0) throw ("SDL failure to initialize: %s\n", SDL_GetError());
	window = SDL_CreateWindow("Automaton", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
	
	if (window == NULL) throw ("SDL failure to declare: %s\n", SDL_GetError());
	surface = SDL_GetWindowSurface(window);

	SDL_FillRect(surface, NULL, SDL_MapRGB(surface->format, 0xff, 0xff, 0xff));
	SDL_UpdateWindowSurface(window);
}


Render::~Render(){

	SDL_DestroyWindow(window);
	window = NULL;

	SDL_Quit;
}


void Render::Pause(int seconds){
	SDL_Delay(seconds * 1000);
}