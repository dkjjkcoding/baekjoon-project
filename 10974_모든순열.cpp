#include<iostream>
#include<algorithm>
using namespace std;

int a[8];

int main() {
	int n;
	cin >> n;
	for (int i = 0;i < n;i++)
		cin >> a[i];
	do {
		for (int i = 0;i < n;i++)
			cout << a[i] << ' ';
		cout << '\n';
	} while (next_permutation(a, a + n));

	return 0;
}