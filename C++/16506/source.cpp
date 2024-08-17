#include <bits/extc++.h>

using namespace __gnu_pbds;
using namespace std;

using ll = long long int;
using ull = unsigned long long int;

using ld = long double;

using pll = pair<ll, ll>;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	ll N;
	cin >> N;

	while (N--) {
		string opcode;
		unsigned D, A, B;

		cin >> opcode >> D >> A >> B;

		if (opcode == "ADD") {
			cout << "00000";
			B <<= 1;
		}
		else if (opcode == "ADDC") {
			cout << "00001";
		}
		else if (opcode == "SUB") {
			cout << "00010";
			B <<= 1;
		}
		else if (opcode == "SUBC") {
			cout << "00011";
		}
		else if (opcode == "MOV") {
			cout << "00100";
			B <<= 1;
		}
		else if (opcode == "MOVC") {
			cout << "00101";
		}
		else if (opcode == "AND") {
			cout << "00110";
			B <<= 1;
		}
		else if (opcode == "ANDC") {
			cout << "00111";
		}
		else if (opcode == "OR") {
			cout << "01000";
			B <<= 1;
		}
		else if (opcode == "ORC") {
			cout << "01001";
		}
		else if (opcode == "NOT") {
			cout << "01010";
			B <<= 1;
		}
		else if (opcode == "MULT") {
			cout << "01100";
			B <<= 1;
		}
		else if (opcode == "MULTC") {
			cout << "01101";
		}
		else if (opcode == "LSFTL") {
			cout << "01110";
			B <<= 1;
		}
		else if (opcode == "LSFTLC") {
			cout << "01111";
		}
		else if (opcode == "LSFTR") {
			cout << "10000";
			B <<= 1;
		}
		else if (opcode == "LSFTRC") {
			cout << "10001";
		}
		else if (opcode == "ASFTR") {
			cout << "10010";
			B <<= 1;
		}
		else if (opcode == "ASFTRC") {
			cout << "10011";
		}
		else if (opcode == "RL") {
			cout << "10100";
			B <<= 1;
		}
		else if (opcode == "RLC") {
			cout << "10101";
		}
		else if (opcode == "RR") {
			cout << "10110";
			B <<= 1;
		}
		else if (opcode == "RRC") {
			cout << "10111";
		}

		cout << 0;

		bitset<3> rD(D);
		cout << rD;

		bitset<3> rA(A);
		if (opcode == "MOV" || opcode == "MOVC" || opcode == "NOT") {
			cout << "000";
		}
		else {
			cout << rA;
		}

		bitset<4> rB(B);
		cout << rB;

		cout << '\n';
	}

	return 0;
}