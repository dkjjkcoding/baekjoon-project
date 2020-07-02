#include<iostream>
#include<algorithm>

#define N 9
#define HEIGHTS 100
#pragma warning(disable:4996)
using namespace std;

int getSum(int* arr) {
	int sum = 0;
	for (int i = 0;i < N;i++) {
		sum += arr[i];
	}
	return sum;
}

void solution(int* arr) {
	int sum = getSum(arr);

	for (int i = 0;i < N - 1;i++) {
		for (int j = i + 1;j < N;j++) {
			if (sum - arr[i] - arr[j] == HEIGHTS) {
				arr[i] = -1;
				arr[j] = -1;
				return;
			}
		}
	}
}

int main() {

	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int arr[N];
	for (int i = 0;i < N;i++) {
		cin >> arr[i];
	}

	solution(arr);

	sort(arr, arr + N);

	for (int i = 2;i < N;i++) {
		cout << arr[i] << '\n';
	}

	return 0;
}