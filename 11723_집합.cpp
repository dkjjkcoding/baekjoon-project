#include<iostream>

#pragma warning(disable:4996)
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n, x, BIT = 0;
	string op;

	cin >> n;
	while (n--) {
		cin >> op;
		if (op == "all") BIT = (1 << 21) - 1;
		else if (op == "empty") BIT = 0;
		else {
			cin >> x;
			if (op == "add") BIT |= (1 << x);
			else if (op == "remove") BIT &= ~(1 << x);
			else if (op == "check") {
				if (BIT & (1 << x)) cout << 1 << '\n';
				else cout << 0 << '\n';
			}
			else if (op == "toggle") BIT ^= (1 << x);
			else{
				cout << "ERROR: The operator cannot be performed\n";
				exit(1);
			}
		}
	}

	return 0;
}