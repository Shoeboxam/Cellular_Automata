#include "Render.h"


Render::Render(Automaton* m_autom){
	//Save pointer to automaton
	autom = m_autom;

	zoom = 1;

	//Start SDL, check for failures
	if (SDL_Init(SDL_INIT_VIDEO) < 0) throw ("SDL failure to initialize: %s\n", SDL_GetError());
	window = SDL_CreateWindow("Automaton", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
	
	if (window == NULL) throw ("SDL failure to declare: %s\n", SDL_GetError());
	surface = SDL_GetWindowSurface(window);

	SDL_FillRect(surface, NULL, SDL_MapRGB(surface->format, 0xff, 0xff, 0xff));
	SDL_UpdateWindowSurface(window);
}

bool Render::Display(){
	//Instead of back-calculating coords, possibly compose render window range into vector, then traverse vector?

	SDL_Surface* cube = NULL;
	SDL_FillRect(cube, NULL, SDL_MapRGB(cube->format, 0x00, 0x00, 0x00));

	//Holds location of box to render
	SDL_Rect* target;

	float scale = SCREEN_HEIGHT * zoom;
	target->h = scale;
	target->w = scale;

	for (int y = int(SCREEN_HEIGHT / scale); y >= 0; y--){
		target->y = y * scale;
		for (int x = int(SCREEN_WIDTH / scale); x >= 0; x--){
			target->x = x * scale;
			// if (autom->compose(respective coords)) { blit }
			SDL_BlitSurface(surface, NULL, cube, target);
		}
	}

	SDL_UpdateWindowSurface(window);
	return true;
}


void Render::set_automaton(Automaton* m_autom){
	autom = m_autom;
}

Render::~Render(){

	SDL_DestroyWindow(window);
	window = NULL;

	SDL_Quit;
}


void Render::Pause(int seconds){
	SDL_Delay(seconds * 1000);
}


/* ~~~ Keybindings
Numpad - rule entry
Scrollbar - zoom
Mouse Left - drag
Arrows - scroll
Right Click - invert cell
R - Random rule
H - move location to home
*/