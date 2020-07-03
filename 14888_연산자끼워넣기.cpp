#include<iostream>
#include<algorithm>
using namespace std;

int a[100];
int op[99]; // +(0) -(1) *(2) /(3)

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n, temp, cnt = 0, sum, tempop;
	int minv = 1000000000, maxv = -1000000000;

	cin >> n;
	for (int i = 0;i < n;i++)
		cin >> a[i];
	for (int i = 0;i <= 4;i++) {
		cin >> temp;
		for (int j = 0;j < temp;j++)
			op[cnt++] = i;
	}

	do {
		sum = a[0];
		for (int i = 0;i < n;i++) {
			temp = a[i + 1];
			tempop = op[i];
			if (tempop == 0) sum += temp;
			else if (tempop == 1) sum -= temp;
			else if (tempop == 2) sum *= temp;
			else sum /= temp;
		}
		minv = min(minv, sum);
		maxv = max(maxv, sum);
	} while (next_permutation(op, op + n - 1));
	cout << maxv << '\n' << minv;

	return 0;
}