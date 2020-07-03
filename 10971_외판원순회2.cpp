#include<iostream>
#include<algorithm>

#define MAX 10
using namespace std;

int arr[MAX];
int w[MAX][MAX];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n, sum, temp, minv = 4000000;
	bool isZero;

	cin >> n;
	for (int i = 0;i < n;i++) {
		arr[i] = i;
		for (int j = 0;j < n;j++)
			cin >> w[i][j];
	}
	do {
		isZero = false;
		sum = 0;
		for (int i = 0;!isZero && i < n - 1;i++) {
			temp = w[arr[i]][arr[i + 1]];
			if (temp == 0)
				isZero = true;
			sum += temp;
		}
		if (isZero) continue;
		temp = w[arr[n - 1]][arr[0]];
		if (temp == 0) continue;
		sum += temp;
		minv = min(minv, sum);
	} while (next_permutation(arr, arr + n));
	cout << minv;
	
	return 0;
}