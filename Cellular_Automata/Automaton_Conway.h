#ifndef AUTOMATON_CONWAY_H
#define AUTOMATON_CONWAY_H

#include "Automaton.h"
#include <vector>

using std::vector;

class Automaton_Conway : public Automaton {

	vector < vector<bool> > data;

public:
	Automaton_Conway(int width, int height);

	bool compose(int x, int y);
};

#endif