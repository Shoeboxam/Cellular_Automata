#ifndef AUTOMATON_ELEMENTARY_H
#define AUTOMATON_ELEMENTARY_H

#include <cmath>
#include <string>
#include <vector>
#include <unordered_map>
#include <map>
#include <bitset>

#include "Automaton.h"

using std::string;
using std::bitset;
using std::vector;


class Automaton_Elementary : public Automaton {
	static vector<bool> Automaton_Elementary::to_vector(string input);

	//Store list of boolean vectors - vectors used because they are dynamically allocated
	vector<vector<bool>> bit_table;

	bitset<8> rule;

	//Current calculated limit
	int depth;

	void ordered_build(int limit);
	bool whitespace_predictor(int depth);

	static const std::unordered_map<vector<bool>, int> conversion_table;

public:
	Automaton_Elementary(int input);

	bool compose(int x, int y);
};

#endif