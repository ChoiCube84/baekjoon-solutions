#include <bits/stdc++.h>
#include <unordered_set>

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

        for (int i=0; i<str.size(); i++) {
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

using namespace std;

using ll = long long;
using ull = unsigned long long;

using pii = pair<int, int>;
using pll = pair<ll, ll>;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int C, N;
    cin >> C >> N;

    Trie colorTrie;

    for (int i=0; i<C; i++) {
        string color;
        cin >> color;
        colorTrie.insert(color);
    }

    unordered_set<string> nicknameTable;

    for (int i=0; i<N; i++) {
        string nickname;
        cin >> nickname;
        nicknameTable.insert(nickname);
    }

    int Q;
    cin >> Q;

    for (int i=0; i<Q; i++) {
        string team;
        cin >> team;

        vector<int> colorPrefixEndingIndex = colorTrie.prefixSearch(team);
        bool found = false;

        for (auto& nickStart : colorPrefixEndingIndex) {
            if (nicknameTable.find(team.substr(nickStart)) != nicknameTable.end()) {
                found = true;
                break;
            }
        }

        if (found) {
            cout << "Yes\n";
        }
        else {
            cout << "No\n";
        }
    }

    return 0;
}
