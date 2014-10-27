//Shoeboxam
//Render configurable cellular automata

#define SCREEN_WIDTH 620
#define SCREEN_HEIGHT 480

#include <iostream>
#include "Automaton.h"
#include <SDL.h>
#include <stdio.h>

using std::cout;
using std::cin;
using std::endl;

void console_render(Automaton custom_Automaton){
	for (int y = 0; y < 90; y++){
		for (int x = -90; x < 90; x++){
			cout << custom_Automaton.compose(x, y);
		}
		cout << endl;
	}
}

int main(int argc, char* args[]) {

	//User selects how seeds are chosen
	int input_preference = 0;
	cout << "[1] Explicit [2] Linear [3] Random :: ";
	cin >> input_preference;


	if (input_preference == 1){ //Explicit
		while (true){
			int rule_preference = 0;
			cout << "Rule: ";
			cin >> rule_preference;

			Automaton custom(rule_preference);
			console_render(custom);
		}
	}

	if (input_preference == 2){ //Linear
		for (int i = 0; i < 256; i++){
			Automaton custom(i);
		}
	}

	if (input_preference == 3){ //Random
		while (true){
			Automaton custom(rand() % 256);
		}
	}

	system("pause");
	return 0;
}