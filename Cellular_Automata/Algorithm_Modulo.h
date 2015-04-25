#ifndef ALGORITHM_MODULO
#define ALGORITHM_MODULO

#include "Automaton.h"

class Algorithm_Modulo : public Automaton{
	string get_name(){ return "Modulo Algorithm"; }
	bool compose(int x, int y){
		return (abs(x) % (abs(y) + 1) % 2);
	}
};

#endif