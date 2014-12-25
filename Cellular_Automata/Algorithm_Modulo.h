#ifndef ALGORITHM_MODULO
#define ALGORITHM_MODULO

#include "Automaton.h"

class Algorithm_Modulo : public Automaton{
	bool compose(int x, int y){
		return (x * y) % 2;
	}
};

#endif