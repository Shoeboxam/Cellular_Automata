#ifndef ALGORITHM_MODULO
#define ALGORITHM_MODULO

#include "Automaton.h"

class Algorithm_Modulo : public Automaton{
	bool compose(int x, int y){
		return bool((x % (y + 1) % 2)); //This is all there is to it!
	}
};

#endif