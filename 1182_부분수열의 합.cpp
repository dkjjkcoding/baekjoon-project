#include <iostream>
#include<algorithm>

#define MAX 20
using namespace std;

int a[MAX];
int use[MAX];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n, s;
	int sum, num = 2, cnt = 0;

	cin >> n >> s;
	for (int i = 0;i < n;i++)
		cin >> a[i];

	for (int i = 0;i < n;i++) {
		if (a[i] == s)
			cnt++;
	}

	while (num <= n) {
		for (int i = 0;i < n;i++) {
			if (i >= n - num)
				use[i] = 1;
			else
				use[i] = 0;
		}
		do {
			sum = 0;
			for (int i = 0;i < n;i++)
				if (use[i] == 1)
					sum += a[i];
			if (sum == s)
				cnt++;
		} while (next_permutation(use, use + n));
		num++;
	}

	cout << cnt;

	return 0;
}