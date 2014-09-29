#include "Automaton.h"

vector<bool> automaton::to_vector(string input){
	vector<bool> buffer;
	for (int i = 0; i < input.length(); i++){
		buffer[i] = input[i];
	}
	return buffer;
}

automaton::automaton(int input){
	//Initialize rule to bit array using bitset conversion
	rule = input % 256;
}

const std::unordered_map<vector<bool>, int> automaton::conversion_table = {
		{ to_vector("111"), 0 },
		{ to_vector("110"), 1 },
		{ to_vector("101"), 2 },
		{ to_vector("100"), 3 },
		{ to_vector("011"), 4 },
		{ to_vector("010"), 5 },
		{ to_vector("001"), 6 },
		{ to_vector("000"), 7 }
};

bool automaton::compose(int x, int y){
	//Calculate tree up to limit
	if (y > depth) ordered_build(y);

	//Return whitespace if outside of logic tree
	if (abs(x) > y) return whitespace_predictor(depth);

	//Else return value from logic tree with x offset by depth
	return bit_table[y][x - y];
}

void automaton::ordered_build(int limit){

	//Loop through each value in matrix
	while (depth < limit){

		bool whitespace = whitespace_predictor(depth);

		//Width of row is equivalent to double depth
		int width = depth * 2;
		vector<bool> row(width);

		//First two and last two values in row use whitespace predictor
		row.push_back(rule[conversion_table.at(vector < bool > {whitespace, whitespace, bit_table[depth - 1][0]})]);
		row.push_back(rule[conversion_table.at(vector < bool > {whitespace, bit_table[depth - 1][0], bit_table[depth - 1][1]})]);

		for (int x = 2; x < width - 2; x++){
			//3-bit vector mapped to conversion table, mapped to rule map, then saved to row
			//append ... apply_rule(identify_pattern(bits)) ... to row
			row.push_back(rule[conversion_table.at(vector<bool>(bit_table[depth - 1][x - 1], bit_table[depth - 1][x + 1]))]);
		}

		row.push_back(rule[conversion_table.at(vector < bool > {bit_table[depth - 1][width - 2], bit_table[depth - 1][width - 1], whitespace})]);
		row.push_back(rule[conversion_table.at(vector < bool > {bit_table[depth - 1][width - 1], whitespace, whitespace})]);

		//Save each row
		bit_table[depth] = row;

		//Calculate each row
		depth++;
	}
}

bool automaton::whitespace_predictor(int depth){
	//Predict whitespace pattern of entire rows

	//Whitespace alternates if black becomes white and white becomes black
	if (!rule[0] && rule[7]) return depth % 2;

	//Whitespace is black if white becomes black
	if (rule[7]) return true;

	//Whitespace is white
	return false;
}