#ifndef __TRIE_HPP__
#define __TRIE_HPP__

#include <string>
#include <vector>

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
	std::vector<TrieNode> nodes;

	Trie() {
		nodes.push_back(TrieNode());
	}

	void add(const std::string& stringToAdd) {
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

#endif // !__TRIE_HPP__
