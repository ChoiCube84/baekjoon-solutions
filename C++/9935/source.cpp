#include <bits/stdc++.h>

using namespace std;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int length;
	string input, bomb;
	ostringstream result;

	cin >> input;
	cin >> bomb;

	length = bomb.length();

	int streak = 0;
	deque<char> dq;
	stack<int> prevStreaks;

	for (int i = 0; i < input.length(); i++) {
		if (input[i] == bomb[streak]) {
			dq.push_back(input[i]);
			streak++;

			if (streak == length) {
				for (int i = 0; i < length; i++) {
					dq.pop_back();
				}

				if (prevStreaks.empty()) {
					streak = 0;
				}
				else {
					streak = prevStreaks.top();
					prevStreaks.pop();
				}
			}
		}
		else if (input[i] == bomb[0]) {
			dq.push_back(input[i]);

			prevStreaks.push(streak);
			streak = 1;
		}
		else {
			streak = 0;
			
			while (!prevStreaks.empty()) {
				prevStreaks.pop();
			}

			while (!dq.empty()) {
				result << dq.front();
				dq.pop_front();
			}

			result << input[i];
		}
	}

	while (!dq.empty()) {
		result << dq.front();
		dq.pop_front();
	}

	string resultString = result.str();
	if (resultString == "") {
		cout << "FRULA";
	}

	cout << resultString;

	return 0;
}
