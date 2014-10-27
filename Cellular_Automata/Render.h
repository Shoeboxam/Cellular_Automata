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

	vector<float> coordinate;
	float zoom; // 1: cube = screen

public:
	Render(Automaton* m_autom);
	~Render();

	bool Display();
	//Setters
	void set_automaton(Automaton* m_autom);

	void Pause(int seconds);
};

#endif