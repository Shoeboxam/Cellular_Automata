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

	bool Algorithm_Random::compose(int x, int y) {
		return bool(rand() % 2);
	}
};




#endif