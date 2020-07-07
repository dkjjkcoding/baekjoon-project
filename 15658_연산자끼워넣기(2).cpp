#include<iostream>

#define MAX 11
#pragma warning(disable:4996)
using namespace std;

int n, minv = 1000000000, maxv = -1000000000;
int a[MAX];
int Plus, Minus, Multiple, Divide;

void dfs(int p, int mi, int mul, int d, int sum, int a_idx) {
	if (a_idx == n) {
		if (sum < minv) minv = sum;
		if (sum > maxv) maxv = sum;
		return;
	}

	if (p < Plus) dfs(p + 1, mi, mul, d, sum + a[a_idx], a_idx + 1);
	if (mi < Minus) dfs(p, mi + 1, mul, d, sum - a[a_idx], a_idx + 1);
	if (mul < Multiple) dfs(p, mi, mul + 1, d, sum * a[a_idx], a_idx + 1);
	if (d < Divide) dfs(p, mi, mul, d + 1, sum / a[a_idx], a_idx + 1);
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n;
	for (int i = 0;i < n;i++)
		cin >> a[i];
	cin >> Plus >> Minus >> Multiple >> Divide;

	dfs(0, 0, 0, 0, a[0], 1);

	cout << maxv << '\n' << minv;

	return 0;
}