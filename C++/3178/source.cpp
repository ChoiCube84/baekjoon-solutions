#include <bits/stdc++.h>
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
            int idx = c - 'A';
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
            int idx = c - 'A';

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
            int idx = str[i] - 'A';

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
    
    size_t getNodeCount(void) {
        return nodes.size() - 1;
    }
};

#endif // !__TRIE_HPP__

using namespace std;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    int N, K;
    cin >> N >> K;
    
    vector<string> words(N);
    
    for (int i=0; i<N; i++) {
        cin >> words[i];
    }
    
    Trie* trie = new Trie();
    
    for (int i=0; i<N; i++) {
        string halved = words[i].substr(0, K);
        
        trie->insert(halved);
    }
    
    int frontCount = trie->getNodeCount();
    
    delete trie;
    trie = new Trie();
    
    for (int i=0; i<N; i++) {
        string halved = words[i].substr(K, K);
        reverse(halved.begin(), halved.end());
        
        trie->insert(halved);
    }
    
    int backCount = trie->getNodeCount();
    
    cout << frontCount + backCount;
    
    return 0;
}
