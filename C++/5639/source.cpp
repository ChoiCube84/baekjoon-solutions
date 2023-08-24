#include <bits/stdc++.h>

using namespace std;

template <typename T>
class BinarySearchTree {
private:
	struct Node {
		Node* left;
		Node* right;
		T value;

		Node(const T& value) : left(nullptr), right(nullptr), value(value) {}
	};

	Node* head;

	void preOrder(Node* currentNode, std::ostringstream& oss, const char& separator) {
		oss << currentNode->value << separator;

		if (currentNode->left != nullptr) {
			preOrder(currentNode->left, oss, separator);
		}

		if (currentNode->right != nullptr) {
			preOrder(currentNode->right, oss, separator);
		}
	}

	void inOrder(Node* currentNode, std::ostringstream& oss, const char& separator) {
		if (currentNode->left != nullptr) {
			inOrder(currentNode->left, oss, separator);
		}

		oss << currentNode->value << separator;

		if (currentNode->right != nullptr) {
			inOrder(currentNode->right, oss, separator);
		}
	}

	void postOrder(Node* currentNode, std::ostringstream& oss, const char& separator) {
		if (currentNode->left != nullptr) {
			postOrder(currentNode->left, oss, separator);
		}

		if (currentNode->right != nullptr) {
			postOrder(currentNode->right, oss, separator);
		}

		oss << currentNode->value << separator;
	}

public:
	BinarySearchTree() : head(nullptr) {}

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

	std::string preOrder(const char& separator = ' ') {
		std::ostringstream oss;

		if (head != nullptr) {
			preOrder(head, oss, separator);
		}

		std::string result = std::move(oss).str();
		if (!result.empty()) {
			result.pop_back();
		}
		return result;
	}

	std::string inOrder(const char& separator = ' ') {
		std::ostringstream oss;

		if (head != nullptr) {
			inOrder(head, oss, separator);
		}

		std::string result = std::move(oss).str();
		if (!result.empty()) {
			result.pop_back();
		}
		return result;
	}

	std::string postOrder(const char& separator = ' ') {
		std::ostringstream oss;

		if (head != nullptr) {
			postOrder(head, oss, separator);
		}

		std::string result = std::move(oss).str();
		if (!result.empty()) {
			result.pop_back();
		}
		return result;
	}
};

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	BinarySearchTree<int> bst;

	int number;
	while (cin >> number) {
		bst.insert(number);
	}

	cout << bst.postOrder('\n');

	return 0;
}
