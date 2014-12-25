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
	rectangle.h = scale;
	rectangle.w = scale;

	for (int y = 0; y <= int(1 / zoom); y++){
		rectangle.y = y * scale;
		for (int x = 0; x <= int(1 / zoom); x++){
			rectangle.x = x * scale;

			if (autom->compose(x + offset.first, y + offset.second)){

				SDL_FillRect(surface, &rectangle, SDL_MapRGB(surface->format, 0xa7, 0x98, 0x62));
			}
		}
	}
	return true;
}

	
bool Render::loop(){
	bool quit = false;

	zoom = .5;

	while (!quit){

		//Calculate updated surface
	
		if (!draw()) return false;
		SDL_UpdateWindowSurface(window);

		while (SDL_PollEvent(&event_current)){
			switch (event_current.type){
			case SDL_QUIT:
				quit = 1;
				break;
			case SDL_KEYDOWN:
				switch (event_current.key.keysym.sym){
				case SDLK_w:
					zoom *= 1.1;
					break;
				case SDLK_s:
					zoom *= 0.9;
					break;
				}
				break;
			case SDL_MOUSEBUTTONDOWN:
				switch (event_current.button.button){
				case SDL_BUTTON_MIDDLE:
					//do stuff
					break;
				}
			}
			break;
		}

		//std::this_thread::sleep_for(std::chrono::milliseconds(1));
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