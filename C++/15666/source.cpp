#include <bits/stdc++.h>
#include <unordered_set>

using namespace std;

int N, M;
vector<int> arr;

template <typename T>
struct vector_hash {
	size_t operator()(const std::vector<T>& v) const {
		std::hash<T> hasher;
		size_t seed = 0;
		for (const T& item : v) {
			seed ^= hasher(item) + 0x9e3779b9 + (seed << 6) + (seed >> 2);
		}
		return seed;
	}
};

unordered_set<vector<int>, vector_hash<int>> vum;

void printNumbers(vector<int>& result, int i, int depth);

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> M;

    arr.resize(N);
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }
    
	sort(arr.begin(), arr.end());

	vector<int> result;
	printNumbers(result, 0, 0);

    return 0;
}

void printNumbers(vector<int>& result, int i, int depth) {
	if (depth == M) {
		if (vum.find(result) == vum.end()) {
			vum.insert(result);
			for (auto& elem : result) {
				cout << elem << " ";
			}
			cout << "\n";
		}
	}
	else {
		for (int j = i; j < N; j++) {
			result.emplace_back(arr[j]);
			printNumbers(result, j, depth + 1);
			result.pop_back();
		}
	}
}
