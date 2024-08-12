#include <bits/extc++.h>

using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int N, M;
	cin >> N >> M;

	for (int i=0; i<N; i++) {
		string input;
		cin >> input;

		reverse(input.begin(), input.end());

		cout << input << '\n';
	}

	return 0;
}