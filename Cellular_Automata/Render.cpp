#include "Render.h"

#include <iostream>
using std::cout;

Render::Render(Automaton* m_autom){

	//Save pointer to automaton
	autom = m_autom;

	momentum.first = 0;
	momentum.second = 0;
	zoom = .025;

	//Start SDL, check for failures
	if (SDL_Init(SDL_INIT_VIDEO) < 0) throw ("SDL failure to initialize: %s\n", SDL_GetError());

	window = SDL_CreateWindow("Automaton", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
	if (window == NULL) throw ("SDL failure to declare: %s\n", SDL_GetError());

	surface = SDL_GetWindowSurface(window);

	SDL_FillRect(surface, NULL, SDL_MapRGB(surface->format, 0x67, 0x6c, 0x7e));

	//Create renderer for window
	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
	if (renderer == NULL) throw ("Renderer could not be created! SDL Error: %s\n", SDL_GetError());

	SDL_UpdateWindowSurface(window);
}

bool Render::draw(){
	//Reset screen
	SDL_FillRect(surface, NULL, SDL_MapRGB(surface->format, 0x67, 0x6c, 0x7e));

	//Holds location of box to render
	SDL_Rect rectangle = { 0, 0, 0, 0 };

	//Determine size of box
	float scale = SCREEN_HEIGHT * zoom;
	rectangle.h = ceil(scale);
	rectangle.w = ceil(scale);

	for (int y = 0; y <= int(SCREEN_HEIGHT / scale); y++){
		rectangle.y = y * scale;
		for (int x = 0; x <= int(SCREEN_WIDTH / scale); x++){
			rectangle.x = x * scale;

			if (autom->compose(x + offset.first, y + offset.second)){

				SDL_FillRect(surface, &rectangle, SDL_MapRGB(surface->format, 0xa7, 0x98, 0x62));
			}
		}
	}

	SDL_UpdateWindowSurface(window);

	return true;
}

	
bool Render::loop(){
	bool quit = false;

	while (!quit){

		offset.first += momentum.first;
		offset.second += momentum.second;

		momentum.first *= .9;
		momentum.second *= .9;

		while (SDL_PollEvent(&event_current)){
			switch (event_current.type){
			case SDL_QUIT:
				quit = 1;
				break;
			case SDL_KEYDOWN:
				switch (event_current.key.keysym.sym){
				case SDLK_UP:
					zoom *= 1.1;
					break;
				case SDLK_DOWN:
					zoom *= 0.9;
					break;
				case SDLK_a:
					momentum.first--;
					break;
				case SDLK_d:
					momentum.first++;
					break;
				case SDLK_w:
					momentum.second--;
					break;
				case SDLK_s:
					momentum.second++;
					break;
				}
				break;
			case SDL_MOUSEBUTTONDOWN:
				switch (event_current.button.button){
				case SDL_BUTTON_LEFT:
					if (event_current.type == SDL_MOUSEMOTION) {
						offset.first += event_current.motion.xrel;
						offset.second += event_current.motion.yrel;

						cout << "Registered SDL_BUTTON_LEFT\n";
					}
					break;
				}
			}
			break;
		}

		//Calculate updated surface
		if (!draw()) return false;
	}
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


void Render::pause(int seconds){
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