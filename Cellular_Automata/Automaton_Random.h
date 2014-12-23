#ifndef AUTOMATON_RANDOM_H
#define AUTOMATON_RANDOM_H

#include <ctime>
#include <cstdlib>

#include "Automaton.h"

class Automaton_Random : public Automaton {
public:
	Automaton_Random(){
		//Seed random number generator
		srand(static_cast<int>(time(NULL)));
	}

	bool Automaton_Random::compose(int x, int y) {
		return rand() % 2;
	}
};




#endif