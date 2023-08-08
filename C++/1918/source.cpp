#include <bits/stdc++.h>

using namespace std;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	string originalExpression;

	char currentOperator;
	stack<char> operators;

	cin >> originalExpression;

	for (int i = 0; i < originalExpression.length(); i++) {
		char letter = originalExpression[i];

		if (letter == '+' || letter == '-') {
			if (!operators.empty()) {
				while (!operators.empty() && operators.top() != '(') {
					cout << operators.top();
					operators.pop();
				}
			}
			operators.push(letter);
		}
		else if (letter == '*' || letter == '/') {
			while (!operators.empty() && (operators.top() == '*' || operators.top() == '/')) {
				cout << operators.top();
				operators.pop();
			}
			operators.push(letter);
		}
		else if (letter == '(') {
			operators.push(letter);
		}
		else if (letter == ')') {
			while (true) {
				currentOperator = operators.top();
				operators.pop();

				if (currentOperator == '(') {
					break;
				}
				else {
					cout << currentOperator;
				}
			}
		}
		else {
			cout << letter;
		}
	}

	while (!operators.empty()) {
		cout << operators.top();
		operators.pop();
	}

	return 0;
}
