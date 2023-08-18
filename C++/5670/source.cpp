#include <bits/stdc++.h>

using namespace std;

struct TrieNode {
	bool endOfWord;
	int next[26];
	int nextLetters;

	TrieNode() : endOfWord(false), nextLetters(0) {
		for (int i = 0; i < 26; i++) {
			next[i] = -1;
		}
	}
};

struct Trie {
	vector<TrieNode> nodes;

	Trie() {
		nodes.push_back(TrieNode());
	}

	void add(const string& stringToAdd) {
		int currentNode = 0;
		for (char c : stringToAdd) {
			int idx = c - 'a';
			if (nodes[currentNode].next[idx] == -1) {
				nodes[currentNode].nextLetters++;

				nodes[currentNode].next[idx] = nodes.size();
				nodes.push_back(TrieNode());
			}
			currentNode = nodes[currentNode].next[idx];
		}
		nodes[currentNode].endOfWord = true;
	}
};

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cout << fixed;
	cout.precision(2);

	int N;

	while (cin >> N) {
		
		string tempWord;
		vector<string> words;
		Trie trie;

		for (int i = 0; i < N; i++) {
			cin >> tempWord;
			words.emplace_back(tempWord);
			trie.add(tempWord);
		}

		int totalPush = 0;

		for (const string& word : words) {
			int pushCount = 0;
			int currentNode = 0;

			for (int i = 0; i < word.length(); i++) {
				if (i == 0 || trie.nodes[currentNode].endOfWord == true || trie.nodes[currentNode].nextLetters > 1) {
					pushCount++;
				}
				currentNode = trie.nodes[currentNode].next[word[i] - 'a'];
			}
			totalPush += pushCount;
		}

		cout << static_cast<double>(totalPush) / words.size() << "\n";
	}

	return 0;
}
