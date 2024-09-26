#include <bits/extc++.h>

using namespace __gnu_pbds;
using namespace std;

using ll = long long int;
using ull = unsigned long long int;

using pll = pair<ll, ll>;

struct pair_hash {
public:
	template <typename T, typename U>
	size_t operator()(const pair<T, U> &x) const {
		return hash<T>()(x.first) ^ hash<U>()(x.second);
	}
};

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int ingredientCount, starterDishCount, mainDishCount, dessertCount, badCombinationCount;
	cin >> ingredientCount >> starterDishCount >> mainDishCount >> dessertCount >> badCombinationCount;

	vector<int> brandCount(ingredientCount);
	for (int i=0; i<ingredientCount; i++) {
		cin >> brandCount[i];
	}

	vector<vector<int>> starterDish(starterDishCount);
	for (int i=0; i<starterDishCount; i++) {
		int k;
		cin >> k;

		for (int j=0; j<k; j++) {
			int ingredient;
			cin >> ingredient;

			starterDish[i].push_back(ingredient);
		}
	}

	vector<vector<int>> mainDish(mainDishCount);
	for (int i=0; i<mainDishCount; i++) {
		int k;
		cin >> k;

		for (int j=0; j<k; j++) {
			int ingredient;
			cin >> ingredient;

			mainDish[i].push_back(ingredient);
		}
	}

	vector<vector<int>> dessert(dessertCount);
	for (int i=0; i<dessertCount; i++) {
		int k;
		cin >> k;

		for (int j=0; j<k; j++) {
			int ingredient;
			cin >> ingredient;

			dessert[i].push_back(ingredient);
		}
	}

	gp_hash_table<pair<int, int>, int, pair_hash> badCombinations;
	for (int i=0; i<badCombinationCount; i++) {
		int dish1, dish2;
		cin >> dish1 >> dish2;

		dish1--;
		dish2--;

		if (dish1 > dish2) {
			swap(dish1, dish2);
		}

		badCombinations.insert({{dish1, dish2}, 1});
	}

	__uint128_t total = 0;
	__uint128_t result = 1;

	for (int i=0; i<starterDishCount; i++) {
		for (int j=0; j<mainDishCount; j++) {
			for (int k=0; k<dessertCount; k++) {
				if (badCombinations.find({i, j+starterDishCount}) == badCombinations.end() 
					&& badCombinations.find({j+starterDishCount, k+starterDishCount+mainDishCount}) == badCombinations.end() 
					&& badCombinations.find({i, k+starterDishCount+mainDishCount}) == badCombinations.end()) {

					gp_hash_table<int, int> ingredients;

					for (int l=0; l<starterDish[i].size(); l++) {
						if (ingredients.find(starterDish[i][l]) == ingredients.end()) {
							ingredients.insert({starterDish[i][l], 1});
							result *= brandCount[starterDish[i][l]];

							if (result > 1000000000000000000) {
								cout << "too many";
								return 0;
							}
						}
					}
					for (int l=0; l<mainDish[j].size(); l++) {
						if (ingredients.find(mainDish[j][l]) == ingredients.end()) {
							ingredients.insert({mainDish[j][l], 1});
							result *= brandCount[mainDish[j][l]];

							if (result > 1000000000000000000) {
								cout << "too many";
								return 0;
							}
						}
					}
					for (int l=0; l<dessert[k].size(); l++) {
						if (ingredients.find(dessert[k][l]) == ingredients.end()) {
							ingredients.insert({dessert[k][l], 1});
							result *= brandCount[dessert[k][l]];

							if (result > 1000000000000000000) {
								cout << "too many";
								return 0;
							}
						}
					}

					total += result;
					result = 1;

					if (total > 1000000000000000000) {
						cout << "too many";
						return 0;
					}
				}
			}
		}
	}

	cout << static_cast<ull>(total);

	return 0;
}