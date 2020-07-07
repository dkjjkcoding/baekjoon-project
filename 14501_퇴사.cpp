#include<iostream>

#define MAX 15
using namespace std;

int n, result;
int t[MAX];
int p[MAX];

void dfs(int i, int sum) {
	if (i == n) {
		if (sum > result) result = sum;
		return;
	}

	if (i + 1 <= n) dfs(i + 1, sum);
	if (i + t[i] <= n) dfs(i + t[i], sum + p[i]);
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n;
	for (int i = 0;i < n;i++)
		cin >> t[i] >> p[i];

	dfs(0, 0);
	cout << result;

	return 0;
}