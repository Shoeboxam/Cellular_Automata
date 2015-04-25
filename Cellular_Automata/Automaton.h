#ifndef AUTOMATON_H
#define AUTOMATON_H

#include <string>
using std::string;

class Automaton {
public:
	int step;
	virtual bool compose(int x, int y) = 0;
	virtual string get_name() = 0;
};

#endif