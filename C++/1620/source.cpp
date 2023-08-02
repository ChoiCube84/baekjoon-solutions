#include <bits/stdc++.h>
#include <unordered_map>

using namespace std;

int isNumber(const string& s);

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int numberOfPokemons, numberOfQuestions, tempNumber;
	string tempPokemon;

	unordered_map<int, string> pokedex_string;
	unordered_map<string, int> pokedex_int;

	cin >> numberOfPokemons >> numberOfQuestions;

	for (int i = 1; i <= numberOfPokemons; i++) {
		cin >> tempPokemon;
		pokedex_string.insert({ i, tempPokemon });
		pokedex_int.insert({ tempPokemon, i });
	}

	while (numberOfQuestions--) {
		cin >> tempPokemon;
		tempNumber = isNumber(tempPokemon);
		
		if (tempNumber == -1) {
			cout << pokedex_int[tempPokemon] << "\n";
		}
		else {
			cout << pokedex_string[tempNumber] << "\n";
		}
	}

	return 0;
}

int isNumber(const string& s)
{
	istringstream iss(s);
	int number;
	if (!(iss >> number))
		return -1;

	if (iss.eof()) {
		return number;
	}
	else {
		return -1;
	}
}
