#include <bits/stdc++.h>

using namespace std;

unsigned long long int w[2] = { 2, 10 };
unsigned long long int b[2] = { 0, 1 };

vector<bool> visited;
queue<pair<unsigned long long int, unsigned long long int>> q;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	unsigned long long int A, B, change = 0;
	cin >> A >> B;

	visited.resize(B + 1);
	visited[A] = true;
	q.push(make_pair(A, 0));

	while (!q.empty()) {
		unsigned long long int currentNumber = q.front().first;
		int currentStep = q.front().second;
		q.pop();

		for (int i = 0; i < 2; i++) {
			unsigned long long int newNumber = w[i] * currentNumber + b[i];

			if (newNumber == B) {
				cout << currentStep + 2;
				return 0;
			}
			else if (newNumber < B && visited[newNumber] == false) {
				visited[newNumber] = true;
				q.push(make_pair(newNumber, currentStep + 1));
			}
		}
	}

	cout << -1;

	return 0;
}
