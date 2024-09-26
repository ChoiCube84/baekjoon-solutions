#include <bits/stdc++.h>
#define MAX_SIZE 20002

using namespace std;

bool alreadyInGroup[MAX_SIZE] = { 0, };
int result[MAX_SIZE] = { -1, };

int orderOfFound[MAX_SIZE] = { 0, };
int highestReachable[MAX_SIZE] = { 0, };
int numberOfGroup[MAX_SIZE] = { 0, };

int tempOrder = 1;
int numberOfSCCs = 0;

vector<vector<int>> graph(MAX_SIZE);
stack<int> s;

vector<vector<int>> SCCs(MAX_SIZE);

int logicToVertex(int logic);
int vertexToLogic(int vertex);

void tarjan(int nodeToCheck);

bool checkSatisfiability(int N);
void caculateResult(int N);

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int N, M, A, B;
	cin >> N >> M;

	for (int i = 0; i < M; i++) {
		cin >> A >> B;

		graph[logicToVertex((-1) * A)].emplace_back(logicToVertex(B));
		graph[logicToVertex((-1) * B)].emplace_back(logicToVertex(A));
	}

	for (int i = 1; i <= 2 * N; i++) {
		if (orderOfFound[i] == 0) {
			tarjan(i);
		}
	}

	bool satisfiability = checkSatisfiability(N);
	if (satisfiability == true) {
		cout << 1 << "\n";
		caculateResult(N);
		for (int i = 1; i <= N; i++) {
			cout << result[i] << " ";
		}
	}
	else {
		cout << 0;
	}

	return 0;
}

//            1  2  3  4  5
// original:  1  3  5  7  9
//			 -1 -2 -3 -4 -5
// inversed:  2  4  6  8 10

int logicToVertex(int logic) {
	if (logic < 0) {
		return logic * (-2);
	}
	else {
		return 2 * logic - 1;
	}
}

int vertexToLogic(int vertex) {
	if (vertex % 2 == 0) {
		return (-1) * vertex / 2;
	}
	else {
		return (vertex + 1) / 2;
	}
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
			SCCs[numberOfSCCs].emplace_back(currentNode);
			numberOfGroup[currentNode] = numberOfSCCs;
		}

		int highestInSCC = s.top();
		s.pop();

		alreadyInGroup[highestInSCC] = 1;
		SCCs[numberOfSCCs].emplace_back(highestInSCC);
		numberOfGroup[highestInSCC] = numberOfSCCs;

		numberOfSCCs++;
	}
}

bool checkSatisfiability(int N) {
	for (int i = 1; i <= N; i++) {
		if (numberOfGroup[logicToVertex(i)] == numberOfGroup[logicToVertex(-i)]) {
			return false;
		}
	}
	return true;
}

void caculateResult(int N) {
	for (int i = 1; i <= N; i++) {
		result[i] = -1;
	}

	for (int i = 1; i <= N; i++) {
		result[i] = numberOfGroup[logicToVertex(i)] < numberOfGroup[logicToVertex(-i)];
	}
}
