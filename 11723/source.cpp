#include <bits/stdc++.h>

using namespace std;

int main(void) {

	ios::sync_with_stdio(0);
	cin.tie(0);

	int numberOfCommands, element;
	string tempCommand;

	unsigned int S = 0;
	
	cin >> numberOfCommands;

	while (numberOfCommands--) {
		cin >> tempCommand;

		if (tempCommand == "add") {
			cin >> element;
			S |= (1 << element);
		}
		else if (tempCommand == "remove") {
			cin >> element;
			S &= ~(1 << element);
		}
		else if (tempCommand == "check") {
			cin >> element;
			if (S & (1 << element)) {
				cout << "1\n";
			}
			else {
				cout << "0\n";
			}
		}
		else if (tempCommand == "toggle") {
			cin >> element;
			S ^= (1 << element);
		}
		else if (tempCommand == "all") {
			S = (1 << 21) - 1;
		}
		else if (tempCommand == "empty") {
			S = 0;
		}
	}

	return 0;
}
