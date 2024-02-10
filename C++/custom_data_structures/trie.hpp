#ifndef __TRIE_HPP__
#define __TRIE_HPP__

#include <string>
#include <vector>

struct TrieNode {
    bool endOfWord;
    std::vector<int> next;
    int nextLetters;

    TrieNode() : endOfWord(false), nextLetters(0) {
        next.resize(26, -1);
    }
};

struct Trie {
    std::vector<TrieNode> nodes;

    Trie() {
        nodes.emplace_back();
    }

    void insert(const std::string& str) {
        int curr = 0;
        for (char c : str) {
            int idx = c - 'a';
            if (nodes[curr].next[idx] == -1) {
                nodes[curr].nextLetters++;

                nodes[curr].next[idx] = nodes.size();
                nodes.emplace_back();
            }
            curr = nodes[curr].next[idx];
        }
        nodes[curr].endOfWord = true;
    }

    bool find(const std::string& str) {
        int curr = 0;
        for (char c : str) {
            int idx = c - 'a';

            if (nodes[curr].next[idx] == -1) {
                return false;
            }
            else {
                curr = nodes[curr].next[idx];
            }
        }
        return nodes[curr].endOfWord;
    }

    std::vector<int> prefixSearch(const std::string& str) {
        int curr = 0;
        std::vector<int> result;

        for (int i = 0; i < str.size(); i++) {
            int idx = str[i] - 'a';

            if (nodes[curr].endOfWord) {
                result.emplace_back(i);
            }

            if (nodes[curr].next[idx] == -1) {
                return result;
            }
            else {
                curr = nodes[curr].next[idx];
            }
        }

        return result;
    }
};

#endif // !__TRIE_HPP__
