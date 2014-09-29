//Shoeboxam
//Render configurable cellular automata

#include <iostream>
#include "Automaton.h"

using std::cout;
using std::cin;
using std::endl;

void console_render(automaton custom_automaton){
	for (int y = 0; y < 90; y++){
		for (int x = -90; x < 90; x++){
			cout << custom_automaton.compose(x, y);
		}
		cout << endl;
	}
}

int main() {
	//glutInit(&argc, argv);		// Initialize GLUT


	//User selects how seeds are chosen
	int input_preference = 0;
	cout << "[1] Explicit [2] Linear [3] Random :: ";
	cin >> input_preference;


	if (input_preference == 1){ //Explicit
		while (true){
			int rule_preference = 0;
			cout << "Rule: ";
			cin >> rule_preference;

			automaton custom(rule_preference);
			console_render(custom);
			//display(*custom);
		}
	}

	if (input_preference == 2){ //Linear
		for (int i = 0; i < 256; i++){
			automaton custom(i);
			//display(*custom);
		}
	}

	if (input_preference == 3){ //Random
		while (true){
			automaton custom(rand() % 256);
			//display(*custom);
		}
	}

	system("pause");
	return 0;
}