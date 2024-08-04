#include <bits/extc++.h>

using namespace std;

using ll = long long int;
using ull = unsigned long long int;

using pll = pair<ll, ll>;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int ingredientCount, starterDishCount, mainDishCount, dessertCount, badCombinationCount;
	cin >> ingredientCount >> starterDishCount >> mainDishCount >> dessertCount >> badCombinationCount;

	vector<int> brandCount(ingredientCount);
	for (int i=0; i<ingredientCount; i++) {
		cin >> brandCount[i];
	}

	for (int i=0; i<starterDishCount; i++) {
		// WIP
	}

	// WIP
	
	return 0;
}