#include <bits/extc++.h>

using namespace __gnu_pbds;
using namespace std;

using ll = long long;
using ull = unsigned long long;

using ld = long double;
using pll = pair<ll, ll>;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	string basic_words[10] = {
		"zero", "one", "two", "three", "four",
		"five", "six", "seven", "eight", "nine"
	};
	
	ll M, N;
	cin >> M >> N;
	
	vector<string> words;
	gp_hash_table<string, ll> table;
	
	for (ll i=M; i<=N; i++) {
		string curr;
		ll num = i;
		
		if (num / 10 > 0) {
			curr = basic_words[num / 10];
			curr += ' ';
			num %= 10;
		}
		
		curr += basic_words[num];
		
		words.emplace_back(curr);
		table[curr] = i;
	}
	
	sort(words.begin(), words.end());
	
	ll count = 0;
	for (auto& word : words) {
		cout << table[word] << ' ';
		count++;
		
		if (count == 10) {
			cout << '\n';
			count = 0;
		}
	}
	
	return 0;
}