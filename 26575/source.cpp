#include <bits/stdc++.h>

using namespace std;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;

	cout << fixed;
	cout.precision(2);

	while (n--) {
		double dogs, amount, price;

		cin >> dogs >> amount >> price;
		cout << "$" << dogs * amount * price << "\n";
	}

	return 0;
}