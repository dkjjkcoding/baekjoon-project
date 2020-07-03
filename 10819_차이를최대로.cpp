#include<iostream>
#include<algorithm>
using namespace std;

int n;
int arr[8];

int getSum(int* arr) {
	int sum = 0;
	for (int i = 0;i < n - 1;i++)
		sum += abs(arr[i] - arr[i + 1]);
	return sum;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int temp, maxv;
	cin >> n;
	for (int i = 0;i < n;i++)
		cin >> arr[i];

	sort(arr, arr + n);
	maxv = getSum(arr);
	while (next_permutation(arr, arr + n)) {
		temp = getSum(arr);
		maxv = max(maxv, temp);
	}
	cout << maxv;

	return 0;
}