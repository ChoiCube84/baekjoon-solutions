#include <bits/stdc++.h>

using namespace std;

void pushIntoQueue(queue<pair<int, string>>& queue, const pair<int, string>& currentStatus, const pair<int, string>& converted, bool* visited, pair<int, string>* history);

pair<int, string> D(pair<int, string> initialValue);
pair<int, string> S(pair<int, string> initialValue);
pair<int, string> L(pair<int, string> initialValue);
pair<int, string> R(pair<int, string> initialValue);

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int numberOfTestCases, initialValue, finalValue;
	string result = "";
	bool visited[10000] = { false, };
	pair<int, string> history[10000];

	queue<pair<int, string>> converted;

	cin >> numberOfTestCases;

	while (numberOfTestCases--) {
		cin >> initialValue >> finalValue;

		converted.push({ initialValue, "" });
		visited[initialValue] = true;

		while (true) {
			pair<int, string> currentStatus = converted.front();
			converted.pop();

			if (currentStatus.first == finalValue) {
				result += currentStatus.second;
				for (int i = finalValue; i != initialValue; i = history[i].first) {
					result += history[i].second;
				}
				reverse(result.begin(), result.end());
				cout << result << "\n";
				break;
			}
			else {
				pushIntoQueue(converted, currentStatus, D(currentStatus), visited, history);
				pushIntoQueue(converted, currentStatus, S(currentStatus), visited, history);
				pushIntoQueue(converted, currentStatus, L(currentStatus), visited, history);
				pushIntoQueue(converted, currentStatus, R(currentStatus), visited, history);
			}
		}

		result = "";

		while (!converted.empty()) {
			converted.pop();
		}

		for (int i = 0; i < 10000; i++) {
			visited[i] = false;
		}
	}

	return 0;
}

void pushIntoQueue(queue<pair<int, string>>& queue, const pair<int, string>& currentStatus, const pair<int, string>& converted, bool* visited, pair<int, string>* history) {
	if (!visited[converted.first]) {
		queue.push(converted);
		visited[converted.first] = true;
		history[converted.first] = currentStatus;
	}
}

pair<int, string> D(pair<int, string> initialValue) {
	pair<int, string> converted;

	converted.first = (initialValue.first * 2) % 10000;
	converted.second = "D";

	return converted;
}

pair<int, string> S(pair<int, string> initialValue) {
	pair<int, string> converted;

	converted.first = (initialValue.first + 9999) % 10000;
	converted.second = "S";

	return converted;
}

pair<int, string> L(pair<int, string> initialValue) {
	pair<int, string> converted;

	converted.first = (initialValue.first % 1000) * 10 + (initialValue.first / 1000);
	converted.second = "L";

	return converted;
}

pair<int, string> R(pair<int, string> initialValue) {
	pair<int, string> converted;

	converted.first = (initialValue.first % 10) * 1000 + (initialValue.first / 10);
	converted.second = "R";

	return converted;
}
