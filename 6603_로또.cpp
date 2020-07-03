#include<iostream>
#include<algorithm>

#define MAX 13
#define COUNT 6
using namespace std;

int arr[MAX], check[MAX];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int k;
	while (1) {
		cin >> k;
		if (!k) break;
		for (int i = 0;i < k;i++) {
			if (i < COUNT) check[i] = 0;
			else check[i] = 1;
			cin >> arr[i];
		}
		do {
			for (int i = 0;i < k;i++) {
				if (check[i]) continue;
				cout << arr[i] << ' ';
			}
			cout << '\n';
		} while (next_permutation(check, check + k));
		cout << '\n';
	}

	return 0;
}