#include "Automaton_Elementary.h"

Automaton_Elementary::Automaton_Elementary(int input){
	//Initialize rule to bit array using bitset conversion
	rule = input % 256;
	

	//Create first row manually
	bit_table.push_back(vector < bool > {1});

	//Create second row manually
	vector <bool> second_row;
	second_row.push_back(rule[conversion_table.at(vector < bool > {false, false, true})]);
	second_row.push_back(rule[conversion_table.at(vector < bool > {false, true, false})]);
	second_row.push_back(rule[conversion_table.at(vector < bool > {true, false, false})]);
	bit_table.push_back(second_row);
}

const std::unordered_map<vector<bool>, int> Automaton_Elementary::conversion_table = {
	//Rules decrement because bitset stores values in increasing significance (reverse)
		{ vector < bool > {1, 1, 1}, 7 },
		{ vector < bool > {1, 1, 0}, 6 },
		{ vector < bool > {1, 0, 1}, 5 },
		{ vector < bool > {1, 0, 0}, 4 },
		{ vector < bool > {0, 1, 1}, 3 },
		{ vector < bool > {0, 1, 0}, 2 },
		{ vector < bool > {0, 0, 1}, 1 },
		{ vector < bool > {0, 0, 0}, 0 }
};

bool Automaton_Elementary::compose(int x, int y){

	if (y < 0) return false;

	//Return whitespace if outside of logic tree
	if (abs(x) > y) return whitespace_predictor(y + 1);

	//Else calculate tree up to limit
	if (y > bit_table.size() - 1) ordered_build(y);

	//Return value from logic tree with x offset by depth
	return bit_table[y][x + y];
}

void Automaton_Elementary::ordered_build(int limit){

	//Loop through each value in matrix
	while (bit_table.size() - 1 < limit){

		bool whitespace = whitespace_predictor(bit_table.size());

		//int width = bit_table.size() * 2 + 1;
		vector<bool> row;

		//First two and last two values in row use whitespace predictor
		row.push_back(rule[conversion_table.at(vector < bool > {whitespace, whitespace, bit_table.back()[0]})]);
		row.push_back(rule[conversion_table.at(vector < bool > {whitespace, bit_table.back()[0], bit_table.back()[1]})]);

		for (int i = 1; i < bit_table.size() * 2 - 2; i++){
			//3-bit vector mapped to conversion table, mapped to rule table, then saved to row
			//append ... apply_rule(identify_pattern(bits)) ... to row
			vector < bool > buffer { bit_table.back()[i - 1], bit_table.back()[i], bit_table.back()[i + 1] };
			row.push_back(rule[conversion_table.at(buffer)]);
		}

		row.push_back(rule[conversion_table.at(vector < bool > {bit_table.back()[bit_table.back().size() - 2], bit_table.back().back(), whitespace})]);
		row.push_back(rule[conversion_table.at(vector < bool > {bit_table.back().back(), whitespace, whitespace})]);

		//Save row
		bit_table.push_back(row);
	}
}

bool Automaton_Elementary::whitespace_predictor(int row){
	//Predict whitespace pattern of entire rows

	//Whitespace alternates if black becomes white and white becomes black
	if (!rule[7] && rule[0]) return row % 2;

	//Whitespace is black if white becomes black
	if (rule[0]) return true;

	//Whitespace is white
	return false;
}