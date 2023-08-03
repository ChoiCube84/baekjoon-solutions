#include <bits/stdc++.h>
#include <unordered_set>

using namespace std;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	unordered_set<string> neverHeard;
	priority_queue<string, vector<string>, greater<string>> neverHeardAndSeen;

	int numberOfNeverHeard, numberOfNeverSeen;
	int numberOfNeverHeardAndSeen = 0;

	string tempPerson;

	cin >> numberOfNeverHeard >> numberOfNeverSeen;

	while (numberOfNeverHeard--) {
		cin >> tempPerson;
		neverHeard.insert({ tempPerson });
	}

	while (numberOfNeverSeen--) {
		cin >> tempPerson;
		if (neverHeard.count(tempPerson)) {
			numberOfNeverHeardAndSeen++;
			neverHeardAndSeen.push(tempPerson);
		}
	}

	cout << numberOfNeverHeardAndSeen << "\n";

	while (!neverHeardAndSeen.empty()) {
		cout << neverHeardAndSeen.top() << "\n";
		neverHeardAndSeen.pop();
	}

	return 0;
}
