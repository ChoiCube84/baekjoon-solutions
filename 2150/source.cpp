#include <bits/stdc++.h>

using namespace std;

bool alreadyInGroup[10001] = { 0, };

int orderOfFound[10001] = { 0, };
int highestReachable[10001] = { 0, };
int numberOfGroup[10001] = { 0, };

int tempOrder = 1;
int numberOfSCCs = 0;

vector<vector<int>> graph(10001);
stack<int> s;

vector<priority_queue<int, vector<int>, greater<int>>> SCCs(10001);

struct cmp {
	bool operator()(const priority_queue<int, vector<int>, greater<int>>& q1, const priority_queue<int, vector<int>, greater<int>>& q2) {
		return q1.top() > q2.top();
	}
};

priority_queue< priority_queue<int, vector<int>, greater<int>>, vector<priority_queue<int, vector<int>, greater<int>>>, cmp> orderedSCCs;

void tarjan(int nodeToCheck);

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int V, E, A, B;
	cin >> V >> E;

	for (int i = 0; i < E; i++) {
		cin >> A >> B;
		graph[A].emplace_back(B);
	}

	for (int i = 1; i <= V; i++) {
		if (orderOfFound[i] == 0) {
			tarjan(i);
		}
	}

	cout << numberOfSCCs << "\n";

	for (int i = 0; i < numberOfSCCs; i++) {
		orderedSCCs.push(SCCs[i]);
	}

	for (int i = 0; i < numberOfSCCs; i++) {
		auto currentSCC = orderedSCCs.top();
		while (!currentSCC.empty()) {
			cout << currentSCC.top() << " ";
			currentSCC.pop();
		}
		cout << -1 << "\n";
		orderedSCCs.pop();
	}

	return 0;
}

void tarjan(int nodeToCheck) {
	orderOfFound[nodeToCheck] = highestReachable[nodeToCheck] = tempOrder;
	tempOrder++;

	s.push(nodeToCheck);
	
	for (auto i : graph[nodeToCheck]) {
		if (orderOfFound[i] == 0) {
			tarjan(i);
			highestReachable[nodeToCheck] = min(highestReachable[nodeToCheck], highestReachable[i]);
		}
		else if (alreadyInGroup[i] == false) {
			highestReachable[nodeToCheck] = min(highestReachable[nodeToCheck], orderOfFound[i]);
		}
	}
	
	if (highestReachable[nodeToCheck] == orderOfFound[nodeToCheck]) {
		while (s.top() != nodeToCheck) {
			int currentNode = s.top();
			s.pop();

			alreadyInGroup[currentNode] = true;
			SCCs[numberOfSCCs].push(currentNode);
			numberOfGroup[currentNode] = numberOfSCCs;
		}

		int highestInSCC = s.top();
		s.pop();
		
		alreadyInGroup[highestInSCC] = 1;
		SCCs[numberOfSCCs].push(highestInSCC);
		numberOfGroup[highestInSCC] = numberOfSCCs;
		
		numberOfSCCs++;
	}
}
