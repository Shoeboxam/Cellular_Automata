#ifndef RENDER_H
#define RENDER_H

#define SCREEN_WIDTH 620
#define SCREEN_HEIGHT 480

#include <SDL.h>
#include <utility>
#include <chrono>

#include "Automaton.h"


class Cellular_Render {

	Automaton* autom = NULL;

	SDL_Window* window = NULL;
	SDL_Surface* surface = NULL;
	SDL_Event event_current;

	SDL_Renderer* renderer = NULL;

	std::pair<float, float> offset;
	std::pair<float, float> momentum;
	float zoom; // 1: cube = screen


public:
	bool draw();
	Cellular_Render(Automaton* m_autom);
	~Cellular_Render();

	bool loop();

	//Setters
	void set_automaton(Automaton* m_autom);

	void pause(int seconds);
};

#endif