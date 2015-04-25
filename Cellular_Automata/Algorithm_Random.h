#ifndef ALGORITHM_RANDOM_H
#define ALGORITHM_RANDOM_H

#include <ctime>
#include <cstdlib>

#include "Automaton.h"

class Algorithm_Random : public Automaton {
public:
	Algorithm_Random(){
		//Seed random number generator
		srand(static_cast<int>(time(NULL)));
	}
	string get_name(){ return "Random Algorithm"; }

	bool Algorithm_Random::compose(int x, int y) {
		return rand() % 2;
	}
};




#endif