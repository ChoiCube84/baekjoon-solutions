#include <bits/stdc++.h>

#ifndef __BINARY_SEARCH_TREE_HPP__
#define __BINARY_SEARCH_TREE_HPP__

#include <stack>
#include <string>
#include <sstream>
#include <vector>

template <typename T>
class BinarySearchTree {
private:
    struct Node {
        Node* left;
        Node* right;
        T value;

        Node() : left(nullptr), right(nullptr), value(static_cast<T>(0)) {}
        explicit Node(const T& value) : left(nullptr), right(nullptr), value(value) {}
    };

    Node* head;

    Node* construct(const std::vector<T>& postOrder, const std::vector<T>& inOrder, size_t start, size_t end) {
        if (start > end) {
            return nullptr;
        }

        size_t leftEnd = end;
        Node* curr = new Node(postOrder[end]);

        if (start == end) {
            return curr;
        }

        while (start < leftEnd && postOrder[leftEnd] >= curr->value) {
            leftEnd--;
        }

        if (postOrder[leftEnd] < curr->value) {
            curr->left = construct(postOrder, inOrder, start, leftEnd);
            curr->right = construct(postOrder, inOrder, leftEnd + 1, end - 1);
        }
        else {
            curr->left = nullptr;
            curr->right = construct(postOrder, inOrder, leftEnd, end - 1);
        }

        return curr;
    }

    void preOrder(Node *currentNode, std::vector<T> &result) {
        result.emplace_back(currentNode->value);

        if (currentNode->left != nullptr) {
            preOrder(currentNode->left, result);
        }

        if (currentNode->right != nullptr) {
            preOrder(currentNode->right, result);
        }
    }

    void inOrder(Node *currentNode, std::vector<T> &result) {
        if (currentNode->left != nullptr) {
            inOrder(currentNode->left, result);
        }

        result.emplace_back(currentNode->value);

        if (currentNode->right != nullptr) {
            inOrder(currentNode->right, result);
        }
    }

    void postOrder(Node *currentNode, std::vector<T> &result) {
        if (currentNode->left != nullptr) {
            postOrder(currentNode->left, result);
        }

        if (currentNode->right != nullptr) {
            postOrder(currentNode->right, result);
        }

        result.emplace_back(currentNode->value);
    }

public:
    BinarySearchTree() : head(nullptr) {}

    BinarySearchTree(const std::vector<T>& postOrder, const std::vector<T>& inOrder) : head(nullptr) {
        if (postOrder.size() != inOrder.size() || postOrder.empty()) {
            return;
        }
        else if (postOrder.size() == 1) {
            head = new Node(postOrder[0]);
            return;
        }

        size_t leftEnd = postOrder.size() - 1;
        head = new Node(postOrder.back());

        while (leftEnd > 0 && postOrder[leftEnd] >= head->value) {
            leftEnd--;
        }

        if (postOrder[leftEnd] < head->value) {
            head->left = construct(postOrder, inOrder, 0, leftEnd);
            head->right = construct(postOrder, inOrder, leftEnd + 1, postOrder.size() - 2);
        }
        else {
            head->left = nullptr;
            head->right = construct(postOrder, inOrder, leftEnd, postOrder.size() - 2);
        }
    }

    ~BinarySearchTree() {
        if (head != nullptr) {
            std::stack<Node*> s;
            s.push(head);

            while (!s.empty()) {
                Node* currentNode = s.top();
                s.pop();

                if (currentNode->left != nullptr) {
                    s.push(currentNode->left);
                }
                if (currentNode->right != nullptr) {
                    s.push(currentNode->right);
                }

                delete currentNode;
            }
        }
    }

    void insert(const T& value) {
        if (head == nullptr) {
            head = new Node(value);
        }
        else {
            Node* currentNode = head;
            Node* parentNode = nullptr;

            while (currentNode != nullptr) {
                parentNode = currentNode;
                if (value < currentNode->value) {
                    currentNode = currentNode->left;
                }
                else {
                    currentNode = currentNode->right;
                }
            }

            if (value < parentNode->value) {
                parentNode->left = new Node(value);
            }
            else {
                parentNode->right = new Node(value);
            }
        }
    }

    void remove(const T& value) {
        // TODO: Implement this later
    }

    bool search(const T& value) {
        Node* currentNode = head;

        while (currentNode != nullptr) {
            if (value < currentNode->value) {
                currentNode = currentNode->left;
            }
            else if (value > currentNode->value) {
                currentNode = currentNode->right;
            }
            else {
                return true;
            }
        }

        return false;
    }

    std::vector<T> preOrder() {
        std::vector<T> result;

        if (head != nullptr) {
            preOrder(head, result);
        }

        return result;
    }

    std::vector<T> inOrder() {
        std::vector<T> result;

        if (head != nullptr) {
            inOrder(head, result);
        }

        return result;
    }

    std::vector<T> postOrder() {
        std::vector<T> result;

        if (head != nullptr) {
            postOrder(head, result);
        }

        return result;
    }
};

#endif // !__BINARY_SEARCH_TREE_HPP__

using namespace std;
using ll = long long;
using ull = unsigned long long;
using pll = pair<ll, ll>;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;

    vector<pair<int, int>> inOrder(n);
    vector<int> indicies(n+1);
    vector<pair<int, int>> postOrder(n);

    for (int i=0; i<n; i++) {
        int elem;
        cin >> elem;

        inOrder[i] = make_pair(i, elem);
        indicies[elem] = i;
    }

    for (int i=0; i<n; i++) {
        int elem;
        cin >> elem;

        postOrder[i] = make_pair(indicies[elem], elem);
    }

    BinarySearchTree<pair<int, int>> bst(postOrder, inOrder);

    for (auto& elem : bst.preOrder()) {
        cout << elem.second << " ";
    }

    return 0;
}
