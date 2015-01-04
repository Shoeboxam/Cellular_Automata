//Shoeboxam
//Render configurable cellular automata

#include <iostream>
//#include <thread>

#include "Automaton_Elementary.h"
#include "Algorithm_Random.h"
#include "Algorithm_Modulo.h"
#include "Cellular_Render.h"

using std::cout;
using std::cin;
using std::endl;

void console_render(Automaton &custom_automaton){
	for (int y = 0; y < 90; y++){
		for (int x = -90; x < 90; x++){
			cout << custom_automaton.compose(x, y);
		}
		cout << endl;
	}
}

int main(int argc, char* args[]) {

	cout << "Rendering automaton . . . \n";

	Automaton_Elementary autom(193, 10);

	Cellular_Render* render = new Cellular_Render(&autom);
	render->loop();
	//std::thread render_thread(&Cellular_Render::loop, render);

	//render_thread.join();
	//delete &render;
	return 0;
}