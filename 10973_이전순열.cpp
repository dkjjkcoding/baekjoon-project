#include<iostream>
#include<algorithm>
using namespace std;

int a[10000];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;
	for (int i = 0;i < n;i++)
		cin >> a[i];

	if (prev_permutation(a, a + n))
		for (int i = 0;i < n;i++)
			cout << a[i] << ' ';
	else
		cout << -1;

	return 0;
}