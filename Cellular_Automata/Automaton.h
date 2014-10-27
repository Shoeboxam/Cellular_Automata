#ifndef Automaton_H
#define Automaton_H

#include <cmath>
#include <string>
#include <vector>
#include <unordered_map>
#include <map>
#include <bitset>

using std::string;
using std::bitset;
using std::vector;


class Automaton {
	static vector<bool> Automaton::to_vector(string input);

	//Store list of boolean vectors - vectors used because they are dynamically allocated
	std::vector<vector<bool>> bit_table;

	bitset<8> rule;

	//Current calculated limit
	int depth = 0;

	void ordered_build(int limit);
	bool whitespace_predictor(int depth);

	static const std::unordered_map<vector<bool>, int> conversion_table;

public:
	Automaton(int input);

	bool compose(int x, int y);
};

#endif