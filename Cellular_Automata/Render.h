#ifndef RENDER_H
#define RENDER_H

#define SCREEN_WIDTH 620
#define SCREEN_HEIGHT 480

#include <SDL.h>
#include <utility>
#include "Automaton.h"

class Render {

	Automaton* autom = NULL;

	SDL_Window* window = NULL;
	SDL_Surface* surface = NULL;
	SDL_Event* event_current = NULL;

	SDL_Renderer* renderer = NULL;

	std::pair<float, float> offset;
	float zoom; // 1: cube = screen

	bool draw();

public:
	Render(Automaton* m_autom);
	~Render();

	bool loop();

	//Setters
	void set_automaton(Automaton* m_autom);

	void pause(int seconds);
};

#endif