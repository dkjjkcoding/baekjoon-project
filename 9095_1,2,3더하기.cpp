#include<iostream>

#pragma warning(disable:4996)
using namespace std;

int dp(int n) {
	if (n <= 0) return 0;
	if (n == 1) return 1;
	if (n == 2) return 2;
	if (n == 3) return 4;
	return dp(n - 1) + dp(n - 2) + dp(n - 3);
}

int main() {

	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int t, n;

	cin >> t;
	while (t--) {
		cin >> n;
		cout << dp(n) << '\n';
	}

	return 0;
}