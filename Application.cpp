//Shoeboxam
//Render configurable cellular automata

#include <iostream>
#include "Automaton_Random.h"
#include "Automaton_Elementary.h"
#include "Render.h"

using std::cout;
using std::cin;
using std::endl;

void console_render(Automaton &custom_Automaton){
	for (int y = 0; y < 90; y++){
		for (int x = -90; x < 90; x++){
			cout << custom_Automaton.compose(x, y);
		}
		cout << endl;
	}
}

int main(int argc, char* args[]) {

	cout << "test";
	vector<Automaton_Elementary> automa_comprehensive;
	
	//Allocate 256 automata, one for each rule - initial allocation footprint is tiny
	//Prevents destruction of computed automata
	for (int i = 0; i < 256; i++){
		automa_comprehensive.push_back(Automaton_Elementary(i));
	}


	//Render* frame = new Render(&automa_comprehensive[4]);
	Render* frame = new Render(&Automaton_Random());
	
	frame->loop();
	//frame->Pause(10);

	system("pause");
	return 0;
}