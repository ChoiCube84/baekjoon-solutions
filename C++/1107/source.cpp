#include <bits/stdc++.h>

using namespace std;

int getDigits(int number);
void makeNumber(int formerNumbers, int digits, vector<int>& availableButtons, vector<int>& numbersToCheck);

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int minimum;
	int targetChannel, numberOfBrokenButtons;

	vector<int> availableButtons = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	vector<int> numbersToCheck;

	cin >> targetChannel;
	cin >> numberOfBrokenButtons;

	for (int i = 0; i < numberOfBrokenButtons; i++) {
		int tempButton;
		cin >> tempButton;
		availableButtons.erase(remove(availableButtons.begin(), availableButtons.end(), tempButton), availableButtons.end());
	}
	
	minimum = abs(targetChannel - 100);

	for (int i = 1; i <= min(6, getDigits(targetChannel) + 1); i++) {
		makeNumber(0, i, availableButtons, numbersToCheck);
	}
	for (auto i : numbersToCheck) {
		minimum = min(minimum, getDigits(i) + abs(targetChannel - i));
	}

	cout << minimum;

	return 0;
}

int getDigits(int number) {
	int digits = 0;

	if (number == 0) {
		return 1;
	}
	else {
		while (number > 0) {
			number /= 10;
			digits++;
		}

		return digits;
	}
}

void makeNumber(int formerNumbers, int digits, vector<int>& availableButtons, vector<int>& numbersToCheck) {
	for (auto i : availableButtons) {
		if (digits == 1) {
			numbersToCheck.emplace_back(formerNumbers * 10 + i);
		}
		else {
			makeNumber(formerNumbers * 10 + i, digits - 1, availableButtons, numbersToCheck);
		}
	}
}
