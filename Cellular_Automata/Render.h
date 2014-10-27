#ifndef RENDER_H
#define RENDER_H

#define SCREEN_WIDTH 620
#define SCREEN_HEIGHT 480

#include <SDL.h>
#include "Automaton.h"

class Render {
	Automaton* autom;

	SDL_Window* window;
	SDL_Surface* surface;

public:
	Render(Automaton* m_autom);
	~Render();

	void Pause(int seconds);
};

#endif